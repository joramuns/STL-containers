#ifndef CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // vector member function

  vector() = default;

  explicit vector(size_type n) : arr_(new value_type[n]()), sz_(n), cpct_(n){};

  explicit vector(std::initializer_list<value_type> const &items)
      : vector(items.size()) {
    std::copy(items.begin(), items.end(), arr_);
  };

  vector(const vector &v)
      : arr_(new value_type[v.sz_]), sz_(v.sz_), cpct_(v.cpct_) {
    for (size_type i = 0; i < v.sz_; ++i) {
      arr_[i] = v.arr_[i];
    }
  };

  vector(vector &&v) noexcept {
    if (this != &v) {
      swap(v);
    }
  };

  ~vector() {
    if (cpct_) {
      delete[] arr_;
      arr_ = nullptr;
      cpct_ = 0U;
      sz_ = 0U;
    }
  };

  vector &operator=(const vector &v) noexcept {
    if (this != &v) {
      vector copy(v);
      swap(copy);
    }
    return *this;
  };

  vector &operator=(vector &&v) noexcept {
    if (this != &v) {
      vector moved(std::move(v));
      swap(moved);
    }
    return *this;
  };

  // vector Elements access
  reference at(size_type pos) {
    if (pos >= sz_) {
      throw std::out_of_range("\nWrong vector position\n");
    }
    return arr_[pos];
  };

  const_reference at(size_type pos) const {
    if (pos >= sz_) {
      throw std::out_of_range("\nWrong vector position\n");
    }
    return arr_[pos];
  };

  reference operator[](size_type pos) noexcept { return arr_[pos]; };

  const_reference operator[](size_type pos) const noexcept {
    return arr_[pos];
  };

  reference front() noexcept { return arr_[0]; };

  reference back() noexcept { return arr_[sz_ - 1]; };

  const_reference front() const noexcept { return arr_[0]; };

  const_reference back() const noexcept { return arr_[sz_ - 1]; };

  iterator data() noexcept { return arr_; };

  const_iterator data() const noexcept { return arr_; };

  // vector iterators
  iterator begin() noexcept { return arr_; };

  iterator end() noexcept { return (arr_ + sz_); };

  const_iterator begin() const noexcept { return arr_; };

  const_iterator end() const noexcept { return (arr_ + sz_); };

  // vector capacity

  bool empty() const noexcept { return sz_ == 0; };

  size_type size() const noexcept { return sz_; };

  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
  };

  void reserve(size_type size) {
    if (size > cpct_) {
      value_type *temp = new value_type[size];
      std::copy_n(arr_, sz_, temp);
      delete[] arr_;
      arr_ = std::move(temp);
      cpct_ = size;
    }
  };

  size_type capacity() const noexcept { return cpct_; };

  void shrink_to_fit() {
    if (cpct_ > sz_) {
      cpct_ = sz_;
      value_type *tmp = new value_type[sz_]();
      for (size_t i = 0; i < sz_; ++i) {
        tmp[i] = arr_[i];
      }
      delete[] arr_;
      arr_ = std::move(tmp);
    }
  };

  // vector modifiers

  void clear() noexcept { sz_ = 0; };

  iterator insert(iterator pos, const_reference value) {
    iterator new_pos = pos, old_end = end();
    if (pos > old_end || pos < begin()) {
      throw std::out_of_range("\nOut of range\n");
    }
    if (++sz_ > cpct_) {
      cpct_ = cpct_ ? cpct_ * 2 : 1;
      value_type *temp = new value_type[cpct_];
      new_pos = std::copy(arr_, pos, temp);
      std::copy(pos, old_end, new_pos + 1);
      delete[] arr_;
      arr_ = temp;
    } else {
      std::copy(pos, old_end, new_pos + 1);
    }
    *new_pos = value;

    return new_pos;
  };

  void erase(iterator pos) noexcept {
    if (pos >= begin() && pos < end()) {
      iterator new_pos = pos;
      ++new_pos;
      std::copy(new_pos, end(), pos);
      --sz_;
    }
  };

  void push_back(const_reference value) { insert(end(), value); };

  void pop_back() noexcept { erase(std::prev(end())); };

  void swap(vector &other) noexcept {
    std::swap(sz_, other.sz_);
    std::swap(cpct_, other.cpct_);
    std::swap(arr_, other.arr_);
  };

  /* Bonus part */
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    iterator non_const_it = iterator(pos);
    for (auto item : {std::forward<Args>(args)...}) {
      non_const_it = insert(non_const_it, value_type{});
      *non_const_it = std::move(item);
      ++non_const_it;
    }
    return non_const_it;
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    insert_many(end(), std::forward<Args>(args)...);
  }

 private:
  value_type *arr_ = nullptr;
  size_type sz_ = 0U;
  size_type cpct_ = 0U;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_
