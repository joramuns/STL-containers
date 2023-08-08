#ifndef CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_

#include <algorithm>
#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  /*** Array member functions ***/
  array() = default;

  explicit array(std::initializer_list<value_type> const &items) {
    if (items.size() != N)
      throw std::invalid_argument(
          "Size of container and number of elements are not equal");
    size_type counter = 0;
    for (const auto &item : items) data_[counter++] = item;
  };

  /* There is no need in copy and move constructors as the container has a stack
   * allocated variable, which can be handled by defaulted constructors.
   * array(const array &a) noexcept { std::copy(a.begin(), a.end(), begin()); };
   *  array(array &&a) : data_(std::move(a.data_)) {}; */

  array(const array &a) = default;

  array(array &&a) = default;

  ~array() = default;

  array &operator=(const array &a) {
    if (this != &a) {
      array copy{a};
      swap(copy);
    }

    return *this;
  };

  array &operator=(array &&a) noexcept {
    if (this != &a) {
      array moved{std::move(a)};
      swap(moved);
    }

    return *this;
  };

  /*** Array element access ***/
  reference at(size_type pos) {
    if (N == 0 || pos > N - 1)
      throw std::invalid_argument("Index is out of range");
    return data_[pos];
  };

  reference operator[](size_type pos) noexcept { return data_[pos]; };

  const_reference at(size_type pos) const {
    if (pos > N - 1) throw std::invalid_argument("Index is out of range");
    return data_[pos];
  };

  const_reference operator[](size_type pos) const noexcept { return data_[pos]; };

  const_reference front() const noexcept { return data_[0]; };

  const_reference back() const noexcept { return data_[size() - 1]; };

  reference front() noexcept { return data_[0]; };

  reference back() noexcept { return data_[size() - 1]; };

  const_iterator data() const noexcept { return N ? data_ : nullptr; };

  iterator data() noexcept { return N ? data_ : nullptr; };

  /*** Array iterators ***/
  iterator begin() noexcept { return data_; };

  iterator end() noexcept { return data_ + N; };

  const_iterator begin() const noexcept { return data_; };

  const_iterator end() const noexcept { return data_ + N; };

  /*** Array capacity ***/
  bool empty() const noexcept { return begin() == end(); };

  size_type size() const noexcept { return end() - begin(); };

  size_type max_size() const noexcept { return size(); };

  /*** Array modifiers ***/
  void swap(array &other) noexcept { std::swap(data_, other.data_); };

  void fill(const_reference value) noexcept {
    std::fill(begin(), end(), value);
  };

 private:
  value_type data_[N ? N : 1] = {};
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_
