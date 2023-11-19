/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef CODING_CHALLENGES_WORDS_IN_WORD_SRC_WORDSINWORDSDP_HPP_
#define CODING_CHALLENGES_WORDS_IN_WORD_SRC_WORDSINWORDSDP_HPP_

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

  std::vector<WordsComposition> GetPossibleWords(const std::vector<std::string>& words) override {
    LoadWords(words);

    std::vector<WordsComposition> result;

    for (const auto& word : words) {
      std::vector<std::vector<std::string>> word_composition(word.size() + 1);
      word_composition[0].emplace_back("");

      for (const auto [index, letter] : std::views::enumerate(word)) {
        const auto words_for_letter_iterator = words_start_at_letter_.find(letter);
        if (words_for_letter_iterator == words_start_at_letter_.end()) continue;

        // Check the target in the dictionary.
        for (const auto& word_for_letter : words_for_letter_iterator->second) {
          // Continue if the word is the same as the target.
          if (word_for_letter == word) continue;

          // Continue if the word is greater than the target.
          int index_for_word = index + std::ssize(word_for_letter);
          if (index_for_word > word.size()) continue;

          // Continue if the word is not part of the substring of the target.
          const auto s_substr = word.substr(index, size(word_for_letter));
          if (s_substr != word_for_letter) continue;

          std::for_each(word_composition[index].begin(), word_composition[index].end(),
                        [&](const auto& composition_at) {
                          auto new_composition = composition_at + " " + word_for_letter;
                          word_composition[index_for_word].emplace_back(new_composition);
                        });
        }
      }

      if (!word_composition[std::size(word)].empty()) {
        result.emplace_back(word, word_composition[word.size()]);
      }
    }

    return result;
  }

 private:
  std::unordered_map<char, std::vector<std::string>> words_start_at_letter_;
};

#endif  // CODING_CHALLENGES_WORDS_IN_WORD_SRC_WORDSINWORDSDP_HPP_
