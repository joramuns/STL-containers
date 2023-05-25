#ifndef CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T> class vector {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const reference;
  using iterator = T *;
  using const_iterator = const iterator;
  using size_type = std::size_t;

  // vector member function

  vector() : sz_(1), cpct_(1) { InitVector(); };

  explicit vector(size_type n) : sz_(n), cpct_(n) {
    InitVector();
    while (n--) {
      push_back(0);
    }
  };

  explicit vector(std::initializer_list<value_type> const &items) {
    for (const auto &item : items) {
      push_back(item);
    }
  };

  vector(const vector &v){
		sz_ = v.sz_;
		cpct_ = v.cpct_;
		InitVector();
		CopyArr(v);
  };

  vector(vector &&v) : vector() {
		std::swap(sz_, v.sz_);
		std::swap(cpct_, v.cpct_);
		InitVector();
		std::swap(arr_, v.arr_);
  };

  ~vector() {
    delete[] arr_;
    sz_ = 0;
    cpct_ = 0;
		arr_ = nullptr;
  };

  operator=(vector &&v) noexcept {

  };

  // vector Elements access
  reference at(size_type pos){

  };

  reference operator[](size_type pos){

  };

  const_reference front() const {

  };

  const_reference back() const {

  };

  T *data() noexcept {

  };

  // vector iterators
  iterator begin() noexcept {

  };

  iterator end() noexcept {

  };

  // vector capacity

  bool empty() const noexcept {

  };

  size_type size() const noexcept {

  };

  size_type max_size() const noexcept {

  };

  void reserve(size_type size){

  };

  size_type capacity() const noexcept {

  };

  void shrink_to_fit(){

  };

  // vector modifiers

  void clear() noexcept {

  };

  iterator insert(iterator pos, const_reference value){

  };

  void erase(iterator pos){

  };

  void push_back(const_reference value) {
    ++sz_;
    if (sz_ == cpct_) {
      vector tmp = this;
      this->~vector();
      sz_ = tmp.sz_;
      cpct_ = 2 * sz_;
      InitVector();
      CopyArr(tmp);
    }
    arr_[sz_ - 1] = value;
  };

  void pop_back(){

  };

  void swap(vector &other) noexcept {

  };

private:
  T *arr_;
  size_type sz_;
  size_type cpct_;

  void InitVector() { arr = new T[cpct_](); };

  void CopyArr(const vector &other) noexcept {
    for (size_type i = 0; i < other.sz_; ++i) {
      arr_[i] = other.arr_[i];
    }
  };
};
} // namespace s21

#endif // CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_
