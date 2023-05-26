#ifndef CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
#define CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_

namespace s21 {
template <typename T>
class Tree {
  using value_type = T;

 private:
  enum TColor { kBlack, kRed };
  struct TNode {
    TNode *parent_ = nullptr;
    TNode *left_ = nullptr;
    TNode *right_ = nullptr;
    value_type data_;
    bool color_ = kBlack;
  };
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
