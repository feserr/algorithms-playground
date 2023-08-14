/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#ifndef CODING_CHALLENGES_DETECT_FRAUDOLENT_CPP_SRC_BANK_H_
#define CODING_CHALLENGES_DETECT_FRAUDOLENT_CPP_SRC_BANK_H_

#include <string>
#include <unordered_map>
#include <vector>

#include "Transaction.h"

class Bank {
 public:
  std::vector<std::string> AddTransaction(const std::string& transaction_string);

 private:
  Transaction ParseTransaction(const std::string& transaction);

  std::unordered_map<std::string, std::vector<Transaction>> transactions_map_;
};

#endif  // CODING_CHALLENGES_DETECT_FRAUDOLENT_CPP_SRC_BANK_H_
