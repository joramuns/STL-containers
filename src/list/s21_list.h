#ifndef CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_

#include <initializer_list>
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
    while (m_size_) {
      pop_back();
    }
    delete head_;
    head_ = nullptr;
  };

  list<value_type> operator=(const list<T> &l);

  list<value_type> operator=(list &&l);

  /*** List element access ***/
  const_reference front() { return head_->next_->data_; };

  const_reference back() { return head_->prev_->data_; };

  /*** List iterators ***/
  iterator begin() { return iterator(head_->next_); };

  iterator end() { return iterator(head_); };

  /*** List capacity ***/
  bool empty() { return head_->next_ == head_->back_; };

  size_type size() { return m_size_; };

  size_type max_size();

  /*** List modifiers ***/
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);

  void push_back(const_reference value) {
    Node *temp = new Node;
    temp->data_ = value;
    temp->prev_ = head_->prev_;
    temp->next_ = temp->prev_->next_;
    temp->next_->prev_ = temp;
    temp->prev_->next_ = temp;
    ++m_size_;
  };

  void pop_back() {
    Node *temp = head_->prev_;
    temp->prev_->next_ = head_;
    head_->prev_ = temp->prev_;
    --m_size_;
    delete temp;
  };

  void push_front(const_reference value) {
    Node *temp = new Node;
    temp->data_ = value;
    temp->next_ = head_->next_;
    temp->prev_ = temp->next_->prev_;
    temp->next_->prev_ = temp;
    temp->prev_->next_ = temp;
    ++m_size_;
  };

  void pop_front() {
    Node *temp = head_->next_;
    temp->next_->prev_ = head_;
    head_->next_ = temp->next_;
    --m_size_;
    delete temp;
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
      ListIterator() : iter_(0) {};
      explicit ListIterator(Node *list_node) : iter_(list_node) {};
      ListIterator(const ListIterator& other) : iter_(other.iter_) {};
      ListIterator(ListIterator&& other) { *this = std::move(other); };
      ListIterator operator=(const ListIterator& other) {
        if (*this != other)
          iter_ = other.iter_;
        return *this; 
      };
      ListIterator operator=(ListIterator&& other) {
        if (*this != other)
          *this = std::move(other);
        return *this; 
      };
      ~ListIterator() {};

      value_type operator*() { return iter_->data_; }

      iterator &operator++() { 
        iter_ = iter_->next_;
        return *this;
      };

      iterator operator++(int) { 
        iterator post_increment = *this;
        ++(*this);
        return post_increment;
      };

      iterator &operator--() {
        iter_ = iter_->prev_;
        return *this; 
      };

      iterator operator--(int) {
        iterator post_decrement = *this;
        --(*this);
        return *this;
      };

      bool operator==(const iterator& other) { return iter_ == other.iter_; }

      bool operator!=(const iterator& other) { return iter_ != other.iter_; }

    private:
      Node *iter_;
  };
  class ConstListIterator {
  };
  Node *head_;
  size_type m_size_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
