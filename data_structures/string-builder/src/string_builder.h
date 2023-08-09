/*
 * Copyright 2023 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#ifndef DATA_STRUCTURES_STRING_BUILDER_SRC_STRING_BUILDER_H_
#define DATA_STRUCTURES_STRING_BUILDER_SRC_STRING_BUILDER_H_

#include <inttypes.h>

#include <cstring>
#include <memory>

const uint32_t kInitSize = 8;

/**
 * @brief String builder class.
 */
class StringBuilder {
 public:
  StringBuilder()
      : string_(new char[kInitSize]), used_size_(0), size_(kInitSize) {}

  StringBuilder(const StringBuilder& other)
      : used_size_(other.used_size_), size_(other.size_) {
    string_ = new char[other.size_];
    memcpy(string_, other.string_, other.used_size_);
  }

  StringBuilder& operator=(const StringBuilder& other) {
    if (&other != this) {
      delete[] string_;
      string_ = nullptr;
      string_ = new char[other.size_];
      memcpy(string_, other.string_, other.used_size_);
      used_size_ = other.used_size_;
      size_ = other.size_;
    }
    return *this;
  }

  ~StringBuilder() {
    if (string_ != nullptr) {
      delete[] string_;
    }
  }

  /**
   * @brief Resize the string.
   *
   * @param length New length.
   */
  void Resize(size_t length) {
    if (size_ < (used_size_ + length)) {
      size_t new_size = size_ + length;
      char* new_string = new char[new_size];
      memmove(new_string, string_, used_size_);
      delete[] string_;
      string_ = new_string;
      size_ += new_size;
    }
  }

  /**
   * @brief Append a string.
   *
   * @param other String to append.
   */
  void Append(const char* other) {
    size_t other_size = strlen(other);
    if (size_ < (used_size_ + sizeof(*other))) {
      Resize(size_ * 2);
    }

    memcpy(&string_[used_size_], other, other_size);

    used_size_ += other_size;
  }

  char* Data() const { return string_; }
  size_t Size() const { return used_size_; }

 private:
  char* string_;
  size_t used_size_;
  size_t size_;
};

#endif  // DATA_STRUCTURES_STRING_BUILDER_SRC_STRING_BUILDER_H_
