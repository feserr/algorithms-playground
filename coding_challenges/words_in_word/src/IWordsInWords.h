/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef CODING_CHALLENGES_WORDS_IN_WORD_SRC_IWORDSINWORDS_H_
#define CODING_CHALLENGES_WORDS_IN_WORD_SRC_IWORDSINWORDS_H_

#include <string>
#include <vector>

struct WordsComposition {
  std::string base_word;
  std::vector<std::string> words_composition;
};

class IWordsInWord {
 public:
  virtual ~IWordsInWord() {}

  virtual std::vector<WordsComposition> GetPossibleWords(const std::vector<std::string>& words) = 0;
};

#endif  // CODING_CHALLENGES_WORDS_IN_WORD_SRC_IWORDSINWORDS_H_
