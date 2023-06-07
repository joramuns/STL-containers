#ifndef CPP2_S21_CONTAINERS_0_TREE_DEBUG_TREE_H_
#define CPP2_S21_CONTAINERS_0_TREE_DEBUG_TREE_H_
#include <deque>
#include <iostream>
#include <string>

#include "s21_tree.h"

namespace s21 {
template <typename T, typename N>
class DTree : public Tree<T, N> {
 public:
  using value_type = T;
  using size_type = std::size_t;

  void OutputTree() {
    std::deque<std::deque<std::string>> printout;
    PrintTree(Tree<T, N>::head_, 1, printout);
    for (const auto &item : printout) {
      for (const auto &str_item : item) {
        std::cout << str_item;
      }
      std::cout << std::endl;
    }
  };

  size_type PrintTree(typename Tree<T, N>::TNode *pivot, size_type h,
                      std::deque<std::deque<std::string>> &output) {
    if (output.size() <= h) {
      output.push_back({});
      output.push_back({});
    }
    if (pivot) {
      output[h - 1].push_back(std::to_string(pivot->key_));
      if (pivot->color_ == Tree<T, N>::kBlack) {
        output[h - 1].back() += "B ";
      } else {
        output[h - 1].back() += "R ";
      }
      PrintTree(pivot->left_, h + 1, output);
      PrintTree(pivot->right_, h + 1, output);
    } else {
      output[h - 1].push_back("x ");
      output[h].push_back("y ");
      output[h].push_back("y ");
    }

    return h;
  };
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_TREE_DEBUG_TREE_H_
