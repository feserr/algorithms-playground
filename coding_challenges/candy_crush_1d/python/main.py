"""Main module
"""

import sys
from candy_crush_1d import CandyCrush1D


def main() -> int:
    """Main application

    Returns:
        int: Exit code.
    """
    case = 1
    for candies in sys.stdin:
        expected = input()

        candy_crush_1d = CandyCrush1D()
        solution = candy_crush_1d.crush(candies.replace('\n', ''))
        if solution != expected:
            print(f"FAILED\nCase {case} failed: expected '{expected}' got '{solution}'")
            return 1

        case += 1

    print("PASSED")

    return 0


if __name__ == "__main__":
    sys.exit(main())
