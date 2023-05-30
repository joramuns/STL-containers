#ifndef CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
#define CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_

#include <initializer_list>
#include <iostream>

// Temp for print
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>

namespace s21 {
template <typename T>
class Tree {
  struct TNode;
  class TreeIterator;
  class ConstTreeIterator;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = TreeIterator;
  using const_iterator = ConstTreeIterator;

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

  ~Tree() { head_->DeleteNode(head_); };

  std::pair<iterator, bool> InsertNode(value_type value) {
    std::pair<iterator, bool> result;
    if (head_) {
      TNode *search = FindNode(value).iter_;
      if (value > search->data_) {
        search->right_ = new TNode(search, value);
        result.first = iterator(search->right_);
        result.second = true;
        std::cout << "inside: " << result.second << " what: " << *result.first
                  << std::endl;
      } else if (value < search->data_) {
        search->left_ = new TNode(search, value);
        result.first = iterator(search->left_);
        result.second = true;
      }
    } else {
      head_ = new TNode(value);
      head_->color_ = kBlack;
      result.first = iterator(head_);
      result.second = false;
    }

    return result;
  }

  iterator FindNode(value_type value) {
    TNode *parent = head_;
    TNode *child = parent;
    bool not_found = true;
    while (child && not_found) {
      parent = child;
      if (value > parent->data_) {
        child = parent->right_;
      } else if (value < parent->data_) {
        child = parent->left_;
      } else {
        not_found = false;
      }
    }
    if (not_found) {
    }

    return iterator(parent);
  }

  void RotateLeft(iterator upper_it, iterator lower_it) {
    TNode *upper_node = upper_it.iter_;
    TNode *lower_node = lower_it.iter_;
    if (upper_node->right_ == lower_node) {
      lower_node->parent_ = upper_node->parent_;
      if (upper_node->parent_ == nullptr) {
        head_ = lower_node;
        lower_node->color_ = kBlack;
      } else {
        if (lower_node->parent_->right_ == upper_node) {
          lower_node->parent_->right_ = lower_node;
        } else {
          lower_node->parent_->left_ = lower_node;
        }
      }
      upper_node->right_ = lower_node->left_;
      lower_node->left_ = upper_node;
      upper_node->parent_ = lower_node;
    }
  }

  void RotateRight(iterator upper_it, iterator lower_it) {
    TNode *upper_node = upper_it.iter_;
    TNode *lower_node = lower_it.iter_;
    if (upper_node->left_ == lower_node) {
      lower_node->parent_ = upper_node->parent_;
      if (upper_node->parent_ == nullptr) {
        head_ = lower_node;
        lower_node->color_ = kBlack;
      } else {
        if (lower_node->parent_->right_ == upper_node) {
          lower_node->parent_->right_ = lower_node;
        } else {
          lower_node->parent_->left_ = lower_node;
        }
      }
      upper_node->left_ = lower_node->right_;
      lower_node->right_ = upper_node;
      upper_node->parent_ = lower_node;
    }
  }

  void PrintTree() {
    std::deque<std::deque<std::string>> printout;
    head_->PrintTree(head_, 1, printout);
    for (const auto &item : printout) {
      for (const auto &str_item : item) {
        std::cout << str_item;
      }
      std::cout << std::endl;
    }
  };

 private:
  class TreeIterator {
   public:
    TreeIterator(){};
    explicit TreeIterator(TNode *tree_node) noexcept : iter_(tree_node){};
    TreeIterator(const TreeIterator &other) noexcept : iter_(other.iter_){};
    TreeIterator(TreeIterator &&other) noexcept {
      std::swap(iter_, other.iter_);
    }

    TreeIterator &operator=(const TreeIterator &other) noexcept {
      if (this != &other) iter_ = other.iter_;

      return *this;
    }
    TreeIterator &operator=(TreeIterator &&other) noexcept {
      if (this != &other) std::swap(iter_, other.iter_);

      return *this;
    }
    operator bool() noexcept { return (iter_); }
    operator bool() const noexcept { return (iter_); }
    const_reference operator*() const { return iter_->data_; }
    reference operator*() { return iter_->data_; }

    TNode *iter_;
  };

  class ConstTreeIterator {
   public:
    ConstTreeIterator(){};
    explicit ConstTreeIterator(const iterator &other) noexcept
        : iter_(other.iter_){};

    operator bool() noexcept { return (iter_); }
    const_reference operator*() const { return iter_->data_; }

    TNode *iter_;
  };

  enum TColor { kBlack, kRed };
  struct TNode {
    TNode *parent_ = nullptr;
    TNode *left_ = nullptr;
    TNode *right_ = nullptr;
    value_type data_;
    bool color_ = kRed;

    explicit TNode(const_reference value) : data_(value){};
    TNode(TNode *parent, const_reference value)
        : parent_(parent), data_(value){};

    bool IsFatherLeft() {
      if (parent_ && parent_->parent_ && parent_->parent_->left_ == parent_) {
        return true;
      }
      return false;
    }
    bool IsParentRed() {
      if (parent_ && parent_->color_ == kRed) {
        return true;
      }
      return false;
    }

    bool IsLeftSon() {
      if (parent_ && parent_->left_ == *this) {
        return true;
      }
      return false;
    }

    bool IsUncleRed() {
      if (parent_ && parent_->right_ && parent_->right_->color_ == kRed) {
        return true;
      }
      return false;
    }

    size_type PrintTree(TNode *pivot, size_type h,
                        std::deque<std::deque<std::string>> &output) {
      if (output.size() <= h) {
        output.push_back({});
        output.push_back({});
      }
      if (pivot) {
        output[h - 1].push_back(std::to_string(pivot->data_));
        if (pivot->color_ == kBlack) {
          output[h - 1].back() += "B";
        } else {
          output[h - 1].back() += "R";
        }
        PrintTree(pivot->left_, h + 1, output);
        PrintTree(pivot->right_, h + 1, output);
      } else {
        output[h - 1].push_back("x");
        output[h].push_back("y");
        output[h].push_back("y");
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
