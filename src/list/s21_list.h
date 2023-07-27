#ifndef CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_

#include <exception>
#include <initializer_list>
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
  list() : head_(new Node){};

  explicit list(size_type n) : list() {
    while (n--) {
      push_back({});
    }
  };

  explicit list(std::initializer_list<value_type> const &items) : list() {
    for (const auto &item : items) push_back(item);
  };

  list(const list &l) : list() {
    for (const auto &item : l) push_back(item);
  };

  list(list &&l) : list() { swap(l); };

  ~list() {
    clear();
    delete head_;
    head_ = nullptr;
  };

  list &operator=(const list &l) {
    if (this != &l) {
      clear();
      for (const auto &item : l) push_back(item);
    }

    return *this;
  };

  list &operator=(list &&l) {
    if (this != &l) {
      swap(l);
    }

    return *this;
  };

  /*** List element access ***/
  const_reference front() const noexcept { return head_->next_->data_; };

  const_reference back() const noexcept { return head_->prev_->data_; };

  reference front() noexcept { return head_->next_->data_; }

  reference back() noexcept { return head_->prev_->data_; }

  /*** List iterators ***/
  iterator begin() noexcept { return iterator(head_->next_); };

  iterator end() noexcept { return iterator(head_); };

  const_iterator begin() const noexcept {
    return const_iterator(head_->next_);
  };

  const_iterator end() const noexcept { return const_iterator(head_); };

  /*** List capacity ***/
  bool empty() const noexcept { return m_size_ == 0; };

  size_type size() const noexcept { return m_size_; };

  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
  };

  /*** List modifiers ***/
  void clear() {
    while (m_size_) erase(begin());
  };

  iterator insert(iterator pos, const_reference value) {
    Node *temp = new Node(value);
    temp->LinkNodes(pos.GetNode());
    ++m_size_;

    return iterator(temp);
  };

  void erase(iterator pos) noexcept {
    if (pos != end()) {
      Node *temp = pos.GetNode();
      temp->ExtractNode();
      --m_size_;
      delete temp;
    }
  };

  void push_back(const_reference value) { insert(end(), value); };

  void pop_back() { erase(--end()); };

  void push_front(const_reference value) { insert(begin(), value); };

  void pop_front() { erase(begin()); };

  void swap(list &other) noexcept {
    if (this != &other) {
      std::swap(head_, other.head_);
      std::swap(m_size_, other.m_size_);
    }
  };

  void merge(list &other) noexcept {
    if (this != &other) {
      iterator this_pos = begin();
      iterator this_end = end();
      iterator other_pos = other.begin();
      iterator other_end = other.end();
      while (other_pos != other_end) {
        while (*other_pos >= *this_pos && this_pos != this_end) {
          ++this_pos;
        }
        iterator move_pos = other_pos;
        ++other_pos;
        move_pos.GetNode()->ExtractNode();
        move_pos.GetNode()->LinkNodes(this_pos.GetNode());
        ++m_size_;
        --other.m_size_;
      }
    }
  };

  void splice(const_iterator pos, list &other) noexcept {
    if (this != &other) {
      iterator non_const_pos{const_cast<Node *>(pos.GetNode())};
      Node *lnode = non_const_pos.GetNode()->prev_;
      Node *rnode = other.begin().GetNode();
      lnode->LinkOneSide(rnode);

      lnode = other.end().GetNode()->prev_;
      rnode = non_const_pos.GetNode();
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

  void unique() {
    iterator pos = begin();
    iterator prev_pos = pos;
    ++pos;
    iterator end_pos = end();
    while (pos != end_pos) {
      if (*pos == *prev_pos) {
        iterator del_pos = pos;
        ++pos;
        erase(del_pos);
      } else {
        ++pos;
        ++prev_pos;
      }
    }
  };
  void sort() {
    if (m_size_ > 1) {
      head_->next_->MergeSort(&(head_->next_), head_);
    }
  };

 private:
  struct Node {
    Node *next_;
    Node *prev_;
    value_type data_{};
    Node() : next_(this), prev_(this){};
    explicit Node(value_type value) : next_(this), prev_(this), data_(value){};

    void MergeSort(Node **sort_head, Node *tail) {
      /* Break recursion in case of empty or one element in list */
      if (*sort_head == tail || (*sort_head)->next_ == tail) {
        return;
      }
      Node *a = nullptr;
      Node *b = nullptr;
      /* Split whole list into two halves */
      SplitList(*sort_head, &a, &b, tail);
      /* Recursively sort every half */
      MergeSort(&a, tail);
      MergeSort(&b, tail);

      /* Merge sorted pieces of list back */
      *sort_head = MergeBack(a, b, tail);
    }

    void SplitList(Node *sort_head, Node **a, Node **b, Node *tail) {
      Node *fast = sort_head->next_;
      Node *slow = sort_head;
      while (fast != tail) {
        fast = fast->next_;
        if (fast != tail) {
          fast = fast->next_;
          slow = slow->next_;
        }
      }
      *a = sort_head;
      *b = slow->next_;
      slow->next_ = tail;
    }

    Node *MergeBack(Node *a, Node *b, Node *tail) {
      Node *result = nullptr;
      if (a == tail) {
        return b;
      } else if (b == tail) {
        return a;
      }
      if (a->data_ <= b->data_) {
        result = a;
        result->next_ = MergeBack(a->next_, b, tail);
      } else {
        result = b;
        result->next_ = MergeBack(a, b->next_, tail);
      }
      result->prev_ = tail;
      result->next_->prev_ = result;

      return result;
    }

    void LinkNodes(Node *pos) {
      prev_ = pos->prev_;
      next_ = prev_->next_;
      next_->prev_ = this;
      prev_->next_ = this;
    };

    void LinkOneSide(Node *other) {
      next_ = other;
      other->prev_ = this;
    };

    void ExtractNode() {
      prev_->next_ = next_;
      next_->prev_ = prev_;
    };
  };

  class ListIterator {
   public:
    /* using iterator_category = std::bidirectional_iterator_tag; */
    /* using difference_type = std::ptrdiff_t; */
    /* using value_type = list::value_type; */
    /* using pointer = value_type *; */
    /* using reference = value_type &; */
    ListIterator() = default;
    explicit ListIterator(Node *list_node) noexcept : iter_(list_node){};

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

    bool operator==(const iterator &other) const noexcept {
      return iter_ == other.iter_;
    }

    bool operator!=(const iterator &other) const noexcept {
      return iter_ != other.iter_;
    }

    Node *GetNode() const noexcept { return iter_; }

   private:
    Node *iter_ = nullptr;
  };

  class ConstListIterator {
   public:
    /* using iterator_category = std::bidirectional_iterator_tag; */
    /* using difference_type = std::ptrdiff_t; */
    /* using value_type = list::value_type; */
    /* using pointer = value_type *; */
    /* using reference = value_type &; */
    ConstListIterator() = default;
    explicit ConstListIterator(const Node *list_node) noexcept
        : iter_(list_node){};
    explicit ConstListIterator(const iterator &other) noexcept
        : iter_(other.GetNode()){};

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

    bool operator==(const const_iterator &other) noexcept {
      return iter_ == other.iter_;
    }

    bool operator!=(const const_iterator &other) noexcept {
      return iter_ != other.iter_;
    }

    const Node *GetNode() const noexcept { return iter_; }

   private:
    const Node *iter_ = nullptr;
  };

  void SwapPrevNode(const iterator &pos) {
    Node *target = pos.GetNode();
    Node *temp = target->prev_;
    target->prev_ = target->next_;
    target->next_ = temp;
  };

  Node *head_;
  size_type m_size_ = 0;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_LIST_S21_LIST_H_
