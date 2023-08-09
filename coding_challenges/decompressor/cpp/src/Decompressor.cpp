/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include "Decompressor.h"

#include <format>
#include <iostream>

const char kOpen = '(';
const char kClose = ')';

std::string RepeatString(std::string_view str, int repeat) {
  if (repeat <= 1) return std::string{str};

  std::string result;
  result.reserve(std::ssize(str) * repeat);

  for (int i = 0; i < repeat; ++i) {
    result += str;
  }

  return result;
}

std::string SingleDecompress(std::string_view compress_str, int* index) {
  int str_len = std::ssize(compress_str);
  if (*index >= str_len) return "";

  int repeat = 0;
  std::string decompress_str = "";

  while (*index < str_len) {
    char char_at_str = compress_str[*index];
    if (char_at_str == kOpen) {
      ++*index;
      decompress_str += SingleDecompress(compress_str, index);
    } else if (char_at_str == kClose) {
      break;
    } else if (std::isdigit(char_at_str)) {
      repeat += static_cast<int>(char_at_str - '0');
    } else {
      decompress_str += char_at_str;
    }

    ++*index;
  }

  return RepeatString(decompress_str, repeat);
}

std::string Decompressor::Decompress(std::string_view compress_str) {
  int index = 0;
  return SingleDecompress(compress_str, &index);
}
