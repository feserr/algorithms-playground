/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#ifndef BANK_H_
#define BANK_H_

#include <string>
#include <unordered_map>
#include <vector>

#include "Transaction.h"

class Bank {
 public:
  std::vector<std::string> AddTransaction(
      const std::string& transaction_string);

 private:
  Transaction ParseTransaction(const std::string& transaction);

  std::unordered_map<std::string, std::vector<Transaction>> transactions_map_;
};

#endif  // BANK_H_
