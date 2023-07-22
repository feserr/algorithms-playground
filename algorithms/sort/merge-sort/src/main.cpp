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

void Merge(int* array, int left, int middle, int right) {
  // Calculate the size of the sub-arrays
  int left_size = middle - left + 1;
  int right_size = right - middle;

  // Create the sub-arrays
  int* left_array = new int[left_size];
  int* right_array = new int[right_size];

  // Copy the data to the sub-arrays
  for (int it = 0; it < left_size; ++it) {
    left_array[it] = array[left + it];
  }
  for (int it = 0; it < right_size; ++it) {
    right_array[it] = array[middle + 1 + it];
  }

  // Merge the sub-arrays
  int it_array = left;
  int it_left = 0;
  int it_right = 0;
  while (it_left < left_size && it_right < right_size) {
    if (left_array[it_left] < right_array[it_right]) {
      array[it_array] = left_array[it_left++];
    } else {
      array[it_array] = right_array[it_right++];
    }
    ++it_array;
  }

  // Copy the remaining data of the sub-arrays.
  while (it_left < left_size) {
    array[it_array++] = left_array[it_left++];
  }
  while (it_right < right_size) {
    array[it_array++] = right_array[it_right++];
  }

  delete[] left_array;
  delete[] right_array;
}

void MergeSort(int* array, int left, int right) {
  if (left < right) {
    int middle = (left + right) / 2;

    MergeSort(array, left, middle);
    MergeSort(array, middle + 1, right);

    Merge(array, left, middle, right);
  }
}

int main(int argc, char** argv) {
  int data[] = {38, 27, 43, 3, 9, 82, 10};
  const int size = sizeof(data) / sizeof(int);

  PrintData(data, size);

  MergeSort(data, 0, size - 1);

  PrintData(data, size);

  return 0;
}
