/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <format>
#include <iostream>
#include <string>

#include "Decompressor.h"

int main(int argc, char** argv) {
  int num_case = 1;
  while (std::cin) {
    std::string compressed_str, expected;
    std::cin >> compressed_str >> expected;

    std::string case_solution = Decompressor::Decompress(compressed_str);
    if (expected != case_solution) {
      std::cout << std::format("FAILED\nCase {}: expected '{}' got '{}',", num_case, expected,
                               case_solution)
                << std::endl;
    }

    ++num_case;
  }

  std::cout << "PASSED" << std::endl;

  return 0;
}
