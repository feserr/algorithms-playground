/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "CandyCrush1D.h"

struct TestInput {
  std::string input;
  std::string solution;
};

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  std::vector<TestInput> test_inputs;

  std::ifstream infile(argv[1]);
  std::string input;
  std::string solution;
  while (infile >> input >> solution) {
    test_inputs.emplace_back(input, solution != "-" ? solution : "");
  }

  int case_index = 1;
  for (const auto& test_input : test_inputs) {
    std::string remain_candies = CandyCrash1D::GreedyCrush(test_input.input);
    std::cout << "Case #" << case_index;

    if (remain_candies != test_input.solution) {
      std::cout << " FAIL" << std::endl;
      std::cerr << "Wrong answer:\n\tExpected '" << test_input.solution << "'\n\tOutput: '"
                << remain_candies << "'" << std::endl;
      return 1;
    }

    std::cout << " OK" << std::endl;

    ++case_index;
  }

  return 0;
}
