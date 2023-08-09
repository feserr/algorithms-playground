/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "lru/cpp/src/lru.h"

struct TestInput {
  std::vector<std::string> input;
  std::vector<std::string> solution;
};

std::vector<TestInput> ReadInput(const std::string& file_path) {
  std::vector<TestInput> input_vector;

  std::ifstream infile(file_path);
  int num_urls = 0;
  while (infile >> num_urls) {
    infile >> num_urls;

    TestInput test_input;
    test_input.input = std::vector<std::string>(num_urls);

    for (int index = 0; index < num_urls; ++index) {
      std::string url = "";
      infile >> url;
      test_input.input[index] = url;
    }

    int num_urls_sol = 0;
    infile >> num_urls_sol;

    test_input.solution = std::vector<std::string>(num_urls_sol);

    for (int index = 0; index < num_urls_sol; ++index) {
      std::string url = "";
      infile >> url;
      test_input.solution[index] = url;
    }

    input_vector.emplace_back(test_input);
  }

  return input_vector;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Wrong arguments" << std::endl;
    return 1;
  }

  std::vector<TestInput> test_inputs = ReadInput(argv[1]);

  int case_index = 1;
  for (const auto& test_input : test_inputs) {
    LRU<std::string, int> history_lru;

    for (const auto& input : test_input.input) {
      history_lru.put(input, 0);
    }

    std::cout << "Case #" << case_index;

    auto solution = history_lru.getAll();

    if (solution.size() != test_input.solution.size()) {
      std::cout << " FAIL" << std::endl;
      return 1;
    }

    for (auto index = 0; index < solution.size(); ++index) {
      if (solution[index].first != test_input.solution[index]) {
        std::cout << " FAIL" << std::endl;
        return 1;
      }
    }

    std::cout << " OK" << std::endl;

    ++case_index;
  }

  return 0;
}
