/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef STACK_H_
#define STACK_H_

#include <algorithm>
#include <iostream>

template <class T>
struct Node {
  Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
  T data;
  Node<T>* next;
  Node<T>* prev;
};

template <class T>
class Stack {
 public:
  Stack() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

  ~Stack() {
    while (m_tail) {
      Pop();
    }
  }

  void Append(const T value) {
    if (!m_head) {
      m_head = new Node(value);
      m_tail = m_head;
    } else {
      m_tail->next = new Node(value);
      m_tail->next->prev = m_tail;
      m_tail = m_tail->next;
    }

    ++m_size;
  }

  void Remove(const T value) {
    auto node = m_head;
    while (node) {
      if (node->data == value) {
        if (node == m_head) {
          m_head = node->next;
          m_head->prev = nullptr;
          delete node;
          --m_size;
          return;
        } else {
          node->prev = node->next;
          delete node;
          --m_size;
          return;
        }
      }
    }
  }

  void Pop() {
    if (m_head == nullptr || m_tail == nullptr) return;

    auto node = m_tail;
    m_tail = m_tail->prev;
    delete node;
    --m_size;
  }

  T Head() {
    if (!m_head)
      throw std::runtime_error("try to get the head of an empty stack.");

    return m_head->data;
  }

  T Tail() {
    if (!m_head || !m_tail)
      throw std::runtime_error("try to get the head of an empty stack.");

    return m_tail->data;
  }

  uint32_t Size() { return m_size; }

 private:
  Node<T>* m_head;
  Node<T>* m_tail;
  uint32_t m_size;
};

#endif  // STACK_H_
