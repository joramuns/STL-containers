#ifndef CPP2_S21_CONTAINERS_0_MULTISET_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_0_MULTISET_S21_MULTISET_H_

#include "../tree/s21_tree.h"

namespace s21 {
template <typename Key>
class multiset {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using tree_type = Tree<Key, Key>;
  using iterator = typename tree_type::TreeIterator;
  using const_iterator = typename tree_type::ConstTreeIterator;
  using size_type = std::size_t;

  /*** Multiset member functions ***/
  multiset() = default;

  explicit multiset(std::initializer_list<value_type> const &items) {
    for (const auto &item : items) {
      rb_tree_->MultiInsertNode(item);
    }
  };

  multiset(const multiset &ms) {
    if (rb_tree_ != ms.rb_tree_) {
      clear();
      delete rb_tree_;
      rb_tree_ = new tree_type(*ms.rb_tree_);
    }
  };

  multiset(multiset &&ms) {
    if (rb_tree_ != ms.rb_tree_) {
      rb_tree_ = std::move(*ms.rb_tree_);
    }
  };

  ~multiset() { delete rb_tree_; };

  multiset &operator=(const multiset &ms) {
    if (this != &ms) {
      delete rb_tree_;
      rb_tree_ = new tree_type(*ms.rb_tree_);
    }

    return *this;
  };

  multiset &operator=(multiset &&ms) {
    if (this != &ms) {
      *rb_tree_ = std::move(*ms.rb_tree_);
    }

    return *this;
  };

  /*** Multiset iterators ***/
  iterator begin() noexcept { return rb_tree_->begin(); };

  iterator end() noexcept { return rb_tree_->end(); };

  const_iterator begin() const noexcept { return rb_tree_->begin(); };

  const_iterator end() const noexcept { return rb_tree_->end(); };

  /*** Multiset capacity ***/
  bool empty() const noexcept { return rb_tree_->Empty(); }

  size_type size() const noexcept { return rb_tree_->GetSize(); };

  size_type max_size() const noexcept { return rb_tree_->MaxSize(); }

  /*** Multiset modifiers ***/
  void clear() noexcept { rb_tree_->ClearTree(); };

  iterator insert(const value_type &value) {
    return rb_tree_->MultiInsertNode(value);
  };

  void erase(iterator pos) { rb_tree_->DeleteNode(pos); };

  void swap(multiset &other) {
    if (rb_tree_ != other.rb_tree_) {
      std::swap(rb_tree_, other.rb_tree_);
    }
  };

  void merge(multiset &other) { rb_tree_->MultiMerge(*other.rb_tree_); };

  /*** Multiset lookup ***/
  size_type count(const key_type &key) const noexcept {
    return rb_tree_->MultiFindKey(key);
  };

  iterator find(const key_type &key) const noexcept {
    return rb_tree_->FindKey(key);
  };

  bool contains(const key_type &key) const noexcept {
    return find(key) != end();
  };

  std::pair<iterator, iterator> equal_range(
      const key_type &key) const noexcept {
    return std::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
  };

  iterator lower_bound(const key_type &key) const noexcept {
    return rb_tree_->LowerBound(key);
  };

  iterator upper_bound(const key_type &key) const noexcept {
    return rb_tree_->UpperBound(key);
  };

 private:
  tree_type *rb_tree_ = new tree_type;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_MULTISET_S21_MULTISET_H_
