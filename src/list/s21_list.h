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
  list() : head_(new node) {};

  explicit list(size_type n) : list() {
    while (--n > 0U) {
      push_back(0);
    }
  };

  explicit list(std::initializer_list<value_type> const &items)
      : list() {
    for (auto &item : items) push_back(item);
  };

  list(const list &l);

  list(list &&l);

  ~list() {
    while (head_->data_) {
      pop_back();
    }
    delete head_;
    head_ = nullptr;
  };

  list<value_type> operator=(const list<T> &l);

  list<value_type> operator=(list &&l);

  /*** List element access ***/
  const_reference front() { return head_->next_->value_; };

  const_reference back() { return head_->prev_->value_; };

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
  void push_back(const_reference value) {
    node *temp = new node;
    temp->prev_ = head_->prev_;
    temp->next_ = head_;
    temp->value_ = value;
    head_->prev_ = temp;
    ++head_->data_;
  };
  void pop_back() {
    node *temp = head_->prev_;
    temp->prev_->next_ = head_;
    head_->prev_ = temp->prev_;
    delete temp;
  }
  void push_front(const_reference value) {
    node *temp = new node;
    temp->next_ = head_->next_;
    temp->prev_ = head_;
    temp->value_ = value;
    head_->next_ = temp;
    ++head_->data_;
  };
  void pop_front() {
    node *temp = head_->next_;
    delete head_;
    head_ = temp;
  };
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

 private:
  struct node {
    node *next_ = nullptr;
    node *prev_ = nullptr;
    T data_ = 0;
    value_type value_;
    node() : next_(this), prev_(this) {};
  };
  node *head_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
