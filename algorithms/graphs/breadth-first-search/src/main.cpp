/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <stdio.h>

#include "graph.h"

int main(int argc, char** argv) {
  Graph graph(4);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 0);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 3);

  graph.BFS(2);

  return 0;
}
