/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <inttypes.h>
#include <stdio.h>
#include <algorithm>

void PrintData(const int* data, const int size) {
  for (int it_data = 0; it_data < size; ++it_data) {
    if (it_data == size - 1) {
      printf("%d\n", data[it_data]);
    } else {
      printf("%d ", data[it_data]);
    }
  }
}

int Partition(int* array, int low, int high) {
  int pivot = array[high];

  int lower = low - 1;
  for (int it = low; it < high; ++it) {
    if (array[it] < pivot) {
      std::swap(array[it], array[++lower]);
    }
  }
  std::swap(array[++lower], array[high]);

  return lower;
}

void QuickSort(int* array, int low, int high) {
  if (low < high) {
    int pivot = Partition(array, low, high);
    QuickSort(array, low, pivot - 1);
    QuickSort(array, pivot + 1, high);
  }
}

int main(int argc, char** argv) {
  int data[] = {10, 80, 30, 90, 40, 50, 70};
  const int size = sizeof(data) / sizeof(int);

  PrintData(data, size);

  QuickSort(data, 0, size - 1);

  PrintData(data, size);

  return 0;
}
