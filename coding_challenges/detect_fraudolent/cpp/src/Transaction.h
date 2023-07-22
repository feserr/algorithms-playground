/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>

using namespace std;

struct Transaction {
  string name;
  int amount;
  int time;
  string location;

  string ToString() {
    return name + " " + to_string(amount) + " " + to_string(time) + " " + location;
  }
};

#endif  // TRANSACTION_H_