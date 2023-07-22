/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "lru/cpp/src/lru.h"

using namespace std;

struct TestInput {
  vector<string> input;
  vector<string> solution;
};

vector<TestInput> ReadInput(const string& file_path) {
  vector<TestInput> input_vector;

  std::ifstream infile(file_path);
  int num_urls = 0;
  while (infile >> num_urls) {
    infile >> num_urls;

    TestInput test_input;
    test_input.input = vector<string>(num_urls);

    for (int index = 0; index < num_urls; ++index) {
      string url = "";
      infile >> url;
      test_input.input[index] = url;
    }

    int num_urls_sol = 0;
    infile >> num_urls_sol;

    test_input.solution = vector<string>(num_urls_sol);

    for (int index = 0; index < num_urls_sol; ++index) {
      string url = "";
      infile >> url;
      test_input.solution[index] = url;
    }

    input_vector.emplace_back(test_input);
  }

  return input_vector;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    cerr << "Wrong arguments" << endl;
    return 1;
  }

  vector<TestInput> test_inputs = ReadInput(argv[1]);

  int case_index = 1;
  for (const auto& test_input : test_inputs) {
    LRU<string, int> history_lru;

    for (const auto& input : test_input.input) {
      history_lru.put(input, 0);
    }

    cout << "Case #" << case_index;

    auto solution = history_lru.getAll();

    if (solution.size() != test_input.solution.size()) {
      cout << " FAIL" << endl;
      return 1;
    }

    for (auto index = 0; index < solution.size(); ++index) {
      if (solution[index].first != test_input.solution[index]) {
        cout << " FAIL" << endl;
        return 1;
      }
    }

    cout << " OK" << endl;

    ++case_index;
  }

  return 0;
}
