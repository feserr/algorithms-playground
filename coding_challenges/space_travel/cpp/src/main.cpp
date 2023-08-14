/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

// A spaceship is approaching some planets that are arranged in a line along a
// single axis. It needs to pass through the line of the planets, but can't get
// too close to any planet, otherwise it would get caught in that planet's
// gravitational field. Given a list of planets, where each planet is specified
// by its position along the line and the range of its gravitational field,
// compute the list of gaps from [0, 1000] through which the spaceship can fly.

// -||X|X|----------
// input                output (gaps)           reasoning
// [location, orbit]
// [3,2]                [0,1],[5,1000]          The field covers [1,5].
// [3,2],[5,1]          [0,1],[6,1000]          The fields cover [1,5] and
// [4,6]. [2,1],[5,1]          [0,1],[3,4],[6,1000]    The fields cover [1,3]
// and [4,6]. [2,2],[7,1],[4,1]    [5,6],[8,1000]          The fields cover
// [0,4], [6,8], an [3,5]

//
// pos = 8
// res = [5,6]

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int kMaxPosition = 1000;

class Position {
 public:
  int x;
  int y;

  Position(int x, int y) : x(x), y(y) {}
};

class Compare {
 public:
  bool operator()(Position a, Position b) { return a.x > b.x; }
};

std::vector<Position> GetFlyCoordinates(const std::vector<Position>& planet_and_orbit) {
  std::priority_queue<Position, std::vector<Position>, Compare> planet_and_orbit_sorted;

  for (const auto& planet : planet_and_orbit) {
    planet_and_orbit_sorted.emplace(planet.x, planet.y);
  }

  int current_pos = 0;
  std::vector<Position> output;

  while (!planet_and_orbit_sorted.empty()) {
    auto planet_orbit = planet_and_orbit_sorted.top();
    planet_and_orbit_sorted.pop();

    if (planet_orbit.x - planet_orbit.y > current_pos) {
      // cout << planet_orbit.x << " " << planet_orbit.y << endl;
      output.emplace_back(current_pos, planet_orbit.x - planet_orbit.y);
    }

    current_pos = planet_orbit.x + planet_orbit.y;
  }

  if (current_pos < kMaxPosition) {
    output.emplace_back(current_pos, kMaxPosition);
  }

  return output;
}

// [3,2]                [0,1],[5,1000]          The field covers [1,5].
// [3,2],[5,1]          [0,1],[6,1000]          The fields cover [1,5] and
// [4,6]. [2,1],[5,1]          [0,1],[3,4],[6,1000]    The fields cover [1,3]
// and [4,6]. [2,2],[7,1],[4,1]    [5,6],[8,1000]          The fields cover
// [0,4], [6,8], an [3,5]

int main(int argc, char** argv) {
  // vector<Position> input = {{3,2}};
  // vector<Position> input = {{3,2}, {5,1}};
  // vector<Position> input = {{2,1}, {5,1}};
  // vector<Position> input = {{2,2}, {7,1}, {4,1}};
  std::vector<Position> input = {{3, 2}, {4, 1}};

  auto output = GetFlyCoordinates(input);

  for (const auto& position : output) {
    std::cout << "[" << position.x << "," << position.y << "]"
              << ",";
  }
  std::cout << std::endl;
}
