/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include "Bank.h"

#include <algorithm>
#include <fstream>
#include <vector>

const int kMaxAmount = 1000;
const int kMaxTime = 60;

vector<string> Bank::AddTransaction(const string& transaction_string) {
  Transaction transaction = ParseTransaction(transaction_string);

  if (transaction.amount > kMaxAmount) {
    return {transaction.ToString()};
  }

  auto transaction_iterator = transactions_map_.find(transaction.name);
  if (transaction_iterator == transactions_map_.end()) {
    transactions_map_[transaction.name].emplace_back(transaction);
    return {};
  }

  if (abs(transaction_iterator->second.back().time - transaction.time) <=
      kMaxTime) {
    return {transaction.ToString()};
  } else if (transaction_iterator->second.front().location !=
             transaction.location) {
    vector<string> fraudolent_transactions;
    fraudolent_transactions.reserve(transaction_iterator->second.size() + 1);

    transform(transaction_iterator->second.begin(),
              transaction_iterator->second.end(),
              back_inserter(fraudolent_transactions),
              [](Transaction& trans) { return trans.ToString(); });

    fraudolent_transactions.emplace_back(transaction.ToString());

    return fraudolent_transactions;
  }

  return {};
}

Transaction Bank::ParseTransaction(const string& transaction) {
  std::ifstream infile(transaction);
  string name, location;
  int amount, time;

  infile >> name >> amount >> time >> location;

  return {name, amount, time, location};
}
