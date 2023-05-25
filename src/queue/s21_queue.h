#ifndef CPP2_S21_CONTAINERS_0_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_0_QUEUE_S21_QUEUE_H_

#include <initializer_list>

#include "../list/s21_list.h"

namespace s21 {
template <typename T, typename Container = list<T>>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  /*** Queue member functions ***/
  queue();
  explicit queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();
  queue &operator=(const queue &q);
  queue &operator=(queue &&q);

  /*** Queue element access ***/
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  reference front() noexcept;
  reference back() noexcept;

  /*** Queue capacity ***/
  bool empty() const noexcept;
  size_type size() const noexcept;

  /*** Queue modifiers ***/
  void push(const_reference value);
  void pop();
  void swap(queue &other) noexcept;

 private:
  Container data_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_QUEUE_S21_QUEUE_H_
