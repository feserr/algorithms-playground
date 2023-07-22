/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "WordsInWordsDP.hpp"
#include "WordsInWordsGraph.hpp"

using namespace std;

int main(int argc, char** argv) {
  if (argc != 3) {
    return 1;
  }

  vector<string> words;

  std::ifstream infile(argv[1]);
  string word;
  while (infile >> word) {
    words.emplace_back(word);
  }

  unique_ptr<IWordsInWord> words_in_word = make_unique<WordsInWordsDP>();

  if (atoi(argv[2]) == 1) {
    words_in_word.reset(new WordsInWordGraph());
  }

  for (const auto& word_composition : words_in_word->GetPossibleWords(words)) {
    cout << word_composition.base_word << ": ";
    for (const auto& word : word_composition.words_composition) {
      cout << word << " ";
    }
    cout << endl;
  }

  return 0;
}