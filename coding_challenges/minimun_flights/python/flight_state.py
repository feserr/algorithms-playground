"""Flight state module.
"""

from dataclasses import dataclass, field


@dataclass(order=True)
class FlightState:
    """Flight state class.
    """

    banned: int
    stops: int = field(compare=False)
    current_stop: int = field(compare=False)

    def __init__(self, stop_id, stops=1, banned=0) -> None:
        self.banned = banned
        self.stops = stops
        self.current_stop = stop_id
