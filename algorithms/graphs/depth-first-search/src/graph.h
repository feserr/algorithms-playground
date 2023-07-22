/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef ALGORITHMS_GRAPHS_DEPTH_FIRST_SEARCH_SRC_GRAPH_H_
#define ALGORITHMS_GRAPHS_DEPTH_FIRST_SEARCH_SRC_GRAPH_H_

#include <inttypes.h>
#include <list>

class Graph {
 public:
  Graph() : num_verts_(0), nodes_() {}
  explicit Graph(uint32_t num_verts) : num_verts_(num_verts) {
    nodes_ = new std::list<int>[num_verts];
  }
  ~Graph() { delete[] nodes_; }

  void AddEdge(int vertice, int value) { nodes_[vertice].push_back(value); }

  void DFSUtil(uint32_t source, bool* visited) {
    if (visited[source]) {
      return;
    }

    visited[source] = true;
    printf("%d ", source);

    for (std::list<int>::iterator it = nodes_[source].begin();
         it != nodes_[source].end(); ++it) {
      DFSUtil(*it, visited);
    }
  }

  void DFS(uint32_t source) {
    bool* visited = new bool[num_verts_];
    for (uint32_t it = 0; it < num_verts_; ++it) {
      visited[it] = false;
    }

    DFSUtil(source, visited);
    printf("\n");

    delete[] visited;
  }

  void DFS_l(uint32_t source) {
    bool* visited = new bool[num_verts_];
    for (uint32_t it = 0; it < num_verts_; ++it) {
      visited[it] = false;
    }

    std::list<int> stack;
    stack.push_back(source);

    while (!stack.empty()) {
      int t_source = stack.back();
      if (visited[t_source]) {
        stack.pop_back();
        continue;
      }
      printf("%d ", t_source);
      visited[t_source] = true;
      stack.pop_back();

      for (std::list<int>::iterator it = nodes_[t_source].begin();
           it != nodes_[t_source].end(); ++it) {
        stack.push_back(*it);
      }
    }
    printf("\n");

    delete[] visited;
  }

 private:
  uint32_t num_verts_;
  std::list<int>* nodes_;
};

#endif  // ALGORITHMS_GRAPHS_DEPTH_FIRST_SEARCH_SRC_GRAPH_H_
