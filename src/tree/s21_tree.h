#ifndef CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
#define CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_

#include <algorithm>
#include <initializer_list>

// temp
#include <iostream>

namespace s21 {
template <typename T, typename N>
class Tree {
 protected:
  struct TNode;

 public:
  class TreeIterator;
  using key_type = T;
  using key_reference = T &;
  using const_key_reference = const T &;
  using value_type = N;
  using value_reference = N &;
  using const_value_reference = const N &;
  using size_type = std::size_t;
  using iterator = TreeIterator;
  using const_iterator = const TNode *;

  Tree() { tail_->is_fake_ = true; };

  // Broken ctor
  Tree(const Tree &other){};

  Tree(Tree &&other) { std::swap(head_, other.head_); };

  // Broken assop
  Tree &operator=(const Tree &other) {
    if (this != &other) {
      delete head_;
      head_ = other.head_;
    }

    return *this;
  };

  Tree &operator=(Tree &&other) { return *this; };

  virtual ~Tree() {
    DeleteTree(head_);
    delete tail_;
  };

  iterator begin() const noexcept {
    TNode *result;
    if (head_) {
      result = head_->MinNode();
    } else {
      result = tail_;
    }

    return iterator(result);
  }

  iterator end() const noexcept { return iterator(tail_); }

  /* Overload for multiset, inserts multi node with key and value = key */
  std::pair<iterator, bool> MultiInsertNode(key_type key) {
    return MultiInsertNode(key, key);
  };

  /* Overload for set, inserts unique node with key and value = key */
  std::pair<iterator, bool> InsertNode(key_type key) {
    return (std::pair<iterator, bool>)InsertNode(key, key);
  };

  /* Inserts multi node */
  std::pair<TNode *, bool> MultiInsertNode(key_type key, value_type value) {
    std::pair<TNode *, bool> result = InsertNode(key);
    while (result.second == false) {
      if (result.first->right_) {
        result = InsertNode(key, value, result.first->right_);
      } else {
        result.first->right_ = new TNode(result.first, key, value);
        result.second = true;
        BalanceTree(result.first->right_);
        tail_->left_ = head_->MaxNode();
        tail_->right_ = head_->MinNode();
      }
    }

    return result;
  };

  /* Inserts unique node from root, redirects to next
   * overloaded function with root as subtree argument */
  std::pair<TNode *, bool> InsertNode(key_type key, value_type value) {
    std::pair<TNode *, bool> result;
    if (head_) {
      result = InsertNode(key, value, head_);
    } else {
      head_ = new TNode(key, value);
      head_->color_ = kBlack;
      head_->parent_ = tail_;
      tail_->left_ = head_->MaxNode();
      tail_->right_ = head_->MinNode();
      result.first = head_;
      result.second = false;
    }

    return result;
  };

  /* Overload for inserting node not only from root, but from
   * subtrees in order to insert nodes with repeating keys */
  std::pair<TNode *, bool> InsertNode(key_type key, value_type value,
                                      TNode *root) {
    TNode *search = FindNode(key, root);
    std::pair<TNode *, bool> result = {search, false};
    if (key > search->key_) {
      search->right_ = new TNode(search, key, value);
      result.first = search->right_;
      result.second = true;
    } else if (key < search->key_) {
      search->left_ = new TNode(search, key, value);
      result.first = search->left_;
      result.second = true;
    }
    if (result.second) {
      BalanceTree(result.first);
      tail_->left_ = head_->MaxNode();
      tail_->right_ = head_->MinNode();
    }

    return result;
  };

  iterator FindKey(key_type key) const noexcept {
    iterator result = FindNode(key);
    if (*result != key) {
      result = end();
    }

    return result;
  }

  /* Overload of search function to find node from root */
  iterator FindNode(key_type key) const noexcept {
    return (iterator)FindNode(key, head_);
  };

