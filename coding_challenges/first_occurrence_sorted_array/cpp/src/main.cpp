/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "NumSearch.h"

using namespace std;

struct TestInput {
  vector<int> input;
  vector<pair<int, int>> solution;
};

vector<TestInput> ReadInput(const string& file_path) {
  vector<TestInput> input_vector;

  std::ifstream infile(file_path);
  string numbers;
  while (getline(infile, numbers)) {
    TestInput test_input;

    std::istringstream is(numbers);
    int number;
    while (is >> number) {
      test_input.input.emplace_back((int)number);
    }

    int num_solutions = 0;
    infile >> num_solutions;

    test_input.solution = vector<pair<int, int>>(num_solutions);

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
    cerr << "Wrong arguments" << endl;
    return 1;
  }

  vector<TestInput> test_inputs = ReadInput(argv[1]);

  int case_index = 1;
  for (const auto& test_input : test_inputs) {
    NumSearch numSearch;

    cout << "Case #" << case_index;

    if (any_of(test_input.solution.begin(), test_input.solution.end(),
               [&numSearch, &test_input](const auto& solution) {
                 return numSearch.Search(test_input.input, solution.first) !=
                        solution.second;
               })) {
      cout << " FAIL" << endl;
      return 1;
    }

    cout << " OK" << endl;

    ++case_index;
  }

  return 0;
}
