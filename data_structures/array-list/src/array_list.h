/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef DATA_STRUCTURES_ARRAY_LIST_SRC_ARRAY_LIST_H_
#define DATA_STRUCTURES_ARRAY_LIST_SRC_ARRAY_LIST_H_

#include <algorithm>
#include <iostream>

template <class T>
struct Data {
  explicit Data(const T value) : node(value), next(nullptr) {}

  T node;
  struct Data* next;
};

/**
 * @brief ArrayList is a sequence of containers.
 *
 * @tparam T Type of the elements.
 */
template <class T>
class ArrayList {
 public:
  /**
   * @brief Construct a new ArrayList object.
   */
  ArrayList() : head_(new Data<T>(T())), size_(0) {}

  /**
   * @brief Destroy the ArrayList object.
   */
  ~ArrayList() { removeAll(); }

  /**
   * @brief Copy construct.
   *
   * @param rhs ArrayList to be copied.
   */
  ArrayList(const ArrayList& rhs) : size_(rhs.size_) { copy(rhs); }

  /**
   * @brief Copy assignment operator.
   *
   * @param rhs ArrayList to be copied.
   * @return ArrayList& The ArrayList copied.
   */
  ArrayList& operator=(const ArrayList& rhs) {
    if (&rhs != this) {
      removeAll();
      head_ = nullptr;
      size_ = 0;

      copy(rhs);
      size_ = rhs.size_;
    }
    return *this;
  }

  /**
   * @brief Get the element at the given position.
   *
   * @param index The position to retrieve.
   * @return T The value of the element.
   */
  T operator[](const T index) { return at(index); }

  /**
   * @brief Get the size of the ArrayList.
   *
   * @return int The number of elements.
   */
  int size() const { return size_; }

  /**
   * @brief Add an element at the end.
   *
   * @param value The new element.
   */
  void push_back(const T& value) {
    if (++size_ == 1) {
      head_->node = value;
    } else {
      Data<T>* new_node = head_;
      while (new_node->next) {
        new_node = new_node->next;
      }
      new_node->next = new Data<T>(value);
    }
  }

  /**
   * @brief Delete last element.
   *
   * @return T The deleted element.
   */
  T pop_back() {
    Data<T>* pop_node = head_;
    Data<T>* pre_pop_node = head_;
    while (pop_node->next) {
      pre_pop_node = pop_node;
      pop_node = pop_node->next;
    }

    T value = pop_node->node;
    delete pop_node;
    pre_pop_node->next = nullptr;
    --size_;
    return value;
  }

  /**
   * @brief Add an element at the beginning.
   *
   * @param value The new element.
   */
  void push_front(const T& value) {
    if (++size_ == 1) {
      head_->node = value;
    } else {
      Data<T>* new_node = new Data<T>(value);
      new_node->next = head_;
      head_ = new_node;
      ++size_;
    }
  }

  /**
   * @brief Delete the first element.
   *
   * @return T The deleted element.
   */
  T pop_front() {
    T ret_value = head_->node;
    Data<T>* pop_node = head_;
    head_ = head_->next;
    delete pop_node;
    --size_;
    return ret_value;
  }

  /**
   * @brief Delete an element at the given position.
   *
   * @param index The position to be deleted.
   */
  void remove(const int index) {
    if (index > size_) {
      throw std::runtime_error("try to remove a index greatear to the size.");
    } else {
      int iter = 0;
      Data<T>* del_next = head_;
      while (del_next) {
        if (++iter == index) {
          Data<T>* deleted = del_next->next;
          del_next->next = del_next->next->next;
          delete deleted;
          break;
        }
        del_next = del_next->next;
      }

      --size_;
    }
  }

  /**
   * @brief Finds the element at the ArrayLists.
   *
   * @param value The element to find.
   * @return T The element if founded, otherwise the default type element.
   */
  T find(const int value) {
    Data<T>* find_next = head_;
    while (find_next) {
      if (find_next->node == value) {
        return find_next->node;
      }
      find_next = find_next->next;
    }

    return T();
  }

  /**
   * @brief Get the element at the given position.
   *
   * @param index The position to retrieve.
   * @return T The element.
   */
  T at(const int index) {
    if (index > size_) {
      throw std::runtime_error("index greatear to the size.");
    } else {
      int iter = 0;
      Data<T>* at_next = head_;
      while (at_next) {
        if (++iter == index) {
          return at_next->node;
        }
        at_next = at_next->next;
      }
    }

    return T();
  }

  /**
   * @brief Remove all the element of the ArrayList.
   *
   */
  void removeAll() {
    if (size_ > 0) {
      while (head_) {
        Data<T>* deleted = head_;
        head_ = head_->next;
        delete deleted;
        --size_;
      }
    }
  }

 private:
  /**
   * @brief copy all the elements the given ArrayList.
   *
   * @param other The ArrayList to be copied.
   */
  void copy(const ArrayList& other) {
    if (other.size_ > 0) {
      head_ = new Data<T>(other.head_->node);

      Data<T>* next_other = other.head_->next;
      Data<T>* next_head = head_;
      while (next_other) {
        next_head->next = new Data<T>(next_other->node);
        next_other = next_other->next;
        next_head = next_head->next;
      }
    }
  }

  Data<T>* head_;
  int size_;
};

#endif  // DATA_STRUCTURES_ARRAY_LIST_SRC_ARRAY_LIST_H_
