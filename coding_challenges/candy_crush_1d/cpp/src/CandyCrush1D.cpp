/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#include "CandyCrush1D.h"

#include <iostream>
#include <stack>

struct Candy {
  char type;
  int amount;
};

std::string CandyCrash1D::GreedyCrush(const std::string& candies) {
  std::stack<Candy> candies_stack;

  for (const auto& candy : candies) {
    if (candies_stack.empty()) {
      candies_stack.emplace(candy, 1);
      continue;
    } else if (candies_stack.top().type == candy) {
      ++candies_stack.top().amount;
      continue;
    }

    while (!candies_stack.empty() && candies_stack.top().amount >= 3) {
      candies_stack.pop();
    }

    if (!candies_stack.empty() && candies_stack.top().type == candy) {
      ++candies_stack.top().amount;
    } else {
      candies_stack.emplace(candy, 1);
    }
  }

  while (!candies_stack.empty() && candies_stack.top().amount >= 3) {
    candies_stack.pop();
  }

  std::string remain_candies = "";
  while (!candies_stack.empty()) {
    const auto& candy_stack_top = candies_stack.top();
    candies_stack.pop();

    std::string candy_stack_top_str = std::string(candy_stack_top.amount, candy_stack_top.type);
    remain_candies = candy_stack_top_str + remain_candies;
  }

  return remain_candies;
}
