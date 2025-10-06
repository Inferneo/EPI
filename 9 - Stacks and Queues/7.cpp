// Compute Binary Tree Nodes in Order of Increasing Depth

#include <memory>
#include <queue>
#include <vector>

using std::make_unique;
using std::queue;
using std::unique_ptr;
using std::vector;

template <typename T> struct BinaryTreeNode {
  BinaryTreeNode(T data = T(), unique_ptr<BinaryTreeNode<T>> left = nullptr,
                 unique_ptr<BinaryTreeNode<T>> right = nullptr)
      : data(std::move(data)), left(std::move(left)), right(std::move(right)) {}
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
};

vector<vector<int>>
BinaryTreeDepthOrder(const unique_ptr<BinaryTreeNode<int>> &tree) {
  queue<BinaryTreeNode<int> *> curr_depth_nodes({tree.get()});
  vector<vector<int>> result;

  while (!curr_depth_nodes.empty()) {
    queue<BinaryTreeNode<int> *> next_depth_nodes;
    vector<int> this_level;
    while (!curr_depth_nodes.empty()) {
      auto curr = curr_depth_nodes.front();
      curr_depth_nodes.pop();
      if (curr) {
        this_level.emplace_back(curr->data);

        // Defer the null checks to the null test above.
        next_depth_nodes.emplace(curr->left.get());
        next_depth_nodes.emplace(curr->right.get());
      }
    }

    if (!this_level.empty()) {
      result.emplace_back(this_level);
    }
    curr_depth_nodes = next_depth_nodes;
  }
  return result;
}

int main() {
  auto root = make_unique<BinaryTreeNode<int>>(
      314, make_unique<BinaryTreeNode<int>>(30),
      make_unique<BinaryTreeNode<int>>(40));
}