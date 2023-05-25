#ifndef CPP2_S21_CONTAINERS_0_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_0_STACK_S21_STACK_H_

#include "../list/s21_list.h"

namespace s21 {
template <typename T, typename Container = list<T>>
class stack {
 public:
   using value_type = T;
   using reference = T &;
   using const_reference = const T &;
   using size_type = std::size_t;

   /*** Stack member functions ***/
   stack();
   explicit stack(std::initializer_list<value_type> const &items);
   stack(const stack &s);
   stack(stack &&s);
   ~stack();
   stack &operator=(const stack &s);
   stack &operator=(stack &&s);

   /*** Stack element access ***/
   const_reference top() const noexcept;
   reference top() noexcept;

   /*** Stack capacity ***/
   bool empty();
   size_type size();

   /*** Stack modifiers ***/
   void push(const_reference value);
   void pop();
   void swap(stack &other);
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_STACK_S21_STACK_H_
