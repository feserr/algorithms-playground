"""Minimun flights module.
"""

from collections import defaultdict
from heapq import heappop, heappush
from queue import Queue
from typing import Tuple
from flight_state import FlightState


class MinFlight:
    """Minimun flight class.
    """

    def __init__(self) -> None:
        self.paths = defaultdict(list)
        self.banned = {}

    def parse(self) -> int:
        """Parse the input data.

        Returns:
            int: The exit code.
        """
        num_paths = int(input())
        for _ in range(num_paths):
            src, dst = list(map(int, input().split()))
            self.paths[src].append(dst)

        banned = list(map(int, input().split()))
        for ban in banned:
            self.banned[ban] = True

        return 0

    def stops(self, src: int, dst: int) -> Tuple[int, int]:
        """Returns the minimun stops to destionation.

        Returns:
            int: The minimun stops to the destination.
        """
        if src not in self.paths:
            return -1, -1

        flight_states_queue = Queue()
        for destination in self.paths[src]:
            if destination not in self.banned:
                flight_states_queue.put(FlightState(destination))

        while flight_states_queue.qsize() != 0:
            flight_state: FlightState = flight_states_queue.get()

            if flight_state.current_stop == dst:
                return flight_state.stops, -1

            if flight_state.current_stop in self.paths:
                for destination in self.paths[flight_state.current_stop]:
                    if destination not in self.banned:
                        flight_states_queue.put(FlightState(
                            destination, flight_state.stops + 1))

        return -1, -1

    def stops_wo_restrictions(self, src: int, dst: int) -> Tuple[int, int]:
        """Returns the minimun stops to destionation.

        Returns:
            int: The minimun stops to the destination.
        """
        if src not in self.paths:
            return -1, -1

        flight_states_queue = []

        for destination in self.paths[src]:
            heappush(flight_states_queue, FlightState(
                destination, 1, 0 if destination not in self.banned else 1))

        while len(flight_states_queue) != 0:
            flight_state: FlightState = heappop(flight_states_queue)

            if flight_state.current_stop == dst:
                return flight_state.stops, flight_state.banned

            if flight_state.current_stop in self.paths:
                for destination in self.paths[flight_state.current_stop]:
                    heappush(flight_states_queue, FlightState(
                        destination, flight_state.stops + 1, flight_state.banned + (0 if destination not in self.banned else 1)))

        return -1, -1
