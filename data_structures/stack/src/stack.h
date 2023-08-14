/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef DATA_STRUCTURES_STACK_SRC_STACK_H_
#define DATA_STRUCTURES_STACK_SRC_STACK_H_

#include <algorithm>
#include <cstdint>
#include <iostream>

template <class T>
struct Node {
  explicit Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
  T data;
  Node<T>* next;
  Node<T>* prev;
};

template <class T>
class Stack {
 public:
  Stack() : head_(nullptr), tail_(nullptr), size_(0) {}

  ~Stack() {
    while (tail_) {
      Pop();
    }
  }

  void Append(const T value) {
    if (!head_) {
      head_ = new Node(value);
      tail_ = head_;
    } else {
      tail_->next = new Node(value);
      tail_->next->prev = tail_;
      tail_ = tail_->next;
    }

    ++size_;
  }

  void Remove(const T value) {
    auto node = head_;
    while (node) {
      if (node->data == value) {
        if (node == head_) {
          head_ = node->next;
          head_->prev = nullptr;
          delete node;
          --size_;
          return;
        } else {
          node->prev = node->next;
          delete node;
          --size_;
          return;
        }
      }
    }
  }

  void Pop() {
    if (head_ == nullptr || tail_ == nullptr) return;

    auto node = tail_;
    tail_ = tail_->prev;
    delete node;
    --size_;
  }

  T Head() {
    if (!head_) throw std::runtime_error("try to get the head of an empty stack.");

    return head_->data;
  }

  T Tail() {
    if (!head_ || !tail_) throw std::runtime_error("try to get the head of an empty stack.");

    return tail_->data;
  }

  uint32_t Size() { return size_; }

 private:
  Node<T>* head_;
  Node<T>* tail_;
  uint32_t size_;
};

#endif  // DATA_STRUCTURES_STACK_SRC_STACK_H_
