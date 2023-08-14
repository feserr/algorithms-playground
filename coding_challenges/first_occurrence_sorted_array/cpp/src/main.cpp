/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "NumSearch.h"

struct TestInput {
  std::vector<int> input;
  std::vector<std::pair<int, int>> solution;
};

std::vector<TestInput> ReadInput(const std::string& file_path) {
  std::vector<TestInput> input_vector;

  std::ifstream infile(file_path);
  std::string numbers;
  while (getline(infile, numbers)) {
    TestInput test_input;

    std::istringstream is(numbers);
    int number;
    while (is >> number) {
      test_input.input.emplace_back(static_cast<int>(number));
    }

    int num_solutions = 0;
    infile >> num_solutions;

    test_input.solution = std::vector<std::pair<int, int>>(num_solutions);

    for (int index = 0; index < num_solutions; ++index) {
      int search_number, solution;
      infile >> search_number >> solution;
      test_input.solution[index] = {search_number, solution};
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
    NumSearch numSearch;

    std::cout << "Case #" << case_index;

    if (any_of(test_input.solution.begin(), test_input.solution.end(),
               [&numSearch, &test_input](const auto& solution) {
                 return numSearch.Search(test_input.input, solution.first) != solution.second;
               })) {
      std::cout << " FAIL" << std::endl;
      return 1;
    }

    std::cout << " OK" << std::endl;

    ++case_index;
  }

  return 0;
}
