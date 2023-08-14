/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Bank.h"

struct TestInput {
  std::vector<std::string> input;
  std::vector<std::string> solution;
};

std::vector<TestInput> ReadInput(const std::string& file_path) {
  std::vector<TestInput> input_vector;

  std::ifstream infile(file_path);
  int num_transactions;
  while (infile >> num_transactions) {
    TestInput test_input;

    test_input.input = std::vector<std::string>(num_transactions);
    for (int index = 0; index < num_transactions; ++index) {
      std::string transaction;
      getline(infile, transaction);
      test_input.input[index] = transaction;
    }

    int num_solutions = 0;
    infile >> num_solutions;

    test_input.solution = std::vector<std::string>(num_solutions);
    for (int index = 0; index < num_solutions; ++index) {
      std::string fraudolent_transaction;
      getline(infile, fraudolent_transaction);
      test_input.solution[index] = fraudolent_transaction;
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
    Bank bank;

    std::cout << "Case #" << case_index;

    std::vector<std::string> fraudolent_transactions;
    for (const auto& transaction : test_input.input) {
      auto fraudolent_at_transaction = bank.AddTransaction(transaction);
      std::copy(fraudolent_at_transaction.begin(), fraudolent_at_transaction.end(),
                std::back_inserter(fraudolent_transactions));
    }

    if (!equal(test_input.solution.begin(), test_input.solution.end(),
               fraudolent_transactions.begin())) {
      std::cout << " FAIL" << std::endl;
      return 1;
    }

    std::cout << " OK" << std::endl;

    ++case_index;
  }

  return 0;
}
