// Test if a Binary Tree is Height-Balanced

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <memory>

using std::abs;
using std::cout;
using std::endl;
using std::make_unique;
using std::max;
using std::unique_ptr;

template <typename T> struct BinaryTreeNode {
  T data{};
  unique_ptr<BinaryTreeNode<T>> left{nullptr}, right{nullptr};
};

struct BalancedStatusWithHeight {
  bool balanced;
  int height;
};

// First value of the return value indicates if tree is balanced, and if
// balanced the second value of the return value is the height of the tree.
BalancedStatusWithHeight
CheckBalanced(const unique_ptr<BinaryTreeNode<int>> &tree) {
  if (tree == nullptr) {
    return {true, -1}; // Base case.
  }

  auto left_result = CheckBalanced(tree->left);
  if (!left_result.balanced) {
    return {false, 0}; // Left subtree is not balanced.
  }
  auto right_result = CheckBalanced(tree->right);
  if (!right_result.balanced) {
    return {false, 0}; // Right subtree is not balanced.
  }

  bool is_balanced = abs(left_result.height - right_result.height) <= 1;
  int height = max(left_result.height, right_result.height) + 1;
  return {is_balanced, height};
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>> &tree) {
  return CheckBalanced(tree).balanced;
}

int main() {
  // construct nodes according to the diagram
  auto root = make_unique<BinaryTreeNode<int>>();
  root->data = 314; // A

  // left subtree of A
  root->left = make_unique<BinaryTreeNode<int>>();
  root->left->data = 6; // B

  // B -> left C(271) with children D(28) and E(0)
  root->left->left = make_unique<BinaryTreeNode<int>>();
  root->left->left->data = 271; // C
  root->left->left->left = make_unique<BinaryTreeNode<int>>();
  root->left->left->left->data = 28; // D
  root->left->left->right = make_unique<BinaryTreeNode<int>>();
  root->left->left->right->data = 0; // E

  // B -> right F(561) -> child G(3)
  root->left->right = make_unique<BinaryTreeNode<int>>();
  root->left->right->data = 561; // F
  root->left->right->right = make_unique<BinaryTreeNode<int>>();
  root->left->right->right->data = 3; // G

  // right subtree of A
  root->right = make_unique<BinaryTreeNode<int>>();
  root->right->data = 6; // I

  // I -> left J(2) -> child K(1);
  root->right->left = make_unique<BinaryTreeNode<int>>();
  root->right->left->data = 2; // J
  root->right->left->right = make_unique<BinaryTreeNode<int>>();
  root->right->left->right->data = 1; // K

  // I -> right O(271) -> P(28)
  root->right->right = make_unique<BinaryTreeNode<int>>();
  root->right->right->data = 271; // O
  root->right->right->right = make_unique<BinaryTreeNode<int>>();
  root->right->right->right->data = 28; // P

  auto b = CheckBalanced(root);
  cout << '\n' << b.height << endl;
}
