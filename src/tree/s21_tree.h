#ifndef CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
#define CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_

#include <algorithm>
#include <initializer_list>

namespace s21 {
template <typename T>
class Tree {
 protected:
  struct TNode;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = TNode *;
  using const_iterator = const TNode *;

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

  virtual ~Tree() { head_->DeleteTree(head_); };

  std::pair<iterator, bool> MultiInsertNode(value_type value) {
    std::pair<iterator, bool> result = InsertNode(value);
    while (result.second == false) {
      if (result.first->right_) {
        result = InsertNode(value, result.first->right_);
      } else {
        result.first->right_ = new TNode(result.first, value);
        result.second = true;
        BalanceTree(result.first->right_);
      }
    }

    return result;
  }

  std::pair<iterator, bool> InsertNode(value_type value) {
    std::pair<iterator, bool> result;
    if (head_) {
      result = InsertNode(value, head_);
    } else {
      head_ = new TNode(value);
      head_->color_ = kBlack;
      result.first = head_;
      result.second = false;
    }

    return result;
  };

  std::pair<iterator, bool> InsertNode(value_type value, TNode *root) {
    TNode *search = FindNode(value, root);
    std::pair<iterator, bool> result = {search, false};
    if (value > search->data_) {
      search->right_ = new TNode(search, value);
      result.first = search->right_;
      result.second = true;
    } else if (value < search->data_) {
      search->left_ = new TNode(search, value);
      result.first = search->left_;
      result.second = true;
    }
    if (result.second) BalanceTree(result.first);

    return result;
  }

  iterator FindNode(value_type value) const noexcept {
    return FindNode(value, head_);
  };

  iterator FindNode(value_type value, TNode *root) const noexcept {
    TNode *parent = root;
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

    return parent;
  }

  iterator MinNode(iterator root_node) const noexcept {
    while (root_node->left_) {
      root_node = root_node->left_;
    }

    return root_node;
  }

  iterator MaxNode(iterator root_node) const noexcept {
    while (root_node->right_) {
      root_node = root_node->right_;
    }

    return root_node;
  }

  iterator NextNode(iterator next_node) {
    if (next_node->right_) {
      next_node = MinNode(next_node->right_);
    } else if (next_node->parent_ && !next_node->IsRightSon()) {
      next_node = next_node->parent_;
    } else {
      while (next_node->parent_ && next_node->IsRightSon()) {
        next_node = next_node->parent_;
      }
      next_node = next_node->parent_;
    }

    return next_node;
  }

  iterator PrevNode(iterator prev_node) {
    if (prev_node->left_) {
      prev_node = MaxNode(prev_node->left_);
    } else if (prev_node->parent_ && prev_node->IsRightSon()) {
      prev_node = prev_node->parent_;
    } else {
      while (prev_node->parent_ && !prev_node->IsRightSon()) {
        prev_node = prev_node->parent_;
      }
      prev_node = prev_node->parent_;
    }

    return prev_node;
  }

  void RotateNodes(iterator upper_node, iterator lower_node) {
    if (lower_node->IsRightSon()) {
      RotateLeft(upper_node, lower_node);
    } else {
      RotateRight(upper_node, lower_node);
    }
  }

  void RotateLeft(iterator upper_node, iterator lower_node) {
    SwapParents(upper_node, lower_node);
    upper_node->right_ = lower_node->left_;
    if (upper_node->right_) upper_node->right_->parent_ = upper_node;
    lower_node->left_ = upper_node;
  }

  void RotateRight(iterator upper_node, iterator lower_node) {
    SwapParents(upper_node, lower_node);
    upper_node->left_ = lower_node->right_;
    if (upper_node->left_) upper_node->left_->parent_ = upper_node;
    lower_node->right_ = upper_node;
  }

  void SwapParents(iterator upper_node, iterator lower_node) {
    lower_node->parent_ = upper_node->parent_;
    if (upper_node->parent_ == nullptr) {
      head_ = lower_node;
      lower_node->color_ = kBlack;
    } else {
      if (upper_node->IsRightSon()) {
        upper_node->parent_->right_ = lower_node;
      } else {
        upper_node->parent_->left_ = lower_node;
      }
    }
    upper_node->parent_ = lower_node;
  }

  void BalanceTree(iterator target_node) {
    /* Father and son are red, need to balance */
    while (target_node->IsParentRed()) {
      /* :1:&:4: Uncle is red, no matter whether son is left or right,
       * difference is in being father left or right child */
      if (target_node->IsUncleRed()) {
        target_node->parent_->color_ = kBlack;
        target_node->GetUncle()->color_ = kBlack;
        target_node->parent_->parent_->color_ = kRed;
        target_node = target_node->parent_->parent_;
      } else {
        /* :2:->:3: First 2 cases, father is left child of grandfother
         * :5:->:6: Second 2 cases, father is right child of grandfother
         * No uncle or uncle black, check if son is right or left son */
        bool is_left_father = target_node->IsLeftFather();
        bool is_left_son = !target_node->IsRightSon();
        /* :3: Son is left, father is left
         * :6: Son is right, father is right */
        if ((is_left_father && is_left_son) ||
            (!is_left_father && !is_left_son)) {
          target_node->parent_->color_ = kBlack;
          target_node->parent_->parent_->color_ = kRed;
          RotateNodes(target_node->parent_->parent_, target_node->parent_);
        } else {
          /* :2:&&:5: Son and father not in one line, convert to :3:||:6: */
          RotateNodes(target_node->parent_, target_node);
          if (is_left_father && !is_left_son) {
            target_node = target_node->left_;
          } else if (!is_left_father && is_left_son) {
            target_node = target_node->right_;
          }
        }
      }
    }
    if (head_->color_ == kRed) head_->color_ = kBlack;
  }

