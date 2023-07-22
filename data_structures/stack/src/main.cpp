/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <stdio.h>

#include "stack.h"

int main(int argc, char** argv) {
  auto stack = Stack<int>();
  stack.Append(1);
  stack.Append(2);
  stack.Append(3);
  stack.Append(4);
  stack.Append(5);
  stack.Append(6);

  std::cout << "Stack, size: " << stack.Size() << ", head: " << stack.Head()
            << ", tail: " << stack.Tail() << std::endl;

  stack.Remove(1);

  std::cout << "Stack, size: " << stack.Size() << ", head: " << stack.Head()
            << ", tail: " << stack.Tail() << std::endl;

  stack.Pop();

  std::cout << "Stack, size: " << stack.Size() << ", head: " << stack.Head()
            << ", tail: " << stack.Tail() << std::endl;

  return 0;
}
