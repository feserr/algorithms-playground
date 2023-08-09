/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <stdio.h>

#include "array_list.h"

int main(int argc, char** argv) {
  ArrayList<int> array_list;

  for (int it = 0; it < 200; ++it) {
    array_list.push_back(it);
  }

  ArrayList<int> backup = array_list;
  backup.remove(195);

  printf("%d\n", backup.at(199));
  printf("%d\n", backup.find(2));
  printf("%d\n", backup.pop_back());
  printf("%d\n", backup.pop_front());

  return 0;
}
