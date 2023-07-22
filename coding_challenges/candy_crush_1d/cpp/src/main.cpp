/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "CandyCrush1D.h"

using namespace std;

struct TestInput {
  string input;
  string solution;
};

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  vector<TestInput> test_inputs;

  std::ifstream infile(argv[1]);
  string input;
  string solution;
  while (infile >> input >> solution) {
    test_inputs.emplace_back(input, solution != "-" ? solution : "");
  }

  int case_index = 1;
  for (const auto& test_input : test_inputs) {
    string remain_candies = CandyCrash1D::GreedyCrush(test_input.input);
    cout << "Case #" << case_index;

    if (remain_candies != test_input.solution) {
      cout << " FAIL" << endl;
      cerr << "Wrong answer:\n\tExpected '" << test_input.solution << "'\n\tOutput: '"
           << remain_candies << "'" << endl;
      return 1;
    }

    cout << " OK" << endl;

    ++case_index;
  }

  return 0;
}
