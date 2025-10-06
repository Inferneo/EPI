// Test if a Binary Tree is Symmetric

#include <iostream>
#include <memory>

using std::cout;
using std::make_unique;
using std::unique_ptr;

template <typename T> struct BinaryTreeNode {
  T data{};
  unique_ptr<BinaryTreeNode<T>> left{nullptr};
  unique_ptr<BinaryTreeNode<T>> right{nullptr};
};

bool CheckSymmetric(const unique_ptr<BinaryTreeNode<int>> &subtree_0,
                    const unique_ptr<BinaryTreeNode<int>> &subtree_1) {
  if (subtree_0 == nullptr && subtree_1 == nullptr) {
    return true;
  } else if (subtree_0 != nullptr && subtree_1 != nullptr) {
    return subtree_0->data == subtree_1->data &&
           CheckSymmetric(subtree_0->left, subtree_1->right) &&
           CheckSymmetric(subtree_0->right, subtree_1->left);
  }
  // One Subtree is empty, and the other is not.
  return false;
}

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>> &tree) {
  return tree == nullptr || CheckSymmetric(tree->left, tree->right);
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

  cout << IsSymmetric(root) << '\n';
}