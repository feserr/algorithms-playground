/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <iostream>
#include "string_builder.h"

int main(int argc, char** argv) {
  StringBuilder sb;

  sb.Append("Hello");
  sb.Append(" World!!");

  std::cout << sb.Data() << std::endl;

  StringBuilder sb2(sb);

  std::cout << sb.Data() << std::endl;
  std::cout << sb2.Data() << std::endl;

  return 0;
}
