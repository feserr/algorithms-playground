/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Bank.h"

using namespace std;

struct TestInput {
  vector<string> input;
  vector<string> solution;
};

vector<TestInput> ReadInput(const string& file_path) {
  vector<TestInput> input_vector;

  std::ifstream infile(file_path);
  int num_transactions;
  while (infile >> num_transactions) {
    TestInput test_input;

    test_input.input = vector<string>(num_transactions);
    for (int index = 0; index < num_transactions; ++index) {
      string transaction;
      getline(infile, transaction);
      test_input.input[index] = transaction;
    }

    int num_solutions = 0;
    infile >> num_solutions;

    test_input.solution = vector<string>(num_solutions);
    for (int index = 0; index < num_solutions; ++index) {
      string fraudolent_transaction;
      getline(infile, fraudolent_transaction);
      test_input.solution[index] = fraudolent_transaction;
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
    Bank bank;

    cout << "Case #" << case_index;

    vector<string> fraudolent_transactions;
    for (const auto& transaction : test_input.input) {
      auto fraudolent_at_transaction = bank.AddTransaction(transaction);
      copy(fraudolent_at_transaction.begin(), fraudolent_at_transaction.end(), back_inserter(fraudolent_transactions));
    }

    if (!equal(test_input.solution.begin(), test_input.solution.end(), fraudolent_transactions.begin())) {
      cout << " FAIL" << endl;
      return 1;
    }

    cout << " OK" << endl;

    ++case_index;
  }

  return 0;
}
