#ifndef CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
#define CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_

#include <initializer_list>
#include <iostream>

// Temp for print
#include <string>
#include <vector>
#include <iomanip>
#include <ios>
#include <cmath>

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

  void PrintTree() {
    std::vector<std::vector<std::string>> printout;
    head_->PrintTree(head_, 1, printout);
    size_type height = printout.size();
    size_type n_height = height - 1;
    for (const auto &item : printout) {
      size_type width = std::pow(2, height) / (2 * item.size());
      width *= 3;
      width -= std::pow(3, --n_height);
      for (const auto &str_item : item) {
        std::cout.width(width);
        std::cout << str_item;
      }
      std::cout << std::endl;
    }
  };

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

    size_type PrintTree(TNode *pivot, size_type h, std::vector<std::vector<std::string>> &output) {
      if (output.size() < h) output.push_back({});
      if (pivot) {
        output[h - 1].push_back(std::to_string(pivot->data_));
        PrintTree(pivot->left_, h + 1, output);
        PrintTree(pivot->right_, h + 1, output);
      } else {
        output[h - 1].push_back("x");
      }

      return h;
    }; 

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
