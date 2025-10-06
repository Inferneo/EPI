#include <algorithm>
#include <iostream>
#include <memory>
#include <ostream>

using std::cout;
using std::make_unique;
using std::unique_ptr;

template <typename T> struct BinaryTreeNode {
  BinaryTreeNode(T data = T(), unique_ptr<BinaryTreeNode<T>> left = nullptr,
                 unique_ptr<BinaryTreeNode<T>> right = nullptr)
      : data(std::move(data)), left(std::move(left)), right(std::move(right)) {}
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
};

void TreeTraversal(const unique_ptr<BinaryTreeNode<int>> &root) {
  if (root) {
    // Preorder: Processes the root before the traversals of left and right
    // children.
    // cout << "Preorder: " << root->data << '\n';
    TreeTraversal(root->left);
    // Inorder: Processes the root after the traversal of the left child and
    // before the traversal of the right child.
    // cout << "Inorder: " << root->data << '\n';
    TreeTraversal(root->right);
    // Postorder: Processes the root after the traversals of the left and right
    // children.
    cout << "Postorder: " << root->data << '\n';
  }
}

int main() {
  auto root = make_unique<BinaryTreeNode<int>>(
      10,
      make_unique<BinaryTreeNode<int>>(20, make_unique<BinaryTreeNode<int>>(40),
                                       make_unique<BinaryTreeNode<int>>(50)),
      make_unique<BinaryTreeNode<int>>(30, make_unique<BinaryTreeNode<int>>(60),
                                       make_unique<BinaryTreeNode<int>>(70)));
  TreeTraversal(root);
}