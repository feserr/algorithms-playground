/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#ifndef NUM_SEARCH_H_
#define NUM_SEARCH_H_

#include <vector>
class NumSearch {
 public:
  /**
   * @brief Search the number using binary search.
   *
   * O(log n) for finding the number
   * O(m) been m the number of occurrences
   *
   * Worst case: O(m/2) when the whole array is the number to search.
   *
   * @param numbers The vector of numbers.
   * @param num_to_search The number to search
   * @return int The position of the number if found, otherwise -1.
   */
  static int Search(const std::vector<int>& numbers, const int num_to_search);
};

#endif  // NUM_SEARCH_H_
