#ifndef CPP2_S21_CONTAINERS_0_SET_S21_SET_H_
#define CPP2_S21_CONTAINERS_0_SET_S21_SET_H_

#include <algorithm>
#include <initializer_list>

#include "../tree/s21_tree.h"

namespace s21 {
template <typename T>
class set {
  /*** Forward declaration of nested classes ***/

 public:
  using key_type = T;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using tree_type = Tree<T, T>;
  using iterator = typename tree_type::TreeIterator;
  using const_iterator = typename tree_type::ConstTreeIterator;
  using size_type = std::size_t;

  /* Set member functions */
  set(){};

  explicit set(std::initializer_list<value_type> const &items) {
    for (const auto &item : items) {
      insert(item);
    }
  };

  set(const set &s) {
    if (rb_tree_ != s.rb_tree_) {
      clear();
      delete rb_tree_;
      rb_tree_ = new tree_type(*s.rb_tree_);
    }
  };

  set(set &&s) {
    if (rb_tree_ != s.rb_tree_) {
      std::swap(rb_tree_, s.rb_tree_);
    }
  };

  ~set() { delete rb_tree_; };

  set &operator=(const set &s) {
    if (this != &s) {
      delete rb_tree_;
      rb_tree_ = new tree_type(*s.rb_tree_);
    }
    return *this;
  };

  set &operator=(set &&s) {
    if (this != &s) {
      *rb_tree_ = std::move(*s.rb_tree_);
    }
    return *this;
  };

  /* Set iterators */
  iterator begin() noexcept { return rb_tree_->begin(); };

  iterator end() noexcept { return rb_tree_->end(); };

  const_iterator begin() const noexcept { return rb_tree_->begin(); };

  const_iterator end() const noexcept { return rb_tree_->end(); };

  /* Set capacity */
  bool empty() const noexcept { return rb_tree_->Empty(); };

  size_type size() const noexcept { return rb_tree_->GetSize(); };

  size_type max_size() const noexcept;

  /* Set modifiers */
  void clear() { rb_tree_->ClearTree(); };

  std::pair<iterator, bool> insert(const value_type &value) {
    return rb_tree_->InsertNode(value);
  };

  void erase(iterator pos) { rb_tree_->DeleteNode(pos); };

  void swap(set &other) {
    if (rb_tree_ != other.rb_tree_) {
      std::swap(rb_tree_, other.rb_tree_);
    }
  };

  void merge(set &other) {
    iterator iter = other.begin();
    iterator iter_end = other.end();
    while (iter != iter_end) {
      if (!contains(*iter)) {
        iterator temp = iter;
        ++iter;
        rb_tree_->InsertNode(other.rb_tree_->ExtractNode(temp));
      } else {
        ++iter;
      }
    }
  };

  /* Set lookup */
  iterator find(const key_type &key) noexcept {
    return rb_tree_->FindKey(key);
  };

  const_iterator find(const key_type &key) const noexcept {
    return rb_tree_->FindKey(key);
  };

  bool contains(const key_type &key) const noexcept {
    return find(key) != end();
  };

 private:
  tree_type *rb_tree_ = new tree_type;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_SET_S21_SET_H_
