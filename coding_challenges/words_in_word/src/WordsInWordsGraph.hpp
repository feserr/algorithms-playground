/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <list>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "IWordsInWords.h"

struct WordNode {
  char letter;
  std::unordered_map<char, WordNode*> next;

  explicit WordNode(char letter) : letter(letter), next() {}
};

struct WordState {
  int index;
  std::vector<std::string> word_composition;
  WordNode* word_node;

  WordState(WordNode* word_node, int index = 0,
            const std::vector<std::string>& word_composition = {})
      : index(index),
        word_composition(word_composition),
        word_node(word_node) {}
};

class WordsInWordGraph : public IWordsInWord {
 public:
  WordsInWordGraph() : words_root_({'\0'}) {}

  void LoadWords(const std::vector<std::string>& words) {
    std::vector<std::string> words_in_word;

    for (const auto& word : words) {
      auto* node = &words_root_;

      for (const auto& letter : word) {
        auto next_iterator = node->next.find(letter);
        if (next_iterator == node->next.end()) {
          word_nodes_.emplace_back(letter);
          node->next[letter] = &word_nodes_.back();
          next_iterator = node->next.find(letter);
        }

        node = next_iterator->second;
      }
    }
  }

  std::vector<WordsComposition> GetPossibleWords(
      const std::vector<std::string>& words) override {
    LoadWords(words);

    for (const auto& word : words) {
      std::queue<WordState> nodes;
      nodes.emplace(&words_root_);

      BuildPossibleWordsWithWord(word, words, &nodes);
    }

    return possible_words_in_word_;
  }

 private:
  void BuildPossibleWordsWithWord(const std::string& base_word,
                                  const std::vector<std::string>& words,
                                  std::queue<WordState>* word_states) {
    while (!word_states->empty()) {
      auto ws = word_states->front();
      word_states->pop();

      for (const auto& word : words) {
        if (word == base_word) continue;

        auto word_state = ws;
        bool exist = true;
        for (const auto& letter : word) {
          if (letter != base_word[word_state.index]) {
            exist = false;
            break;
          }

          auto next_words = word_state.word_node->next;
          auto next_iterator = next_words.find(letter);
          if (next_iterator != next_words.end()) {
            word_state.word_node = next_iterator->second;
            ++word_state.index;
          } else {
            exist = false;
          }
        }

        if (!exist) {
          continue;
        }

        word_state.word_composition.emplace_back(word);
        if (word_state.index == base_word.size()) {
          possible_words_in_word_.emplace_back(base_word,
                                               word_state.word_composition);
          break;
        }

        word_states->emplace(word_state.word_node, word_state.index,
                            word_state.word_composition);
      }
    }
  }

  WordNode words_root_;
  std::list<WordNode> word_nodes_;
  std::vector<WordsComposition> possible_words_in_word_;
};
