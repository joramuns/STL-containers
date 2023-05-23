#ifndef CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_

#include <initializer_list>
#include <exception>
#include <iostream>
#include <iterator>
#include <limits>

namespace s21 {
template <typename T>
class list {
  /*** Forward declaration of nested classes ***/
  class ListIterator;
  class ConstListIterator;
 public:
  /*** List member types ***/
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator;
  using const_iterator = ConstListIterator;
  using size_type = std::size_t;

  /*** List functions ***/
  list() : head_(new Node), m_size_(0) {};

  explicit list(size_type n) : list() {
    while (n--) {
      push_back(0);
    }
  };

  explicit list(std::initializer_list<value_type> const &items)
      : list() {
    for (auto &item : items) push_back(item);
  };

  list(const list &l) : list() {
    for (const auto& item : l)
      push_back(item);
  };

  list(list &&l) : list() {
    std::swap(head_, l.head_);
    std::swap(m_size_, l.m_size_);
  };

  ~list() {
    clear();
    delete head_;
    head_ = nullptr;
  };

  list &operator=(const list &l) {
    if (this != &l) {
      clear();
      m_size_ = 0;
      for (const auto& item : l)
        push_back(item);
    }

    return *this;
  };

  list &operator=(list &&l) {
    if (this != &l) {
      std::swap(head_, l.head_);
      std::swap(m_size_, l.m_size_);
    }

    return *this;
  };

  /*** List element access ***/
  const_reference front() const noexcept { return head_->next_->data_; };

  const_reference back() const noexcept { return head_->prev_->data_; };

  /*** List iterators ***/
  iterator begin() const noexcept { return iterator(head_->next_); };

  iterator end() const noexcept { return iterator(head_); };

  /*** List capacity ***/
  bool empty() const noexcept { return m_size_ == 0; };

  size_type size() const noexcept { return m_size_; };

  size_type max_size();

  /*** List modifiers ***/
  void clear() {
    while (m_size_)
      erase(begin());
  };

  iterator insert(iterator pos, const_reference value) {
    Node *temp = new Node;
    temp->data_ = value;
    temp->prev_ = pos.iter_->prev_;
    temp->next_ = temp->prev_->next_;
    temp->next_->prev_ = temp;
    temp->prev_->next_ = temp;
    ++m_size_;

    return iterator(temp);
  };

  void erase(iterator pos) {
    if (pos == end())
      throw std::invalid_argument("Container is empty or trying to erase end iterator");
    Node *temp = pos.iter_;
    temp->prev_->next_ = temp->next_;
    temp->next_->prev_ = temp->prev_;
    --m_size_;
    delete temp;
  };

  void push_back(const_reference value) {
    insert(end(), value);
  };

  void pop_back() {
    erase(--end());
  };

  void push_front(const_reference value) {
    insert(begin(), value);
  };

  void pop_front() {
    erase(begin());
  };

  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

 private:
  struct Node {
    Node *next_;
    Node *prev_;
    value_type data_;
    Node() : next_(this), prev_(this), data_(0) {};
  };
  class ListIterator {
    public:
      /* using iterator_category = std::bidirectional_iterator_tag; */
      /* using difference_type = std::ptrdiff_t; */
      /* using value_type = list::value_type; */
      /* using pointer = value_type *; */
      /* using reference = value_type &; */
      ListIterator() = delete;
      explicit ListIterator(Node *list_node) noexcept : iter_(list_node) {};
      ListIterator(const ListIterator& other) noexcept : iter_(other.iter_) {};
      ListIterator(ListIterator&& other) noexcept { *this = std::move(other); };
      ListIterator operator=(const ListIterator& other) noexcept {
        if (*this != other)
          iter_ = other.iter_;
        return *this; 
      };
      ListIterator operator=(ListIterator&& other) noexcept {
        if (*this != other)
          *this = std::move(other);
        return *this; 
      };
      ~ListIterator() noexcept {};

      value_type operator*() const noexcept { return iter_->data_; }

      iterator &operator++() noexcept { 
        iter_ = iter_->next_;
        return *this;
      };

      iterator operator++(int) noexcept { 
        iterator post_increment = *this;
        ++(*this);
        return post_increment;
      };

      iterator &operator--() noexcept {
        iter_ = iter_->prev_;
        return *this; 
      };

      iterator operator--(int) noexcept {
        iterator post_decrement = *this;
        --(*this);
        return *this;
      };

      bool operator==(const iterator& other) const noexcept { return iter_ == other.iter_; }

      bool operator!=(const iterator& other) const noexcept { return iter_ != other.iter_; }

      Node *iter_;
  };
  class ConstListIterator {
  };
  Node *head_;
  size_type m_size_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
