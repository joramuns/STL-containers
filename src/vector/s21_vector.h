#ifndef CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T> class vector {
public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = std::size_t;

  // vector member function

  vector() : sz_(0), cpct_(0){};

  explicit vector(size_type n) : sz_(n), cpct_(n) {
    InitVector();
    for (size_type i = 0; i < n; ++i) {
      arr_[i] = 0;
    }
  };

  explicit vector(std::initializer_list<value_type> const &items)
      : sz_(0), cpct_(0) {
    InitVector();
    for (const auto &item : items) {
      push_back(item);
    }
  };

  vector(const vector &v) {
    sz_ = v.sz_;
    cpct_ = v.cpct_;
    InitVector();
    CopyArr(v);
  };

  vector(vector &&v) : sz_(std::move(v.sz_)), cpct_(std::move(v.cpct_)), arr_(std::move(v.arr_)){};

  ~vector() {
    delete[] arr_;
    sz_ = 0;
    cpct_ = 0;
    arr_ = nullptr;
  };

  vector operator=(vector &&v) noexcept {
    if (this != &v) {
      delete[] arr_;

      sz_ = v.sz_;
      cpct_ = v.cpct_;
      CopyArr(v);

      v.sz_ = 0;
      v.cpct_ = 0;
      v.arr_ = nullptr;
    }
    return *this;
  };

  // vector Elements access
  reference at(size_type pos){
    if (sz_ > pos) {
      throw std::invalid_argument("\nWrong vector position\n");
    }
    return arr_[pos];
  };

  reference operator[](size_type pos) { return arr_[pos]; };

  const_reference front() const { return arr_[0]; };

  const_reference back() const { return arr_[sz_ - 1]; };

  T *data() noexcept {

  };

  // vector iterators
  iterator begin() noexcept { return arr_; };

  iterator end() noexcept {
    iterator tmp = arr_;
    return (tmp + sz_);
  };

  // vector capacity

  bool empty() const noexcept { return sz_ == 0 ? 1 : 0; };

  size_type size() const noexcept { return sz_; };

  size_type max_size() const noexcept { return 0; };

  void reserve(size_type size){

  };

  size_type capacity() const noexcept { return cpct_; };

  void shrink_to_fit(){

  };

  // vector modifiers

  void clear() noexcept {

  };

  iterator insert(iterator pos, const_reference value) {
    *(++pos) = value;
    return pos;
  };

  // void erase(iterator pos){

  // };

  void push_back(const_reference value) {
    ++sz_;
    if (sz_ >= cpct_) {
      vector tmp = *this;
      this->~vector();
      sz_ = tmp.sz_;
      cpct_ = 2 * sz_;
      InitVector();
      CopyArr(tmp);
    }
    arr_[sz_ - 1] = value;
  };

  void pop_back() { erase(end()); };

  void swap(vector &other) noexcept {

  };

private:
  T *arr_;
  size_type sz_;
  size_type cpct_;

  void InitVector() { arr_ = new T[cpct_](); };

  void CopyArr(const vector &other) noexcept {
    for (size_type i = 0; i < other.sz_; ++i) {
      arr_[i] = other.arr_[i];
    }
  };
};
} // namespace s21

#endif // CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_
