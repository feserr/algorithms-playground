/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "lru.h"

enum class Command { CreateClass, Put, Get };

int main(int argc, char** argv) {
  std::vector<std::string> commands = {
      "LRUCache", "put", "put", "put", "put", "put", "get", "put", "get",
      "get",      "put", "get", "put", "put", "put", "get", "put", "get",
      "get",      "get", "get", "put", "put", "get", "get", "get", "put",
      "put",      "get", "put", "get", "put", "get", "get", "get", "put",
      "put",      "put", "get", "put", "get", "get", "put", "put", "get",
      "put",      "put", "put", "put", "get", "put", "put", "get", "put",
      "put",      "get", "put", "put", "put", "put", "put", "get", "put",
      "put",      "get", "put", "get", "get", "get", "put", "get", "get",
      "put",      "put", "put", "put", "get", "put", "put", "put", "put",
      "get",      "get", "get", "put", "put", "put", "get", "put", "put",
      "put",      "get", "put", "put", "put", "get", "get", "get", "put",
      "put",      "put", "put", "get", "put", "put", "put", "put", "put",
      "put",      "put"};
  std::vector<std::vector<int>> inputs = {
      {10},     {10, 13}, {3, 17},  {6, 11},  {10, 5}, {9, 10},  {13},
      {2, 19},  {2},      {3},      {5, 25},  {8},     {9, 22},  {5, 5},
      {1, 30},  {11},     {9, 12},  {7},      {5},     {8},      {9},
      {4, 30},  {9, 3},   {9},      {10},     {10},    {6, 14},  {3, 1},
      {3},      {10, 11}, {8},      {2, 14},  {1},     {5},      {4},
      {11, 4},  {12, 24}, {5, 18},  {13},     {7, 23}, {8},      {12},
      {3, 27},  {2, 12},  {5},      {2, 9},   {13, 4}, {8, 18},  {1, 7},
      {6},      {9, 29},  {8, 21},  {5},      {6, 30}, {1, 12},  {10},
      {4, 15},  {7, 22},  {11, 26}, {8, 17},  {9, 29}, {5},      {3, 4},
      {11, 30}, {12},     {4, 29},  {3},      {9},     {6},      {3, 4},
      {1},      {10},     {3, 29},  {10, 28}, {1, 20}, {11, 13}, {3},
      {3, 12},  {3, 8},   {10, 9},  {3, 26},  {8},     {7},      {5},
      {13, 17}, {2, 27},  {11, 15}, {12},     {9, 19}, {2, 15},  {3, 16},
      {1},      {12, 17}, {9, 1},   {6, 19},  {4},     {5},      {5},
      {8, 1},   {11, 7},  {5, 2},   {9, 28},  {1},     {2, 2},   {7, 4},
      {4, 22},  {7, 24},  {9, 26},  {13, 28}, {11, 26}};
  // std::vector<std::string> commands = {"LRUCache", "put", "get",
  //                                      "put",      "get", "get"};
  // std::vector<std::vector<int>> inputs = {{1}, {2, 1}, {2}, {3, 2}, {2},
  // {3}};

  std::unordered_map<std::string, Command> commandToEnum(
      {{"LRUCache", Command::CreateClass},
       {"put", Command::Put},
       {"get", Command::Get}});

  LRU<int, int> lru;

  for (auto pos = 0; pos < commands.size(); ++pos) {
    auto command = commands.at(pos);
    auto input = inputs.at(pos);
    switch (commandToEnum[command]) {
      case Command::CreateClass:
        lru = LRU<int, int>(input.at(0));
        break;
      case Command::Put:
        lru.put(input.at(0), input.at(1));
        std::cout << "null ";
        break;
      case Command::Get:
        std::cout << lru.get(input.at(0)).value_or(-1) << " ";
        break;
      default:
        break;
    }
  }

  std::cout << std::endl;

  return 0;
}