  /* Overload for searching key node
   * in subtrees for multi version of container */
  TNode *FindNode(key_type key, TNode *root) const noexcept {
    TNode *parent = root;
    TNode *child = parent;
    bool not_found = true;
    while (child && not_found) {
      parent = child;
      if (key > parent->key_) {
        child = parent->right_;
      } else if (key < parent->key_) {
        child = parent->left_;
      } else {
        not_found = false;
      }
    }

    return parent;
  };

  /* Universal function for rotating nodes,
   * based on mutual arrangement of upper and
   * lower nodes determines which side rotation should be called */
  void RotateNodes(TNode *upper_node, TNode *lower_node) {
    if (lower_node->IsRightSon()) {
      RotateLeft(upper_node, lower_node);
    } else {
      RotateRight(upper_node, lower_node);
    }
  };

  void RotateLeft(TNode *upper_node, TNode *lower_node) {
    SwapParents(upper_node, lower_node);
    upper_node->right_ = lower_node->left_;
    if (upper_node->right_) upper_node->right_->parent_ = upper_node;
    lower_node->left_ = upper_node;
  };

  void RotateRight(TNode *upper_node, TNode *lower_node) {
    SwapParents(upper_node, lower_node);
    upper_node->left_ = lower_node->right_;
    if (upper_node->left_) upper_node->left_->parent_ = upper_node;
    lower_node->right_ = upper_node;
  };

