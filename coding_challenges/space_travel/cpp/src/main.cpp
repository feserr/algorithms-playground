// A spaceship is approaching some planets that are arranged in a line along a single axis. It needs to pass through the line of the planets, but can't get too close to any planet, otherwise it would get caught in that
// planet's gravitational field.
// Given a list of planets, where each planet is specified by its position along the line and the range of its gravitational field, compute the list of gaps from [0, 1000] through which the spaceship can fly.

// -||X|X|----------
// input                output (gaps)           reasoning
// [location, orbit]
// [3,2]                [0,1],[5,1000]          The field covers [1,5].
// [3,2],[5,1]          [0,1],[6,1000]          The fields cover [1,5] and [4,6].
// [2,1],[5,1]          [0,1],[3,4],[6,1000]    The fields cover [1,3] and [4,6].
// [2,2],[7,1],[4,1]    [5,6],[8,1000]          The fields cover [0,4], [6,8], an [3,5]

//
// pos = 8
// res = [5,6]

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int kMaxPosition = 1000;

class Position {
  public:
    int x;
    int y;

    Position(int x, int y) : x(x), y(y) {}
};

class Compare {
  public:
    bool operator() (Position a, Position b) {
        return a.x > b.x;
    }
};


vector<Position> GetFlyCoordinates(const vector<Position>& planet_and_orbit) {
    priority_queue<Position, vector<Position>, Compare> planet_and_orbit_sorted;

    for (const auto& planet : planet_and_orbit) {
        planet_and_orbit_sorted.emplace(planet.x, planet.y);
    }

    int current_pos = 0;
    vector<Position> output;

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
// [3,2],[5,1]          [0,1],[6,1000]          The fields cover [1,5] and [4,6].
// [2,1],[5,1]          [0,1],[3,4],[6,1000]    The fields cover [1,3] and [4,6].
// [2,2],[7,1],[4,1]    [5,6],[8,1000]          The fields cover [0,4], [6,8], an [3,5]

int main(int argc, char** argv) {
    // vector<Position> input = {{3,2}};
    // vector<Position> input = {{3,2}, {5,1}};
    // vector<Position> input = {{2,1}, {5,1}};
    // vector<Position> input = {{2,2}, {7,1}, {4,1}};
    vector<Position> input = {{3,2},{4,1}};

    auto output = GetFlyCoordinates(input);

    for (const auto& position : output) {
        cout << "[" << position.x << "," << position.y << "]" << ",";
    }
    cout << endl;
}
