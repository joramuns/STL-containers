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

  reference &front() noexcept { return head_->next_->data_; }

  reference &back() noexcept { return head_->prev_->data_; }

  /*** List iterators ***/
  iterator begin() noexcept { return iterator(head_->next_); };

  iterator end() noexcept { return iterator(head_); };
  
  const_iterator begin() const noexcept { return const_iterator(head_->next_); };

  const_iterator end() const noexcept { return const_iterator(head_); };
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
    temp->LinkNodes(pos.iter_);
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

  void swap(list &other) {
    if (this != &other) {
      Node *temp = head_;
      head_ = other.head_;
      other.head_ = temp;
      size_type temp_size = m_size_;
      m_size_ = other.m_size_;
      other.m_size_ = temp_size;
    }
  };
  void merge(list &other);

  /* void splice(const_iterator pos, list &other) { */
  void splice(const_iterator pos, list &other) {
    if (this != &other) {
      iterator non_const_pos{const_cast<Node *>(pos.iter_)};
      Node *lnode = non_const_pos.iter_->prev_;
      Node *rnode = other.begin().iter_;
      lnode->LinkOneSide(rnode);

      lnode = other.end().iter_->prev_;
      rnode = non_const_pos.iter_;
      lnode->LinkOneSide(rnode);

      m_size_ += other.size();
      other.head_->next_ = other.head_;
      other.head_->prev_ = other.head_;
      other.m_size_ = 0;
    }
  };

  void reverse() {
    iterator iter_prev = end();
    for (int i = 0; i <= m_size_; ++i) {
      SwapPrevNode(iter_prev);
      ++iter_prev;
    }
  };

  void unique();
  void sort();

 private:
  struct Node {
    Node *next_;
    Node *prev_;
    value_type data_;
    Node() : next_(this), prev_(this), data_(0) {};

    void LinkNodes(Node *pos) {
      prev_ = pos->prev_;
      next_ = prev_->next_;
      next_->prev_ = this;
      prev_->next_ = this;
    };

    void LinkOneSide(Node *other) {
      next_ = other;
      other->prev_ = this;
    }
  };
  class ListIterator {
    public:
      /* using iterator_category = std::bidirectional_iterator_tag; */
      /* using difference_type = std::ptrdiff_t; */
      /* using value_type = list::value_type; */
      /* using pointer = value_type *; */
      /* using reference = value_type &; */
      ListIterator() {};
      explicit ListIterator(Node *list_node) noexcept : iter_(list_node) {};
      ListIterator(const ListIterator& other) noexcept : iter_(other.iter_) {};
      ListIterator(ListIterator&& other) noexcept { *this = std::move(other); };
      ListIterator &operator=(const ListIterator& other) noexcept {
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

      operator ConstListIterator() const { return ConstListIterator(*this); };

      reference operator*() noexcept { return iter_->data_; }

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
        return post_decrement;
      };

      bool operator==(const iterator& other) const noexcept { return iter_ == other.iter_; }

      bool operator!=(const iterator& other) const noexcept { return iter_ != other.iter_; }

      Node *iter_;
  };
  class ConstListIterator {
    public:
      /* using iterator_category = std::bidirectional_iterator_tag; */
      /* using difference_type = std::ptrdiff_t; */
      /* using value_type = list::value_type; */
      /* using pointer = value_type *; */
      /* using reference = value_type &; */
      ConstListIterator() = delete;
      /* explicit ConstListIterator(const Node *list_node) noexcept : iter_(list_node) {}; */
      explicit ConstListIterator(const iterator &other) noexcept : iter_(other.iter_) {};
      /* operator ListIterator() const { return ListIterator(); }; */
      /* explicit ConstListIterator(const iterator&) {}; */
      /* ConstListIterator(std::initializer_list<iterator> &other) noexcept : iter_(other.iter_) {}; */
      /* explicit ConstListIterator(typename list<T>::ListIterator other) noexcept : iter_(other.iter_) {}; */
      ~ConstListIterator() noexcept {};

      value_type operator*() const noexcept { return iter_->data_; }

      const_iterator &operator++() noexcept { 
        iter_ = iter_->next_;
        return *this;
      };

      const_iterator operator++(int) noexcept { 
        const_iterator post_increment = *this;
        ++(*this);
        return post_increment;
      };

      const_iterator &operator--() noexcept {
        iter_ = iter_->prev_;
        return *this; 
      };

      const_iterator operator--(int) noexcept {
        const_iterator post_decrement = *this;
        --(*this);
        return post_decrement;
      };

      /* friend bool operator==(const const_iterator &one, const const_iterator& other)  noexcept { return one.iter_ == other.iter_; } */
      bool operator==(const const_iterator& other)  noexcept { return iter_ == other.iter_; }

      /* friend bool operator!=(const const_iterator &one, const const_iterator& other)  noexcept { return one.iter_ != other.iter_; } */
      bool operator!=(const const_iterator& other)  noexcept { return iter_ != other.iter_; }

      const Node *iter_;
  };

  void SwapPrevNode (const iterator &pos) {
    Node *target = pos.iter_;
    Node *temp = target->prev_;
    target->prev_ = target->next_;
    target->next_ = temp;
  };

  Node *head_;
  size_type m_size_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
