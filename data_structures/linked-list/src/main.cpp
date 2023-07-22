/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <stdio.h>

#include "linked_list.h"

int main(int argc, char** argv) {
  auto linked_list = LinkedList<int>();
  linked_list.Append(1);
  linked_list.Append(2);
  linked_list.Append(3);
  linked_list.Append(2);
  linked_list.Append(2);
  linked_list.Append(1);
  linked_list.Append(2);
  linked_list.Append(3);
  linked_list.Append(4);

  linked_list.Remove(2);

  return 0;
}