  void DeleteNode(iterator remove_node) {
    size_type children_num = remove_node->CountChildren();
    /* :3: RB2, red or black node with 2 children:
     * Check if maximum value of left tree is red and delete it
     * Otherwise, go to minumum value of right tree, call this function
     * and repeat the whole algorithm */
    if (children_num == 2) {
      iterator swap_node = MaxNode(remove_node->left_);
      if (swap_node->color_ == kRed) {
        remove_node->data_ = swap_node->data_;
        DeleteNode(swap_node);
      } else {
        swap_node = MinNode(remove_node->right_);
        remove_node->data_ = swap_node->data_;
        DeleteNode(swap_node);
      }
      /* :1: R0, red node without children
       * It is impossible for red node to have one child
       * Simply erase this node            */
    } else if (remove_node->color_ == kRed) {
      remove_node->EraseNode();
      /* :4-5: Delete black node */
      /* :4: B1, black node with one child */
    } else if (remove_node->color_ == kBlack && children_num == 1) {
      if (remove_node->right_) {
        remove_node->data_ = remove_node->right_->data_;
        DeleteNode(remove_node->right_);
      } else {
        remove_node->data_ = remove_node->left_->data_;
        DeleteNode(remove_node->left_);
      }
      /* :5: B0, black node without children */
    } else {
      TNode *brother = remove_node->GetBrother();
      remove_node->EraseNode();
      RebalanceBrother(brother);
    }
  }

  void RebalanceBrother(iterator brother) { /* :B0.1: Brother is black */
    if (brother->color_ == kBlack) {
      TNode *far_nephew = brother->GetFarNephew();
      TNode *near_nephew = brother->GetNearNephew();
      /* Far nephew is red, near nephew's color doesn't matter */
      if (far_nephew && far_nephew->color_ == kRed) {
        brother->color_ = brother->parent_->color_;
        brother->parent_->color_ = kBlack;
        far_nephew->color_ = kBlack;
        RotateNodes(brother->parent_, brother);
        /* Far newphew is black, near nephew is red */
      } else if (near_nephew && near_nephew->color_ == kRed) {
        brother->color_ = kRed;
        near_nephew->color_ = kBlack;
        RotateNodes(brother, near_nephew);
        RebalanceBrother(near_nephew);
        /* Both nephews are black */
      } else {
        brother->color_ = kRed;
        if (brother->parent_->color_ == kRed) {
          brother->parent_->color_ = kBlack;
        } else {
          brother = brother->parent_->GetBrother();
          RebalanceBrother(brother);
        }
      }
      /* :B0.2: Brother is red */
    } else {
      brother->color_ = kBlack;
      brother->parent_->color_ = kRed;
      /* Near nephew becomes new brother, then goes new rebalancing */
      TNode *new_brother = brother->GetNearNephew();
      RotateNodes(brother->parent_, brother);
      RebalanceBrother(new_brother);
    }
  }

 protected:
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

    bool IsUncleRed() {
      TNode *uncle_node = GetUncle();
      if (uncle_node && uncle_node->color_ == kRed) {
        return true;
      } else {
        return false;
      }
    }

    TNode *GetUncle() {
      if (parent_->IsRightSon()) {
        return parent_->parent_->left_;
      } else {
        return parent_->parent_->right_;
      }
    }

    TNode *GetBrother() {
      if (IsRightSon()) {
        return parent_->left_;
      } else {
        return parent_->right_;
      }
    }

    TNode *GetFarNephew() {
      if (IsRightSon()) {
        return right_;
      } else {
        return left_;
      }
    }

    TNode *GetNearNephew() {
      if (IsRightSon()) {
        return left_;
      } else {
        return right_;
      }
    }

    size_type CountChildren() {
      size_type count = 0;
      if (left_) ++count;
      if (right_) ++count;

      return count;
    }

    void EraseNode() {
      if (IsRightSon()) {
        parent_->right_ = nullptr;
      } else if (parent_) {
        parent_->left_ = nullptr;
      }
      delete this;
    }

    void DeleteTree(TNode *pivot) {
      if (pivot) {
        DeleteTree(pivot->left_);
        DeleteTree(pivot->right_);
        delete pivot;
      }
    }
  };
  TNode *head_ = nullptr;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
