#ifndef CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_

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

  vector(){

  };

  vector(size_type n){

  };

  vector(std::initializer_list<value_type> const &items){

  };

  vector(const &v){

  };

  vector(vector &&v){

  };

  ~vector(){

  };

  operator=(vector &&v){

  };

  // vector Elements access
  reference at(size_type pos){

  };

  reference operator[](size_type pos){

  };

  const_reference front(){

  };

  const_reference back(){

  };

  T *data(){

  };

  // vector iterators
  iterator begin(){

  };

  iterator end(){

  };

  // vector capacity

  bool empty(){

  };

  size_type size(){

  };

  size_type max_size(){

  };

  void reserve(size_type size){

  } :

      size_type capacity(){

      };

  void shrink_to_fit(){

  };

  // vector modifiers

  void clear(){

  };

  iterator insert(iterator pos, const_reference value){

  };

  void erase(iterator pos){

  };

  void push_back(const_reference value){

  };

  void pop_back(){

  };

  void swap(vector &other){

  };

private:
  T *arr : size_type sz;
  size_type cpct;
};
} // namespace s21

#endif // CPP2_S21_CONTAINERS_0_VECTOR_S21_VECTOR_H_
