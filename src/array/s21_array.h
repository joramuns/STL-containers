#ifndef CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_

#include <initializer_list>

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
  array();
  explicit array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a) noexcept;
  ~array() noexcept;
  array &operator=(const array &a);
  array &operator=(array &&a) noexcept;

  /*** Array element access ***/
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  reference front() noexcept;
  reference back() noexcept;
  iterator data() const noexcept;
  
  /*** Array iterators ***/
  iterator begin() const noexcept;
  iterator end() const noexcept;

  /*** Array capacity ***/
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  /*** Array modifiers ***/
  void swap(array &other) noexcept;
  void fill(const_reference value) noexcept;

 private:
  value_type *data_;
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_0_ARRAY_S21_ARRAY_H_
