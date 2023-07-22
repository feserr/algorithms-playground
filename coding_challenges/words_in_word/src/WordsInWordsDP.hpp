/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <algorithm>
#include <ranges>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "IWordsInWords.h"

class WordsInWordsDP : public IWordsInWord {
 public:
  void LoadWords(const std::vector<std::string>& words) {
    for (const auto& word : words) {
      words_start_at_letter_[word[0]].emplace_back(word);
    }
  }

  std::vector<WordsComposition> GetPossibleWords(
      const std::vector<std::string>& words) override {
    LoadWords(words);

    std::vector<WordsComposition> result;

    for (const auto& word : words) {
      std::vector<std::vector<std::string>> word_composition(word.size() + 1);
      word_composition[0].emplace_back("");

      for (const auto [index, letter] : std::views::enumerate(word)) {
        const auto words_for_letter_iterator =
            words_start_at_letter_.find(letter);
        if (words_for_letter_iterator == words_start_at_letter_.end()) continue;

        for (const auto& word_for_letter : words_for_letter_iterator->second) {
          if (word_for_letter == word) continue;

          int index_for_word = index + std::ssize(word_for_letter);
          if (index_for_word > word.size()) continue;

          bool valid = true;
          for (int index_of_word = 0;
               std::cmp_less(index_of_word, word_for_letter.size());
               ++index_of_word) {
            if (word_for_letter[index_of_word] != word[index + index_of_word]) {
              valid = false;
              break;
            }
          }
          if (!valid) continue;

          std::for_each(
              word_composition[index].begin(), word_composition[index].end(),
              [&](const auto& composition_at) {
                word_composition[index_for_word].emplace_back(composition_at);
              });
          word_composition[index_for_word].emplace_back(word_for_letter);
        }
      }

      if (!word_composition[word.size()].empty()) {
        result.emplace_back(word, word_composition[word.size()]);
      }
    }

    return result;
  }

 private:
  std::unordered_map<char, std::vector<std::string>> words_start_at_letter_;
};
