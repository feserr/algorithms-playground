/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <algorithm>
#include <iostream>

template <class T>
struct Data {
  explicit Data(const T value) : data(value), next(nullptr) {}

  T data;
  Data<T>* next;
};

template <class T>
class LinkedList {
 public:
  LinkedList() : root(nullptr) {}

  // void Append(const T value) {
  //   if (!root) {
  //     root = new Data<T>(value);
  //   } else {
  //     Data<T>* tmp = root;
  //     while (tmp) {
  //       if (!tmp->next) break;
  //       tmp = tmp->next;
  //     }
  //     tmp->next = new Data<T>(value);
  //   }
  // }

  void Append(const T value) {
    Data<T>** ptr_root = &root;
    while (*ptr_root) {
      ptr_root = &((*ptr_root)->next);
    }
    *ptr_root = new Data(value);
  }

  void Remove(const T value) {
    Data<T>** ptr_root = &root;
    while (*ptr_root) {
      if ((*ptr_root)->data == value) {
        Data<T>* tmp = *ptr_root;
        *ptr_root = (*ptr_root)->next;
        delete tmp;
      } else {
        ptr_root = &((*ptr_root)->next);
      }
    }
  }

 private:
  Data<T>* root;
};

#endif  // LINKED_LIST_H_
