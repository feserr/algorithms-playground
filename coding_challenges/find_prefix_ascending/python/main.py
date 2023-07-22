"""Main module
"""

import sys
from find_prefix import FindPrefix


def main() -> int:
    """Main application

    Returns:
        int: Exit code.
    """
    cases = int(input())
    for case in range(cases):
        find_prefix = FindPrefix()

        words = input().split()
        prefix = input()
        words_with_prefix = find_prefix.find(words, prefix)
        print(f"Case #{case}: {len(words_with_prefix)}")
        for word in words_with_prefix:
            print(word)

    return 0


if __name__ == "__main__":
    sys.exit(main())
