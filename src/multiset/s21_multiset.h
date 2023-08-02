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

  explicit multiset(std::initializer_list<value_type> const &items);

  multiset(const multiset &ms);

  multiset(multiset &&ms);

  ~multiset() { delete rb_tree_; };

  multiset &operator=(const multiset &ms);

  multiset &operator=(multiset &&ms);

  /*** Multiset iterators ***/
  iterator begin() const noexcept;

  iterator end() const noexcept;

  /*** Multiset modifiers ***/
  void clear() noexcept;

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
  size_type count(const key_type &key) const noexcept;

  iterator find(const key_type &key) const noexcept { return rb_tree_->FindKey(key); };

  bool contains(const key_type &key) const noexcept { return find(key) != end(); };

  std::pair<iterator, iterator> equal_range(const key_type &key) const noexcept;

  iterator lower_bound(const key_type &key) const noexcept;

  iterator upper_bound(const key_type &key) const noexcept;

 private:
  tree_type *rb_tree_ = new tree_type;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_MULTISET_S21_MULTISET_H_
