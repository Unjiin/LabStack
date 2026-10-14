#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
class TStack {
 public:
  [[nodiscard]] bool empty() const noexcept { return data_.empty(); }
  [[nodiscard]] std::size_t size() const noexcept { return data_.size(); }

  void push(const T& value) { data_.push_back(value); }
  void push(T&& value) { data_.push_back(std::move(value)); }

  T pop() {
    if (empty()) {
      throw std::out_of_range("stack is empty");
    }
    T value = std::move(data_.back());
    data_.pop_back();
    return value;
  }

  T& top() {
    if (empty()) {
      throw std::out_of_range("stack is empty");
    }
    return data_.back();
  }

  const T& top() const {
    if (empty()) {
      throw std::out_of_range("stack is empty");
    }
    return data_.back();
  }

  void clear() noexcept { data_.clear(); }

 private:
  std::vector<T> data_;
};
