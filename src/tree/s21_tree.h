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
      } else if (value < search->data_) {
        search->left_ = new TNode(search, value);
        result.first = iterator(search->left_);
        result.second = true;
      }
      if (result.second) BalanceTree(iterator(result.first));
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

  iterator MinNode(iterator root) {
    TNode *root_node = root.iter_;
    while (root_node->left_) {
      root_node = root_node->left_;
    }

    return iterator(root_node);
  }

  iterator MaxNode(iterator root) {
    TNode *root_node = root.iter_;
    while (root_node->right_) {
      root_node = root_node->right_;
    }

    return iterator(root_node);
  }

  iterator NextNode(iterator target) {
    TNode *next_node = target.iter_;
    if (next_node->right_) {
      next_node = MinNode(iterator(next_node->right_)).iter_;
    } else if (next_node->parent_ && next_node == next_node->parent_->left_) {
      next_node = next_node->parent_;
    } else {
      while (next_node->parent_ && next_node == next_node->parent_->right_) {
        next_node = next_node->parent_;
      }
      /* if (next_node->parent_) { */
        next_node = next_node->parent_;
      /* } */
    }

    return iterator(next_node);
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
        if (upper_node->parent_->right_ == upper_node) {
          upper_node->parent_->right_ = lower_node;
        } else {
          upper_node->parent_->left_ = lower_node;
        }
      }
      upper_node->right_ = lower_node->left_;
      if (upper_node->right_) upper_node->right_->parent_ = upper_node;
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
        if (upper_node->parent_->right_ == upper_node) {
          upper_node->parent_->right_ = lower_node;
        } else {
          upper_node->parent_->left_ = lower_node;
        }
      }
      upper_node->left_ = lower_node->right_;
      if (upper_node->left_) upper_node->left_->parent_ = upper_node;
      lower_node->right_ = upper_node;
      upper_node->parent_ = lower_node;
    }
  }

  void BalanceTree(iterator target_iter) {
    TNode *target_node = target_iter.iter_;
    /* Father and son are red, need to balance */
    while (target_node->IsParentRed()) {
      /* :1-3: First 3 cases, father is left child of grandfother */
      if (target_node->IsLeftFather()) {
        /* :1: Uncle (right) is red, no matter whether son is left or right
         * child */
        if (target_node->IsRightUncleRed()) {
          target_node->parent_->color_ = kBlack;
          target_node->parent_->parent_->right_->color_ = kBlack;
          target_node->parent_->parent_->color_ = kRed;
          target_node = target_node->parent_->parent_;
          /* :2-3: No uncle or uncle black, check if son is left or right son */
        } else {
          /* :2: Son is right, need to convert to 3 case */
          if (target_node->IsRightSon()) {
            RotateLeft(iterator(target_node->parent_), iterator(target_node));
            target_node = target_node->left_;
            /* :3: Son is left */
          } else {
            target_node->parent_->color_ = kBlack;
            target_node->parent_->parent_->color_ = kRed;
            RotateRight(iterator(target_node->parent_->parent_),
                        iterator(target_node->parent_));
          }
        }
        /* :4-6: Second 3 cases, father is right child of grandfother */
      } else {
        /* :4: Uncle (left) is red, no matter whether son is left or right child
         */
        if (target_node->IsLeftUncleRed()) {
          target_node->parent_->color_ = kBlack;
          target_node->parent_->parent_->left_->color_ = kBlack;
          target_node->parent_->parent_->color_ = kRed;
          target_node = target_node->parent_->parent_;
          /* :5-6: No uncle or uncle black, check if son is right or left son */
        } else {
          /* :6: Son is right */
          if (target_node->IsRightSon()) {
            target_node->parent_->color_ = kBlack;
            target_node->parent_->parent_->color_ = kRed;
            RotateLeft(iterator(target_node->parent_->parent_),
                       iterator(target_node->parent_));
            /* :5: Son is left, need to convert to 6 case */
          } else {
            RotateRight(iterator(target_node->parent_), iterator(target_node));
            target_node = target_node->right_;
          }
        }
      }
    }
    if (head_->color_ == kRed) head_->color_ = kBlack;
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

    bool IsLeftFather() {
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

    bool IsRightSon() {
      if (parent_ && parent_->right_ == this) {
        return true;
      }
      return false;
    }

    bool IsRightUncleRed() {
      if (parent_->parent_ && parent_->parent_->right_ &&
          parent_->parent_->right_->color_ == kRed) {
        return true;
      }
      return false;
    }

    bool IsLeftUncleRed() {
      if (parent_->parent_ && parent_->parent_->left_ &&
          parent_->parent_->left_->color_ == kRed) {
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
