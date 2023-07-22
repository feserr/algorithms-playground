/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class LetterNode {
 public:
  LetterNode(char letter) : letter(letter), nexts() {}

  char letter;
  unordered_map<char, unique_ptr<LetterNode>> nexts;
};

class State {
 public:
  State(const LetterNode* node, int val = 0) : node(node), val(val) {}

  const LetterNode* node;
  int val;
};

class DifferBy {
 public:
  DifferBy(int maxDiffer) : maxDiffer_(maxDiffer) {}

  bool Check(const vector<string>& words) {
    LetterNode root('\0');

    for (const auto& word : words) {
      queue<State> states;

      // Initialise the states
      LetterNode* node = &root;
      for (const auto& next : node->nexts) {
        states.emplace(next.second.get(), next.first == word[0] ? 0 : 1);
      }

      // Pointer to store the new letters if needed
      LetterNode* to_store = &root;
      if (to_store->nexts.find(word[0]) == to_store->nexts.end())
        to_store->nexts[word[0]] = make_unique<LetterNode>(word[0]);
      to_store = to_store->nexts[word[0]].get();

      for (int pos = 1; pos < word.size(); ++pos) {
        char letter = word[pos];

        // Process the current states
        // We will create new states with all the possible next letter of
        // each state. If difference is above the maximun allowed, the state
        // will be discard.
        queue<State> new_states;
        while (!states.empty()) {
          auto state = states.front();
          states.pop();

          // Iterate all over the possible next words
          for (const auto& next_node : state.node->nexts) {
            // If it is different to the actual letter increase the state value
            if (next_node.first != letter) {
              ++state.val;

              // If the state value is greater than the maximum possible
              // difference stop with this state.
              if (state.val > maxDiffer_) {
                continue;
              }
            }

            // Add a new updated state.
            new_states.emplace(next_node.second.get(), state.val);
          }
        }
        states = new_states;

        // Create the new node if needed.
        if (to_store->nexts.find(letter) == to_store->nexts.end())
          to_store->nexts[letter] = make_unique<LetterNode>(letter);
        to_store = to_store->nexts[letter].get();
      }

      if (!states.empty()) return true;
    }

    return false;
  }

 private:
  int maxDiffer_;
};

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

  DifferBy differBy(atoi(argv[2]));
  if (differBy.Check(words))
    cout << "Yes";
  else
    cout << "No";
  cout << endl;

  return 0;
}