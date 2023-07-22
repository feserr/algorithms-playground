/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef DATA_STRUCTURES_HASH_TABLE_SRC_HASH_TABLE_H_
#define DATA_STRUCTURES_HASH_TABLE_SRC_HASH_TABLE_H_

#include <stdlib.h>
#include <vector>

const int kSize = 100;

template <class T>
class HashData {
 public:
  HashData() : key(0), value(T()), size_(0) {}
  explicit HashData(int k, T v) : key(k), value(v), size_(0) {}

  int Size() const { return size_; }
  void IncressSize() { ++size_; }
  void DecressSize() { --size_; }

  int key;
  T value;

 private:
  int size_;
};

template <class T>
class HashTable {
 public:
  HashTable() {
    data = new HashData<T>*[kSize];
    for (int i = 0; i < kSize; i++) {
      data[i] = nullptr;
    }
  }

  ~HashTable() {
    for (int iter = 0; iter < kSize; ++iter) {
      if (data[iter] != nullptr) {
        if (data[iter]->Size() > 1) {
          delete[] data[iter];
        } else {
          delete data[iter];
        }
      }
    }
    delete[] data;
  }

  T operator[](const T value) { return FindValue(value); }

  int Hash(const T value) { return value % kSize; }

  void Insert(const T value) {
    int key = Hash(value);

    if (data[key] == nullptr) {
      data[key] = new HashData<T>(key, value);
      data[key]->IncressSize();
    } else {
      HashData<T>* data_aux = new HashData<T>[data[key]->Size()];
      int iter = 0;
      for (; iter < data[key]->Size(); ++iter) {
        data_aux[iter] =
            HashData<T>(data[key][iter].key, data[key][iter].value);
        data_aux[0].IncressSize();
      }
      data_aux[iter] = HashData<T>(key, value);
      data_aux[0].IncressSize();

      if (data[key]->Size() > 1) {
        delete[] data[key];
      } else {
        delete data[key];
      }

      data[key] = new HashData<T>[data_aux[key].Size()];
      data[key] = data_aux;
    }
  }

  void Remove(const T value) {
    int key = Hash(value);

    for (size_t iter = 0; iter < data[key]->Size(); ++iter) {
      if (data[key][iter].value == value) {
        if (iter < data[key]->Size()) {
          for (size_t current_iter = iter; current_iter < data[key]->Size() - 1;
               ++current_iter) {
            data[key][current_iter] = data[key][current_iter + 1];
          }
        } else {
          data[key][iter].value = T();
        }
        data[key]->DecressSize();
        break;
      }
    }
  }

 private:
  T FindValue(const T value) {
    int key = Hash(value);

    for (int iter = 0; iter < data[key]->Size(); ++iter) {
      if (data[key][iter].value == value) {
        return data[key][iter].value;
      }
    }

    return T();
  }

 private:
  HashData<T>** data;
};

#endif  // DATA_STRUCTURES_HASH_TABLE_SRC_HASH_TABLE_H_
