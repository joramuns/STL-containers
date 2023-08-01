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
  array() noexcept {};

  explicit array(std::initializer_list<value_type> const &items) {
    if (items.size() != N)
      throw std::invalid_argument(
          "Size of container and number of elements are not equal");
    size_type counter = 0;
    for (const auto &item : items) data_[counter++] = item;
  };

  array(const array &a) {
    size_type a_size = a.size();
    for (size_type i = 0; i != a_size; ++i) data_[i] = a.data_[i];
  };

  array(array &&a) noexcept { std::swap(data_, a.data_); };

  ~array() noexcept {};

  array &operator=(const array &a) {
    size_type a_size = a.size();
    for (size_type i = 0; i != a_size; ++i) data_[i] = a.data_[i];

    return *this;
  };

  array &operator=(array &&a) noexcept {
    std::swap(data_, a.data_);

    return *this;
  };

  /*** Array element access ***/
  reference at(size_type pos) {
    if (pos > N - 1 || N == 0) throw std::invalid_argument("Index is out of range");
    return data_[pos];
  };

  reference operator[](size_type pos) noexcept { return data_[pos]; };

  const_reference at(size_type pos) const {
    if (pos > N - 1) throw std::invalid_argument("Index is out of range");
    return data_[pos];
  };

  const_reference operator[](size_type pos) const { return at(pos); };

  const_reference front() const noexcept { return data_[0]; };

  const_reference back() const noexcept { return data_[size() - 1]; };

  reference front() noexcept { return data_[0]; };

  reference back() noexcept { return data_[size() - 1]; };

  const_iterator data() const noexcept { return data_; };

  iterator data() noexcept { return data_; };

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
  value_type data_[N + 1] = {};
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_
