/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

int MinDeletions(std::string s) {
  std::unordered_map<char, int> letters;

  for (const auto& letter : s) {
    ++letters[letter];
  }

  std::priority_queue<int, std::vector<int>, std::greater<int>> frequency;
  for (const auto& letter_freq : letters) {
    frequency.emplace(letter_freq.second);
  }

  int removed = 0;
  std::stack<std::pair<int, int>> slots_left;

  int top = frequency.top();
  if (top - 1 > 0) slots_left.emplace(top - 1, top - 1);
  int prev = frequency.top();
  frequency.pop();

  while (!frequency.empty()) {
    int freq = frequency.top();
    frequency.pop();

    if (freq != prev) {
      if (freq - 1 - prev > 0) slots_left.emplace(freq - 1, freq - 1 - prev);
    } else {
      if (slots_left.empty()) {
        removed += freq;
      } else {
        auto slot = slots_left.top();

        removed += freq - slot.first;
        --slots_left.top().first;
        --slots_left.top().second;

        if (slots_left.top().second == 0) {
          slots_left.pop();
        }
      }
    }

    prev = freq;
  }

  return removed;
}

int main(int argc, char** argv) {
  int res = MinDeletions(
      "jbddhjemmnhaflahionjoddojoliimdcailihfdleahgbafnknblkheeicoonffenhhmgfhg"
      "mnjk");

  std::cout << res << std::endl;

  return 0;
}
