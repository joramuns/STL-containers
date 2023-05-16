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
  list() : head_(new node<value_type>), tail_(head_) { push_back(0); };

  explicit list(size_type n) : head_(new node<T>), tail_(head_) {
    while (--n > 0U) {
      push_back(0);
    }
  };

  explicit list(std::initializer_list<value_type> const &items)
      : head_(new node<value_type>), tail_(head_) {
    for (auto &item : items) push_back(item);
    pop_front();
  };

  list(const list &l);

  list(list &&l);

  ~list() {
    while (head_ != tail_) {
      pop_back();
    }
    delete head_;
  };

  list<value_type> operator=(const list<T> &l);

  list<value_type> operator=(list &&l);

  /*** List element access ***/
  const_reference front() { return head_->value_; };

  const_reference back() { return tail_->value_; };

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
    node<value_type> *temp = new node<value_type>;
    temp->prev_ = tail_;
    tail_->next_ = temp;
    temp->value_ = value;
    tail_ = temp;
  };
  void pop_back() {
    node<value_type> *temp = tail_->prev_;
    delete tail_;
    tail_ = temp;
  }
  void push_front(const_reference value) {
    node<value_type> *temp = new node<value_type>;
    temp->next_ = head_;
    head_->prev_ = temp;
    temp->value_ = value;
    head_ = temp;
  };
  void pop_front() {
    node<value_type> *temp = head_->next_;
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
  template <typename>
  struct node {
    node<value_type> *next_ = nullptr;
    node<value_type> *prev_ = nullptr;
    T data_ = 0;
    value_type value_;
  };
  node<value_type> *head_;
  node<value_type> *tail_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
