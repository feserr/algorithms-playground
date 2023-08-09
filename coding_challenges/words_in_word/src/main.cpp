/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "WordsInWordsDP.hpp"
#include "WordsInWordsGraph.hpp"

int main(int argc, char** argv) {
  if (argc != 3) {
    return 1;
  }

  std::vector<std::string> words;

  std::ifstream infile(argv[1]);
  std::string word;
  while (infile >> word) {
    words.emplace_back(word);
  }

  std::unique_ptr<IWordsInWord> words_in_word = std::make_unique<WordsInWordsDP>();

  if (atoi(argv[2]) == 1) {
    words_in_word.reset(new WordsInWordGraph());
  }

  for (const auto& word_composition : words_in_word->GetPossibleWords(words)) {
    std::cout << word_composition.base_word << ": ";
    for (const auto& word : word_composition.words_composition) {
      std::cout << word << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
