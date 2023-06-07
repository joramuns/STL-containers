#ifndef CPP2_S21_CONTAINERS_0_SET_S21_SET_H_
#define CPP2_S21_CONTAINERS_0_SET_S21_SET_H_

#include <algorithm>
#include <initializer_list>

#include "../tree/s21_tree.h"

namespace s21 {
template <typename T>
class set {
  /*** Forward declaration of nested classes ***/
  class SetIterator;
  class ConstSetIterator;

 public:
  using key_type = T;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = SetIterator;
  using const_iterator = ConstSetIterator;
  using size_type = std::size_t;

  /* Set member functions */
  set(){};
  explicit set(std::initializer_list<value_type> const &items){};
  set(const set &s) = default;
  set(set &&s) = default;
  ~set(){};
  /* set &operator=(const set &s){ return 0; }; */
  /* set &operator=(set &&s){ return 0; }; */

  /* Set iterators */
  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;

  /* Set capacity */
  bool empty() noexcept;
  bool empty() const noexcept;
  size_type size() noexcept;
  size_type size() const noexcept;
  size_type max_size() noexcept;
  size_type max_size() const noexcept;

  /* Set modifiers */
  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  void erase(iterator pos);
  void swap(set &other);
  void merge(set &other);

  /* Set lookup */
  iterator find(const key_type &key) noexcept;
  iterator find(const key_type &key) const noexcept;
  bool contains(const key_type &key) noexcept;
  bool contains(const key_type &key) const noexcept;

 private:
  class SetIterator {};
  class ConstSetIterator {};
  size_type size_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_SET_S21_SET_H_
