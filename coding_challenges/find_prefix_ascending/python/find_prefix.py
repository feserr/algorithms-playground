"""Find prefix module.
"""


from typing import List
from xmlrpc.client import Boolean


class FindPrefix:
    """Find prefix class.
    """

    def __init__(self) -> None:
        self.words_found: List[str] = []

    def prefix_in_word(self, word: str, prefix: str) -> Boolean:
        """Find if the prefix is in the word.

        Args:
            word (str): The word.
            prefix (str): The prefix.

        Returns:
            Boolean: True if it has the prefix, otherwise False.
        """
        if len(word) < len(prefix):
            return False

        for index, _ in enumerate(prefix):
            if prefix[index] != word[index]:
                return False

        return True

    def continium_bin_search(self, words: List[str], prefix: str, left: int, right: int) -> None:
        """Continium binary search.

        Args:
            words (List[str]): The list of words.
            prefix (str): The prefix.
            left (int): The left bound.
            right (int): The right bound.
        """
        if left > right:
            return None

        middle = (left + right) // 2
        word = words[middle]

        if word[0] == prefix[0]:
            if self.prefix_in_word(word, prefix):
                self.words_found.append(word)

            self.continium_bin_search(words, prefix, left, middle - 1)
            self.continium_bin_search(words, prefix, middle + 1, right)
        elif word[0] > prefix[0]:
            self.continium_bin_search(words, prefix, left, middle - 1)
        else:
            self.continium_bin_search(words, prefix, middle + 1, right)

    def find(self, words: List[str], prefix: str) -> List[str]:
        """Find the words with the prefix.

        Args:
            words (List[str]): The list of words.
            prefix (str): The prefix.

        Returns:
            List[str]: The words with the prefix.
        """
        self.words_found = []

        self.continium_bin_search(words, prefix, 0, len(words))

        return self.words_found
