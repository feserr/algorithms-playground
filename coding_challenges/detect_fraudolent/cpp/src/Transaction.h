/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>

struct Transaction {
  std::string name;
  int amount;
  int time;
  std::string location;

  std::string ToString() {
    return name + " " + std::to_string(amount) + " " + std::to_string(time) + " " + location;
  }
};

#endif  // TRANSACTION_H_
