"""Main module
"""

import sys
from shortest_substr import ShortestSubstr


def main() -> int:
    """Main application

    Returns:
        int: Exit code.
    """
    cases = int(input())
    for case in range(cases):
        words = list(map(str, input().split()))
        shortest_substr_obj = ShortestSubstr()
        shortest_substrs = shortest_substr_obj.get_shortest_substr(words)

        for shortest_substr in shortest_substrs:
            possible_solution = list(map(str, input().split()))

            missing = [string for string in shortest_substr if not any(
                string in ks for ks in possible_solution)]

            if missing:
                print(f"Case #{case} FAIL")
                return 1

        print(f"Case #{case} OK")

    return 0


if __name__ == "__main__":
    sys.exit(main())
