/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef IWORDS_IN_WORD_H
#define IWORDS_IN_WORD_H

#include <string>
#include <vector>

struct WordsComposition {
  std::string base_word;
  std::vector<std::string> words_composition;
};

class IWordsInWord {
 public:
  virtual ~IWordsInWord() {}

  virtual std::vector<WordsComposition> GetPossibleWords(
      const std::vector<std::string>& words) = 0;
};

#endif  // IWORDS_IN_WORD_H
