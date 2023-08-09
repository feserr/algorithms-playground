"""Candy crush 1D module.
"""

from typing import List


class CandyNode:
    """Candy node class.
    """

    def __init__(self, candy: int) -> None:
        self.candy: str = candy
        self.amount: int = 1


class CandyCrush1D:
    """Find prefix class.
    """

    def __init__(self) -> None:
        pass

    def crush(self, candies: str) -> str:
        """Crush the candies received.

        Args:
            candies (str): The candies.

        Returns:
            str: Remaing candies.
        """
        candies_stack: List[CandyNode] = []

        # Add candies and crush them if possible.
        for candy in candies:
            # If empty or the top one is the same, add it and continue.
            if not len(candies_stack):
                candies_stack.append(CandyNode(candy))
                continue
            elif candies_stack[0].candy == candy:
                candies_stack[0].amount += 1
                continue

            # Crush the candies at the top if possible.
            while len(candies_stack) != 0 and candies_stack[0].amount >= 3:
                candies_stack = candies_stack[1:]

            # Add the candy at the top if exist, otherwise at the end.
            if len(candies_stack) and candies_stack[0].candy == candy:
                candies_stack[0].amount += 1
            else:
                candies_stack = [CandyNode(candy)] + candies_stack[:]

        # Crush candies left after adding them.
        while len(candies_stack) != 0 and candies_stack[0].amount >= 3:
            candies_stack.pop()

        # if no candy left, return empty result.
        if not len(candies_stack):
            return "-"

        # return remaing candies as a string.
        remain_candies = [candy.candy *
                          candy.amount for candy in candies_stack]
        remain_candies.reverse()
        return "".join(remain_candies)
