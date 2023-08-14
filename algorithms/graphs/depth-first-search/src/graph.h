/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef ALGORITHMS_GRAPHS_DEPTH_FIRST_SEARCH_SRC_GRAPH_H_
#define ALGORITHMS_GRAPHS_DEPTH_FIRST_SEARCH_SRC_GRAPH_H_

#include <inttypes.h>

#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

class Graph {
 public:
  Graph() : num_verts_(0), nodes_() {}

  explicit Graph(uint32_t num_verts) : num_verts_(num_verts) { nodes_.resize(num_verts); }

  void AddEdge(int vertice, int value) { nodes_[vertice].emplace_back(value); }

  void DFS(uint32_t source) {
    std::vector<bool> visited = std::vector<bool>(num_verts_, false);

    std::stack<int> stack;
    stack.emplace(source);

    visited[source] = true;

    while (!stack.empty()) {
      int t_source = stack.top();
      stack.pop();
      std::cout << t_source << " ";

      for (const auto& value : nodes_[t_source]) {
        if (visited[value]) continue;

        visited[value] = true;
        stack.emplace(value);
      }
    }

    std::cout << std::endl;
  }

 private:
  uint32_t num_verts_;
  std::vector<std::vector<int>> nodes_;
};

#endif  // ALGORITHMS_GRAPHS_DEPTH_FIRST_SEARCH_SRC_GRAPH_H_
