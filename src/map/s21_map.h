#ifndef CPP2_S21_CONTAINERS_0_MAP_S21_MAP_H_
#define CPP2_S21_CONTAINERS_0_MAP_S21_MAP_H_

#include "../tree/s21_tree.h"

namespace s21 {
template <typename Key, typename T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using tree_type = Tree<Key, T>;
  using iterator = typename tree_type::TreeIterator;
  using const_iterator = typename tree_type::ConstTreeIterator;
  using size_type = std::size_t;

  /*** Map member functions ***/
  map() = default;

  explicit map(std::initializer_list<value_type> const &items) {
    for (const auto &item : items) {
      insert(item);
    }
  };

  map(const map &m) : rb_tree_(m.rb_tree_){};

  map(map &&m) : rb_tree_(std::move(m.rb_tree_)){};

  ~map() = default;

  map &operator=(const map &m) {
    if (this != &m) {
      clear();
      rb_tree_ = tree_type(m.rb_tree_);
    }
    return *this;
  };

  map &operator=(map &&m) {
    if (this != &m) {
      rb_tree_ = std::move(m.rb_tree_);
    }
    return *this;
  };

  /*** Map element access ***/
  mapped_type &at(const Key &key) {
    iterator iter = rb_tree_.FindKey(key);
    return *iter;
  };

  mapped_type &operator[](const Key &key) { return at(key); };

  /*** Map iterators ***/
  iterator begin() noexcept { return rb_tree_.begin(); };

  iterator end() noexcept { return rb_tree_.end(); };

  const_iterator begin() const noexcept { return rb_tree_.begin(); };

  const_iterator end() const noexcept { return rb_tree_.end(); };

  /*** Map capacity ***/
  bool empty() { return rb_tree_.Empty(); };

  size_type size() { return rb_tree_.GetSize(); };

  size_type max_size() { return rb_tree_.MaxSize(); };

  /*** Map modifiers ***/
  void clear() { rb_tree_.ClearTree(); };

  std::pair<iterator, bool> insert(const value_type &value) {
    return rb_tree_.InsertNode(value);
  };

  std::pair<iterator, bool> insert(const key_type &key,
                                   const mapped_type &obj) {
    return rb_tree_.InsertNode((value_type{key, obj}));
  };

  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const mapped_type &obj) {
    auto insert_attempt = insert(key, obj);
    if (insert_attempt.second == false) {
      insert_attempt.first = (iterator)rb_tree_.FindKey(key);
      *insert_attempt.first = obj;
    }

    return insert_attempt;
  };

  void erase(iterator pos) { rb_tree_.DeleteNode(pos); };

  void swap(map &other) {
    if (&rb_tree_ != &other.rb_tree_) {
      std::swap(rb_tree_, other.rb_tree_);
    }
  };

  void merge(map &other) {
    if (this != &other) {
      rb_tree_.Merge(other.rb_tree_);
    }
  };

  /*** Map lookup ***/
  bool contains(const key_type &key) { return rb_tree_.FindKey(key) != end(); };

 private:
  tree_type rb_tree_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_MAP_S21_MAP_H_
