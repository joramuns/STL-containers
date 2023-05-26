#ifndef CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_

#include <initializer_list>
#include <algorithm>
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
      throw std::invalid_argument("Size of container and number of elements are not equal");
    size_type counter = 0;
    for (const auto& item : items) data_[counter++] = item;
  };

  array(const array &a);

  array(array &&a) noexcept;

  ~array() noexcept {};

  array &operator=(const array &a);

  array &operator=(array &&a) noexcept;

  /*** Array element access ***/
  reference at(size_type pos) {
    if (pos > N - 1)
      throw std::invalid_argument("Index is out of range");
    return data_[pos];
  };

  reference operator[](size_type pos) {
    return at(pos);
  };

  const_reference front() const noexcept;
  const_reference back() const noexcept;
  reference front() noexcept;
  reference back() noexcept;
  iterator data() const noexcept;
  
  /*** Array iterators ***/
  iterator begin() noexcept { return data_; };

  iterator end() noexcept { return data_ + N; };
  
  const_iterator begin() const noexcept { return data_; };

  const_iterator end() const noexcept { return data_ + N; };

  /*** Array capacity ***/
  bool empty() const noexcept { return begin() == end(); };

  size_type size() const noexcept { return end() - begin(); };

  size_type max_size() const noexcept;

  /*** Array modifiers ***/
  void swap(array &other) noexcept { 
    std::swap(data_, other.data_);
  };

  void fill(const_reference value) noexcept { std::fill(begin(), end(), value); };

 private:
  value_type data_[N] = {};
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_
