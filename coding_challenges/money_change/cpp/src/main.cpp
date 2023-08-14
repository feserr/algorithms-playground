/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<uint32_t> coins = {1, 2, 5, 10, 20, 50, 100, 200};

std::unordered_map<uint32_t, float> machine_coins = {{1, 0.01f},  {2, 0.02f}, {5, 0.05f},
                                                     {10, 0.1f},  {20, 0.2f}, {50, 0.5f},
                                                     {100, 1.0f}, {200, 2.0f}};

std::vector<float> MoneyChange(const uint32_t money) {
  std::vector<uint32_t> amount_coins(money + 1, 0);
  std::vector<uint32_t> value_coins(money + 1, 0);

  for (uint32_t amount = 1; amount <= money; ++amount) {
    for (const auto& coin : coins) {
      if (coin > amount) break;

      uint32_t num_coins = amount_coins[amount - coin] + 1;
      if (amount_coins[amount] == 0 || num_coins < amount_coins[amount]) {
        value_coins[amount] = coin;
        amount_coins[amount] = num_coins;
      }
    }
  }

  std::vector<float> change;
  change.reserve(money);
  uint32_t pos = money;
  while (pos > 0) {
    change.emplace_back(machine_coins[value_coins[pos]]);
    pos -= value_coins[pos];
  }

  return change;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  auto change = MoneyChange(static_cast<uint32_t>(atof(argv[1]) * 100));

  float last_coin = 0;
  uint32_t amount = 0;
  for (const auto& coin : change) {
    if (last_coin == 0 || last_coin == coin) {
      ++amount;
      last_coin = coin;
    } else {
      std::cout << amount << " " << last_coin << "£" << std::endl;
      amount = 1;
      last_coin = coin;
    }
  }
  std::cout << amount << " " << last_coin << "£" << std::endl;

  return 0;
}
