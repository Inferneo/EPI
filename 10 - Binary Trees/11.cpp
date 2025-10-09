// Implement an Inorder Traversal in O(1) Space

#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;

template <typename T> struct BinaryTreeNode {
  T data{};
  unique_ptr<BinaryTreeNode<T>> left{nullptr}, right{nullptr};
  BinaryTreeNode<T> *parent;
};

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>> &tree) {
  BinaryTreeNode<int> *prev = nullptr, *curr = tree.get();
  vector<int> result;

  while (curr != nullptr) {
    BinaryTreeNode<int> *next;
    if (curr->parent == prev) {
      // We came down to curr from prev.
      if (curr->left != nullptr) { // Keep going left.
        next = curr->left.get();
      } else {
        result.emplace_back(curr->data);
        // Done with left, so go right if right is not empty.
        // Otherwise, go up.
        next = (curr->right != nullptr) ? curr->right.get() : curr->parent;
      }
    } else if (curr->left.get() == prev) {
      // We came up to curr from its left child.
      result.emplace_back(curr->data);
      // Done with left, so go right if right is not empty.
      // Otherwise, go up.
      next = (curr->right != nullptr) ? curr->right.get() : curr->parent;
    } else { // Done with both children, so move up.
      next = curr->parent;
    }

    prev = curr;
    curr = next;
  }
  return result;
}

// Time complexity is O(n). Space complexity is O(1).