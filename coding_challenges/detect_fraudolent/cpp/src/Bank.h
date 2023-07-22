/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#ifndef BANK_H_
#define BANK_H_

#include <unordered_map>
#include <vector>

#include "Transaction.h"

using namespace std;

class Bank {
 public:
  vector<string> AddTransaction(const string& transaction_string);

 private:
  Transaction ParseTransaction(const string& transaction);

  unordered_map<string, vector<Transaction>> transactions_map_;
};

#endif  // BANK_H_
