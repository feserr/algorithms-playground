/*
 * Copyright 2021 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

int Rec(const vector<string>& arr, int pos, const unordered_set<char>& word) {
  if (pos >= arr.size()) {
    return 0;
  } else if (pos == arr.size() - 1) {
    string actual = arr[pos];
    unordered_set<char> tmp = word;
    for (const auto& letter : actual) {
      if (tmp.find(letter) != tmp.end()) break;
      tmp.emplace(letter);
    }

    if (tmp.size() == word.size() + actual.size())
      return tmp.size();
    else {
      tmp = {};
      for (const auto& letter : actual) {
        if (tmp.find(letter) != tmp.end()) break;
        tmp.emplace(letter);
      }

      size_t t_size = tmp.size() == actual.size() ? actual.size() : 0;

      return max(word.size(), t_size);
    }
  }

  int length = 0;
  string actual = arr[pos];

  unordered_set<char> tmp = word;
  for (const auto& letter : actual) {
    if (tmp.find(letter) != tmp.end()) break;
    tmp.emplace(letter);
  }
  if (tmp.size() == word.size() + actual.size()) {
    length = Rec(arr, pos + 1, tmp);
  }

  return max(length, Rec(arr, pos + 1, word));
}

int MaxLength(const vector<string>& arr) { return Rec(arr, 0, {}); }

int main(int argc, char** argv) {
  int res = MaxLength({"aa", "bb"});

  cout << res << endl;

  return 0;
}