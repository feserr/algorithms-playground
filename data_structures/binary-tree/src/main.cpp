/*
 * Copyright 2021 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "binary_tree.h"

int main(int argc, char** argv) {
  BinaryTree<int> tree;

  tree.add(4);
  tree.add(3);
  tree.add(1);
  tree.add(2);
  tree.add(5);

  tree.dfsIterativePrint();
  tree.dfsRecursivePrint();

  tree.bfsPrint();

  return 0;
}
