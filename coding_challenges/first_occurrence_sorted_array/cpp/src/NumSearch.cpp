/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include "NumSearch.h"

int NumSearch::Search(const std::vector<int>& numbers,
                      const int num_to_search) {
  int start = 0;
  int end = numbers.size() - 1;

  while (start <= end) {
    int middle = (start + end) / 2;
    int num = numbers[middle];

    if (num == num_to_search) {
      while (middle >= 0 && numbers[middle] == num_to_search) {
        --middle;
      }

      return middle + 1;
    } else if (num_to_search > num) {
      start = middle + 1;
    } else {
      end = middle - 1;
    }
  }

  return -1;
}
