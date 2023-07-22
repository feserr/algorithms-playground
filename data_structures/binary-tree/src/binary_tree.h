/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <queue>
#include <stack>

using namespace std;

template <class T>
struct Node {
  explicit Node(T data) {
    this->data = data;
    left = right = NULL;
  }

  T data;
  struct Node* left;
  struct Node* right;
};

template <class T>
class BinaryTree {
 public:
  BinaryTree() : root_(), size_(0) {}

  ~BinaryTree() {
    queue<Node<T>*> nodes;
    nodes.emplace(root_);

    while (!nodes.empty()) {
      Node<T>* node_to_delete = nodes.front();
      nodes.pop();

      if (!node_to_delete) continue;

      nodes.emplace(node_to_delete->left);
      nodes.emplace(node_to_delete->right);

      delete node_to_delete;
    }
  }

  void add(T data) {
    if (!root_) {
      root_ = new Node(data);
      ++size_;
      return;
    }

    Node<T>* node = root_;
    while (node) {
      if (node->data == data) return;
      if (data < node->data) {
        if (!node->left) {
          node->left = new Node(data);
          break;
        }

        node = node->left;
      } else {
        if (!node->right) {
          node->right = new Node(data);
          break;
        }

        node = node->right;
      }
    }

    ++size_;
  }

  void dfsRecursivePrint() {
    recPrint(root_);
    cout << endl;
  }

  void dfsIterativePrint() {
    stack<Node<T>*> nodes;
    Node<T>* node = root_;

    while (!nodes.empty() || node) {
      while (node) {
        nodes.emplace(node);
        node = node->left;
      }

      node = nodes.top();
      nodes.pop();

      cout << node->data << " ";

      node = node->right;
    }

    cout << endl;
  }

  void bfsPrint() {
    queue<Node<T>*> nodes;
    nodes.emplace(root_);

    while (!nodes.empty()) {
      Node<T>* node = nodes.front();
      nodes.pop();

      if (!node) continue;

      cout << node->data << " ";
      nodes.emplace(node->left);
      nodes.emplace(node->right);
    }

    cout << endl;
  }

 private:
  void recPrint(Node<T>* node) {
    if (!node) return;

    recPrint(node->left);
    cout << node->data << " ";
    recPrint(node->right);
  }

  Node<T>* root_;

  uint32_t size_;
};

#endif  // BINARY_TREE_H_
