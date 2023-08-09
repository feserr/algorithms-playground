/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

const uint32_t kEnd = 10;

std::mutex mut;
std::condition_variable cond_var;
uint32_t num = 0;

/**
 * @brief Print from the value of "num" to "kEnd" only printing the even or
 * odd numbers.
 *
 * Must be used in two threads to not create a deadlock.
 *
 * @param even_odd false if even, true if odd.
 */
void PrintNumber(const bool even_odd) {
  while (num < kEnd) {
    std::unique_lock<std::mutex> mut_lock(mut);
    cond_var.wait(mut_lock, [even_odd] { return num % 2 == even_odd; });
    std::cout << num << " ";
    ++num;
    cond_var.notify_one();
  }
}

int main(int argc, char** argv) {
  std::thread even_thread(PrintNumber, 0);
  std::thread odd_thread(PrintNumber, 1);

  even_thread.join();
  odd_thread.join();

  std::cout << std::endl;

  return 0;
}
