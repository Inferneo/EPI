// Compute the LCA when Nodes have Parent Pointers

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>

using std::abs;
using std::cout;
using std::make_unique;
using std::swap;
using std::unique_ptr;

template <typename T> struct BinaryTreeNode {
  T data{};
  unique_ptr<BinaryTreeNode<T>> left{nullptr}, right{nullptr};
  BinaryTreeNode<T> *parent;
};

int GetDepth(const BinaryTreeNode<int> *node) {
  int depth = 0;
  while (node->parent) {
    ++depth;
    node = node->parent;
  }
  return depth;
}

BinaryTreeNode<int> *LCA(const unique_ptr<BinaryTreeNode<int>> &node_0,
                         const unique_ptr<BinaryTreeNode<int>> &node_1) {
  auto *iter_0 = node_0.get();
  auto *iter_1 = node_1.get();
  int depth_0 = GetDepth(iter_0), depth_1 = GetDepth(iter_1);
  // Makes iter_0 as the deeper node in order to simplify the code.
  if (depth_1 > depth_0) {
    swap(iter_0, iter_1);
  }
  // Ascends from the deeper node.
  int depth_diff = abs(depth_0 - depth_1);
  while (depth_diff--) {
    iter_0 = iter_0->parent;
  }

  // Now ascends both nodes until we reach the LCA.
  while (iter_0 != iter_1) {
    iter_0 = iter_0->parent, iter_1 = iter_1->parent;
  }

  return iter_0;
}

int main() {
  auto root = make_unique<BinaryTreeNode<int>>();
  root->data = 314; // A

  // left subtree of A
  root->left = make_unique<BinaryTreeNode<int>>();
  root->left->data = 6; // B
  root->left->parent = root.get();

  // B -> right C(561) -> child D(3)
  root->left->right = make_unique<BinaryTreeNode<int>>();
  root->left->right->data = 2; // C
  root->left->right->parent = root->left.get();
  root->left->right->right = make_unique<BinaryTreeNode<int>>();
  root->left->right->right->data = 3; // D
  root->left->right->right->parent = root->left->right.get();

  // right subtree of A
  root->right = make_unique<BinaryTreeNode<int>>();
  root->right->data = 60; // E
  root->right->parent = root.get();

  // E -> left F(2) -> child K(1);
  root->right->left = make_unique<BinaryTreeNode<int>>();
  root->right->left->data = 20; // F
  root->right->left->parent = root->right.get();
  root->right->left->left = make_unique<BinaryTreeNode<int>>();
  root->right->left->left->data = 30; // G
  root->right->left->left->parent = root->right->left.get();

  auto *lca = LCA(root->left->right->right, root->right->left->left);

  cout << "LCA of 3 and 30 is " << lca->data << '\n';
}