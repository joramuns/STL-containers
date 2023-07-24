#ifndef CPP2_S21_CONTAINERS_0_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_0_STACK_S21_STACK_H_

#include <initializer_list>

#include "../list/s21_list.h"

namespace s21 {
template <typename T, typename Container = list<T>>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  /*** Stack member functions ***/
  stack() = default;

  explicit stack(std::initializer_list<value_type> const &items)
      : data_(items){};

  stack(const stack &s) : data_(s.data_){};

  stack(stack &&s) noexcept { std::swap(data_, s.data_); };

  ~stack() = default;

  stack &operator=(const stack &s) {
    data_ = s.data_;

    return *this;
  };

  stack &operator=(stack &&s) noexcept {
    std::swap(data_, s.data_);

    return *this;
  };

  /*** Stack element access ***/
  const_reference top() const noexcept { return data_.back(); };

  reference top() noexcept { return data_.back(); };

  /*** Stack capacity ***/
  bool empty() const noexcept { return data_.empty(); };

  size_type size() const noexcept { return data_.size(); };

  /*** Stack modifiers ***/
  void push(const_reference value) { data_.push_back(value); };

  void pop() { data_.pop_back(); };

  void swap(stack &other) noexcept { std::swap(data_, other.data_); };

 private:
  Container data_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_STACK_S21_STACK_H_
