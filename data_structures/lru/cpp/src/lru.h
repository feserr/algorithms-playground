/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/FriendlyCodingPals/judgment-of-paris#license
 */

#ifndef LRU_H_
#define LRU_H_

#include <algorithm>
#include <list>
#include <optional>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <class T, class U>
class LRU {
 public:
  typedef typename std::pair<T, U> lru_pair_type;

  LRU() : max_capacity_(-1), elements_list_(), elements_map_() {}

  explicit LRU(const int capacity)
      : max_capacity_(capacity), elements_list_(), elements_map_() {}

  /**
   * @brief Add the key and value to the LRU
   *
   * Complexity: O(1)
   *
   * @param key The key.
   * @param value The value.
   */
  void put(const T& key, const U& value) {
    // Create a new element at the beginning of the list.
    elements_list_.emplace_front(key, value);

    // If the element exist, remove it from the map and list.
    auto element_map_iterator = elements_map_.find(key);
    if (element_map_iterator != elements_map_.end()) {
      elements_list_.erase(element_map_iterator->second);
      elements_map_.erase(element_map_iterator);
    }

    // Add the element to the hash table.
    elements_map_[key] = elements_list_.begin();

    // If the LRU is full, remove the last element of the list and its
    // key from the hash table.
    if (max_capacity_ < 0) return;

    if (elements_map_.size() == max_capacity_) {
      auto last_element_list = elements_list_.end();
      --last_element_list;

      elements_map_.erase(last_element_list->first);
      elements_list_.pop_back();
    }
  }

  /**
   * @brief Get the value from the key if exist.
   *
   * @param key The key.
   * @return optional<lru_pair_type> The value if exist.
   */
  optional<U> get(const T& key) {
    auto element_map_iterator = elements_map_.find(key);
    if (element_map_iterator == elements_map_.end()) {
      return {};
    }

    return element_map_iterator->second->second;
  }

  /**
   * @brief Get the all the elements from the LRU.
   *
   * @return vector<lru_pair_type> The elements.
   */
  vector<lru_pair_type> getAll() {
    vector<lru_pair_type> elements(elements_list_.size());

    copy(elements_list_.begin(), elements_list_.end(), elements.begin());

    return elements;
  }

 private:
  typedef typename std::list<lru_pair_type>::iterator element_list_iterator_;

  int max_capacity_;
  list<lru_pair_type> elements_list_;
  unordered_map<T, element_list_iterator_> elements_map_;
};

#endif  // LRU_H_
