#ifndef CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
#define CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class Tree {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  Tree(){};

  // Broken ctor
  Tree(const Tree &other){};

  Tree(Tree &&other) { std::swap(head_, other.head_); }

  // Broken assop
  Tree &operator=(const Tree &other) {
    if (this != &other) {
      delete head_;
      head_ = other.head_;
    }

    return *this;
  };

  Tree &operator=(Tree &&other) { return *this; };

  ~Tree() {
    head_->DeleteNode(head_);
  };

  void InsertNode(value_type value) {
    if (head_) {
      TNode *parent = head_;
      TNode *child = (value > parent->data_) ? parent->right_ : parent->left_;
      while (child) {
        parent = child;
        child = (value > parent->data_) ? parent->right_ : parent->left_;
      }
      child = new TNode(parent, value);
      if (value > parent->data_) {
        parent->right_ = child;
      } else if (value < parent->data_) {
        parent->left_ = child;
      } else {
        std::cout << "Equal nodes, temporary block" << std::endl;
      }
    } else {
      head_ = new TNode(value);
    }
  }
 private:
  enum TColor { kBlack, kRed };
  struct TNode {
    TNode *parent_ = nullptr;
    TNode *left_ = nullptr;
    TNode *right_ = nullptr;
    value_type data_;
    bool color_ = kBlack;

    explicit TNode(const_reference value) : data_(value){};
    TNode(TNode *parent, const_reference value) : parent_(parent), data_(value) {};


    void DeleteNode(TNode *pivot) {
      if (pivot) {
        DeleteNode(pivot->left_);
        DeleteNode(pivot->right_);
        delete pivot;
      }
    }
      
  };
  TNode *head_ = nullptr;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
