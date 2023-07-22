/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <stdio.h>

void PrintData(const int* data, const int size) {
  for (int it_data = 0; it_data < size; ++it_data) {
    if (it_data == size - 1) {
      printf("%d\n", data[it_data]);
    } else {
      printf("%d ", data[it_data]);
    }
  }
}

int main(int argc, char** argv) {
  int data[] = {31, 21, 45, 10, 50, 51, 49};
  const int size = sizeof(data) / sizeof(int);

  PrintData(data, size);

  for (int it_array = 1; it_array < size; ++it_array) {
    int key = data[it_array];
    int sort_it = it_array - 1;
    while (sort_it >= 0 && data[sort_it] > key) {
      data[sort_it + 1] = data[sort_it];
      --sort_it;
    }
    data[sort_it + 1] = key;
  }

  PrintData(data, size);

  return 0;
}
