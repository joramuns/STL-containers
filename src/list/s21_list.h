#ifndef CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_

#include <initializer_list>
#include <limits>

#include "s21_listiterator.h"

namespace s21 {
template <typename T>
class list {
 public:
  /*** List member types ***/
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator<T>;
  using const_iterator = ConstListIterator<T>;
  using size_type = std::size_t;

  /*** List functions ***/
  list();
  explicit list(size_type n);
  explicit list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list<T> operator=(const list<T> &l);
  list<T> operator=(list &&l);

  /*** List element access ***/
  const_reference front();
  const_reference back();

  /*** List iterators ***/
  iterator begin();
  iterator end();

  /*** List capacity ***/
  bool empty();
  size_type size();
  size_type max_size();

  /*** List modifiers ***/
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

 private:
  list<T> *next_;
  list<T> *prev_;
  value_type value_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
