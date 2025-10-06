// Compute the Lowest Common Ancestor in a Binary Tree

#include <iostream>
#include <memory>

using std::cout;
using std::make_unique;
using std::unique_ptr;

template <typename T> struct BinaryTreeNode {
  T data{};
  unique_ptr<BinaryTreeNode<T>> left{nullptr}, right{nullptr};
};

struct Status {
  int num_target_nodes;
  BinaryTreeNode<int> *ancestor;
};

// Returns an object consisting of an int and a node. The int field is 0, 1, or
// 2 depending on how many of {node0, node1} are present in the tree. If both
// are present in the tree, when ancestor is assigned to a non-null value, it is
// the LCA.
Status LCAHelper(const unique_ptr<BinaryTreeNode<int>> &tree,
                 const unique_ptr<BinaryTreeNode<int>> &node0,
                 const unique_ptr<BinaryTreeNode<int>> &node1) {
  if (tree == nullptr) {
    return {0, nullptr};
  }
  auto left_result = LCAHelper(tree->left, node0, node1);
  if (left_result.num_target_nodes == 2) {
    return left_result;
  }
  auto right_result = LCAHelper(tree->right, node0, node1);
  if (right_result.num_target_nodes == 2) {
    return right_result;
  }
  int num_target_nodes = left_result.num_target_nodes +
                         right_result.num_target_nodes + (tree == node0) +
                         (tree == node1);
  return {num_target_nodes, num_target_nodes == 2 ? tree.get() : nullptr};
}

BinaryTreeNode<int> *LCA(const unique_ptr<BinaryTreeNode<int>> &tree,
                         const unique_ptr<BinaryTreeNode<int>> &node0,
                         const unique_ptr<BinaryTreeNode<int>> &node1) {
  return LCAHelper(tree, node0, node1).ancestor;
}

int main() {
  auto root = make_unique<BinaryTreeNode<int>>();
  root->data = 314; // A

  // left subtree of A
  root->left = make_unique<BinaryTreeNode<int>>();
  root->left->data = 6; // B

  // B -> right C(561) -> child D(3)
  root->left->right = make_unique<BinaryTreeNode<int>>();
  root->left->right->data = 2; // C
  root->left->right->right = make_unique<BinaryTreeNode<int>>();
  root->left->right->right->data = 3; // D

  // right subtree of A
  root->right = make_unique<BinaryTreeNode<int>>();
  root->right->data = 6; // E

  // E -> left F(2) -> child K(1);
  root->right->left = make_unique<BinaryTreeNode<int>>();
  root->right->left->data = 2; // F
  root->right->left->left = make_unique<BinaryTreeNode<int>>();
  root->right->left->left->data = 3; // G

  auto lca = LCA(root, root->left, root->left->right);

  cout << lca->data << '\n';
}