  /* Common decomposed algorithm for both rotations */
  void SwapParents(TNode *upper_node, TNode *lower_node) {
    lower_node->parent_ = upper_node->parent_;
    if (upper_node->IsFatherFake()) {
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
  };

  void BalanceTree(TNode *target_node) {
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
  };

  void DeleteNode(TNode *remove_node) {
    size_type children_num = remove_node->CountChildren();
    /* :3: RB2, red or black node with 2 children:
     * Check if maximum key of left tree is red and delete it
     * Otherwise, go to minumum key of right tree, call this function
     * and repeat the whole algorithm */
    if (children_num == 2) {
      TNode *swap_node = remove_node->left_.MaxNode();
      if (swap_node->color_ == kRed) {
        remove_node->key_ = swap_node->key_;
        remove_node->value_ = swap_node->value_;
        DeleteNode(swap_node);
      } else {
        swap_node = remove_node->right_.MinNode();
        remove_node->key_ = swap_node->key_;
        remove_node->value_ = swap_node->value_;
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
        remove_node->key_ = remove_node->right_->key_;
        remove_node->value_ = remove_node->right_->value_;
        DeleteNode(remove_node->right_);
      } else {
        remove_node->key_ = remove_node->left_->key_;
        remove_node->value_ = remove_node->left_->value_;
        DeleteNode(remove_node->left_);
      }
      /* :5: B0, black node without children */
    } else {
      TNode *brother = remove_node->GetBrother();
      remove_node->EraseNode();
      RebalanceBrother(brother);
    }
  };

  /* Rebalance tree function after deleting a node */
  void RebalanceBrother(TNode *brother) { /* :B0.1: Brother is black */
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
  };

  void DeleteTree(TNode *pivot) {
    if (pivot) {
      DeleteTree(pivot->left_);
      DeleteTree(pivot->right_);
      delete pivot;
    }
  };
  class TreeIterator {
   public:
    TreeIterator(){};

    explicit TreeIterator(TNode *node) : iter_(node){};
    /* explicit TreeIterator(iterator &other) : iter_(other.iter_){}; */

    iterator &operator=(const iterator &other) {
      iter_ = other.iter_;
      return *this;
    }

    ~TreeIterator(){};

    iterator operator++() {
      *this = this->iter_->NextNode();
      /* *this = this->iter_->PrevNode(); */
      return *this;
    };

    /* iterator operator++(int) {}; */
    iterator operator--() {
      *this = this->iter_->PrevNode();
      return *this;
    };
    /* iterator operator--(int) {}; */

    bool operator==(const iterator &other) { return iter_ == other.iter_; }

    bool operator!=(const iterator &other) { return iter_ != other.iter_; }

    value_reference operator*() { return iter_->value_; }

   private:
    TNode *iter_;
  };

 protected:
  enum TColor { kBlack, kRed };

  struct TNode {
    TNode *parent_ = nullptr;
    TNode *left_ = nullptr;
    TNode *right_ = nullptr;
    key_type key_;
    value_type value_;
    bool color_ = kRed;
    bool is_fake_ = false;

    TNode(const_key_reference key, const_value_reference value)
        : key_(key), value_(value){};

    TNode(TNode *parent, const_key_reference key, const_value_reference value)
        : parent_(parent), key_(key), value_(value){};

    /* operator TreeIterator() { return TreeIterator(this); } */

    TNode *MinNode() noexcept {
      TNode *root_node = this;
      while (root_node->left_) {
        root_node = root_node->left_;
      }

      return root_node;
    };

    TNode *MaxNode() noexcept {
      TNode *root_node = this;
      while (root_node->right_) {
        root_node = root_node->right_;
      }

      return root_node;
    };

    iterator NextNode() {
      TNode *next_node = this;
      if (next_node->right_) {
        next_node = next_node->right_->MinNode();
      } else if (next_node->parent_ && !next_node->IsRightSon()) {
        next_node = next_node->parent_;
      } else {
        while (next_node->parent_ && !next_node->IsFatherFake() &&
               next_node->IsRightSon()) {
          next_node = next_node->parent_;
        }
        next_node = next_node->parent_;
      }

      return iterator(next_node);
    };

    iterator PrevNode() {
      TNode *prev_node = this;
      if (prev_node->left_) {
        prev_node = prev_node->left_->MaxNode();
      } else if (prev_node->parent_ && prev_node->IsRightSon()) {
        prev_node = prev_node->parent_;
      } else {
        while (prev_node->parent_ && !prev_node->IsFatherFake() &&
               !prev_node->IsRightSon()) {
          prev_node = prev_node->parent_;
        }
        prev_node = prev_node->parent_;
      }

      return iterator(prev_node);
    };

    bool IsFatherFake() { return this->parent_->is_fake_; }

    bool IsLeftFather() {
      if (parent_ && parent_->parent_ && parent_->parent_->left_ == parent_) {
        return true;
      }
      return false;
    };

    bool IsParentRed() {
      if (parent_ && !IsFatherFake() && parent_->color_ == kRed) {
        return true;
      }
      return false;
    };

    bool IsRightSon() {
      if (parent_ && parent_->right_ == this) {
        return true;
      }
      return false;
    };

    bool IsUncleRed() {
      TNode *uncle_node = GetUncle();
      if (uncle_node && uncle_node->color_ == kRed) {
        return true;
      } else {
        return false;
      }
    };

    TNode *GetUncle() {
      if (parent_->IsRightSon()) {
        return parent_->parent_->left_;
      } else {
        return parent_->parent_->right_;
      }
    };

    TNode *GetBrother() {
      if (IsRightSon()) {
        return parent_->left_;
      } else {
        return parent_->right_;
      }
    };

    TNode *GetFarNephew() {
      if (IsRightSon()) {
        return right_;
      } else {
        return left_;
      }
    };

    TNode *GetNearNephew() {
      if (IsRightSon()) {
        return left_;
      } else {
        return right_;
      }
    };

    size_type CountChildren() {
      size_type count = 0;
      if (left_) ++count;
      if (right_) ++count;

      return count;
    };

    void EraseNode() {
      if (IsRightSon()) {
        parent_->right_ = nullptr;
      } else if (parent_) {
        parent_->left_ = nullptr;
      }
      delete this;
    };
  };

  TNode *head_ = nullptr;
  TNode *tail_ = new TNode({}, {});
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_TREE_S21_TREE_H_
