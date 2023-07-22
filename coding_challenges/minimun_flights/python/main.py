"""Main module
"""

import sys
from min_flights import MinFlight


def main() -> int:
    """Main application

    Returns:
        int: Exit code.
    """
    cases = int(input())
    for case in range(cases):
        min_flight = MinFlight()
        min_flight.parse()

        src, dst = list(map(int, input().split()))
        stops, stops_banned = min_flight.stops_wo_restrictions(src, dst)
        print(f"Case #{case}: {stops} stops, {stops_banned} stops on banned")

    return 0


if __name__ == "__main__":
    sys.exit(main())
