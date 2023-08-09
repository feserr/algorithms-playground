/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <iostream>
#include <string>

const int kLetterA = 'A';
const int kLetterZ = 'Z';

bool IsLetter(const char letter) {
  return letter >= kLetterA && letter <= kLetterZ;
}

std::string RepeatTimes(const std::string& str) {
  size_t pos = 0;
  for (; pos < str.size(); ++pos) {
    if (IsLetter(str[pos]) || str[pos] == '(') break;
  }

  return str.substr(0, pos);
}

std::string Decompress(const std::string& compress_str, int repeat = 1) {
  std::string decompress_str = "";

  while (repeat > 0) {
    size_t pos = 0;
    while (pos < compress_str.size()) {
      char comp_char = compress_str[pos];

      if (IsLetter(comp_char)) {
        decompress_str += comp_char;
      } else if (comp_char == '(') {
        size_t end_pos = pos + 1;
        int brackets = 1;
        while (end_pos < compress_str.size()) {
          char inner_comp_char = compress_str[end_pos];
          if (inner_comp_char == '(') {
            ++brackets;
          } else if (inner_comp_char == ')') {
            --brackets;
          }

          if (!brackets) {
            std::string to_repeat_str =
                compress_str.substr(pos + 1, end_pos - pos - 1);
            std::string repeat_number = RepeatTimes(to_repeat_str);

            decompress_str +=
                Decompress(to_repeat_str.substr(repeat_number.size()),
                           atoi(repeat_number.c_str()));
            break;
          }

          ++end_pos;
        }

        pos = end_pos;
      }

      ++pos;
    }

    --repeat;
  }

  return decompress_str;
}

int main(int argc, char** argv) {
  std::string compress_str = "(2(3AB)A)";

  std::string decompress_str = Decompress(compress_str);

  std::cout << decompress_str << std::endl;

  return 0;
}
