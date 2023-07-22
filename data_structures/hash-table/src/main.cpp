/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <stdio.h>
#include "hash_table.h"

int main(int argc, char** argv) {
  HashTable<int> hash_table = HashTable<int>();
  hash_table.Insert(0);
  hash_table.Insert(1);
  hash_table.Insert(2);
  hash_table.Insert(3);
  hash_table.Insert(4);
  hash_table.Insert(100);
  hash_table.Insert(101);
  hash_table.Insert(201);

  hash_table.Remove(101);

  printf("%d\n", hash_table[201]);

  return 0;
}
