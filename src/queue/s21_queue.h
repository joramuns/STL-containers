#ifndef CPP2_S21_CONTAINERS_0_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_0_QUEUE_S21_QUEUE_H_

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
  queue() = default;

  explicit queue(std::initializer_list<value_type> const &items)
      : data_{items} {};

  queue(const queue &q) : data_{q.data_} {};

  queue(queue &&q) : data_{std::move(q.data_)} {};

  ~queue() = default;

  queue &operator=(const queue &q) {
    if (this != &q) {
      queue copy{q};
      swap(copy);
    }

    return *this;
  };

  queue &operator=(queue &&q) noexcept {
    if (this != &q) {
      queue moved{std::move(q)};
      swap(moved);
    }

    return *this;
  };

  /*** Queue element access ***/
  const_reference front() const noexcept { return data_.front(); };

  const_reference back() const noexcept { return data_.back(); };

  reference front() noexcept { return data_.front(); };

  reference back() noexcept { return data_.back(); };

  /*** Queue capacity ***/
  bool empty() const noexcept { return data_.empty(); };

  size_type size() const noexcept { return data_.size(); };

  /*** Queue modifiers ***/
  void push(const_reference value) { data_.push_back(value); };

  void pop() noexcept { data_.pop_front(); };

  void swap(queue &other) noexcept { std::swap(data_, other.data_); };

  /* Bonus part */
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    data_.insert_many_back(std::forward<Args>(args)...);
  }

 private:
  Container data_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_QUEUE_S21_QUEUE_H_
