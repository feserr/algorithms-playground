"""Shortest substr module
"""

from collections import defaultdict
from typing import Tuple


class Node():
    """Node class.
    """
    def __init__(self) -> None:
        self.letter: str = ""
        self.visited: int = 0
        self.next: dict[str, Node] = defaultdict(Node)


class ShortestSubstr():
    """Shortest substr class
    """

    def __init__(self) -> None:
        self._letter_dict: dict[str, Node] = defaultdict(Node)

    def __parse_word(self, word: str):
        """Parse a word and populate the letter dictionary.

        Args:
            word (str): the word
        """
        prev_states: list[Node] = []

        for letter in word:
            for index, _ in enumerate(prev_states):
                prev_states[index].next[letter].letter = letter
                prev_states[index].next[letter].visited += 1
                prev_states[index] = prev_states[index].next[letter]

            self._letter_dict[letter].letter = letter
            self._letter_dict[letter].visited += 1
            new_state = self._letter_dict[letter]

            prev_states.append(new_state)

    def __check_and_append(self, res: list[list[str]], index: int, state: Tuple[Node, str]):
        """Check if the word state is better than the actual shortest solution for the given
        index.

        Args:
            res (list[list[str]]): The solution array.
            index (int): The index of the solutions.
            state (Tuple[Node, str]): The state to check.
        """
        if state[0].visited == 1:
            if len(res[index]) == 0:
                res[index] = []
                res[index].append(state[1])
            elif len(res[index]) > 0 and len(state[1]) < len(res[index][0]):
                res[index] = []
                res[index].append(state[1])
            elif len(state[1]) == len(res[index][0]):
                res[index].append(state[1])

    def get_shortest_substr(self, words: list[str]) -> list[str]:
        """Get the shortest unique substr for the given words.

        Args:
            words (list[str]): The word list.

        Returns:
            list[str]: The shortest substring of each word.
        """
        for word in words:
            self.__parse_word(word)

        res: list[list[str]] = [[]] * len(words)
        for index, word in enumerate(words):
            states: list[Tuple[Node, str]] = []

            for letter in word:
                for index_state, _ in enumerate(states):
                    states[index_state][0] = states[index_state][0].next[letter]
                    states[index_state][1] += letter
                    self.__check_and_append(res, index, states[index_state])

                states.append([self._letter_dict[letter], letter])
                self.__check_and_append(res, index, states[len(states) - 1])

        return res
