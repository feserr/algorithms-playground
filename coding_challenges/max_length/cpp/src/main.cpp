/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

int Rec(const std::vector<std::string>& arr, int pos,
        const std::unordered_set<char>& word) {
  if (pos >= arr.size()) {
    return 0;
  } else if (pos == arr.size() - 1) {
    std::string actual = arr[pos];
    std::unordered_set<char> tmp = word;
    for (const auto& letter : actual) {
      if (tmp.find(letter) != tmp.end()) break;
      tmp.emplace(letter);
    }

    if (tmp.size() == word.size() + actual.size()) return tmp.size();

    tmp = {};
    for (const auto& letter : actual) {
      if (tmp.find(letter) != tmp.end()) break;
      tmp.emplace(letter);
    }

    size_t t_size = tmp.size() == actual.size() ? actual.size() : 0;

    return std::max(word.size(), t_size);
  }

  int length = 0;
  std::string actual = arr[pos];

  std::unordered_set<char> tmp = word;
  for (const auto& letter : actual) {
    if (tmp.find(letter) != tmp.end()) break;
    tmp.emplace(letter);
  }
  if (tmp.size() == word.size() + actual.size()) {
    length = Rec(arr, pos + 1, tmp);
  }

  return std::max(length, Rec(arr, pos + 1, word));
}

int MaxLength(const std::vector<std::string>& arr) { return Rec(arr, 0, {}); }

int main(int argc, char** argv) {
  int res = MaxLength({"aa", "bb"});

  std::cout << res << std::endl;

  return 0;
}
