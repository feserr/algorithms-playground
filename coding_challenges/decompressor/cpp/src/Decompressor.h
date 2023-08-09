/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef CODING_CHALLENGES_DECOMPRESSOR_CPP_SRC_DECOMPRESSOR_H_
#define CODING_CHALLENGES_DECOMPRESSOR_CPP_SRC_DECOMPRESSOR_H_

#include <string>

class Decompressor {
 public:
  static std::string Decompress(std::string_view compress_str);
};

#endif  // CODING_CHALLENGES_DECOMPRESSOR_CPP_SRC_DECOMPRESSOR_H_
