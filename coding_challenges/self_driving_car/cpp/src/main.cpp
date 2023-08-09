/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>

struct Point {
  int x;
  int y;

  Point(int x, int y) : x(x), y(y) {}
};

struct PathPoint {
  int cost;
  Point at;

  PathPoint(int cost, const Point& point) : cost(cost), at(point) {}
};

struct Compare {
  bool operator()(const PathPoint& a, const PathPoint& b) {
    return a.cost > b.cost;
  }
};

const std::vector<Point> kDefaultMovs = {{1, 0}, {0, 1}};

class SelfDrivingCar {
 public:
  explicit SelfDrivingCar(const std::vector<Point>& movs = kDefaultMovs)
      : movs_(movs) {}

  int CalculateTime(const std::vector<std::vector<int>>& path) {
    if (!path.size()) return -1;

    int max_y = path.size();
    int max_x = path[0].size();

    std::vector<std::vector<int>> best_cost(max_y,
                                            std::vector<int>(max_x, INT32_MAX));

    std::priority_queue<PathPoint, std::vector<PathPoint>, Compare>
        min_path_point;
    min_path_point.emplace(path[0][0], Point(0, 0));

    while (!min_path_point.empty()) {
      auto path_point = min_path_point.top();
      min_path_point.pop();

      // if (path_point.cost > best_cost[path_point.at.y][path_point.at.x])
      if (best_cost[path_point.at.y][path_point.at.x] != INT32_MAX) continue;

      best_cost[path_point.at.y][path_point.at.x] =
          std::max(path_point.cost, path[path_point.at.y][path_point.at.x]);

      if (path_point.at.x == max_x - 1 && path_point.at.y == max_y - 1) break;

      for (const auto& mov : movs_) {
        if (path_point.at.x + mov.x >= max_x || path_point.at.x + mov.x < 0 ||
            path_point.at.y + mov.y >= max_y || path_point.at.y + mov.y < 0)
          continue;

        Point new_point(path_point.at.x + mov.x, path_point.at.y + mov.y);
        min_path_point.emplace(
            std::max(path_point.cost, path[new_point.y][new_point.x]),
            new_point);
      }
    }

    return best_cost[max_y - 1][max_x - 1];
  }

 private:
  std::vector<Point> movs_;
};

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  std::vector<std::vector<int>> path;

  std::ifstream infile(argv[1]);
  std::string line;
  while (getline(infile, line)) {
    std::istringstream ss(line);
    path.emplace_back(std::istream_iterator<int>{ss},
                      std::istream_iterator<int>{});
  }

  SelfDrivingCar self_driving_car;

  std::cout << "Min time: " << self_driving_car.CalculateTime(path) << std::endl;

  return 0;
}
