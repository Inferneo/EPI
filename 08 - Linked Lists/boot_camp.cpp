#include <iostream>
#include <memory>

using std::cout;
using std::make_shared;
using std::shared_ptr;

template <typename T> struct ListNode {
  T data{};
  shared_ptr<ListNode<T>> next{nullptr};
};

shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> L, int key) {
  while (L && L->data != key) {
    L = L->next;
  }
  // If key is not in list, L will have become null.
  return L;
}

// Insert new node after node
void InsertAfter(const shared_ptr<ListNode<int>> &node,
                 const shared_ptr<ListNode<int>> &new_node) {
  new_node->next = node->next;
  node->next = new_node;
}

// Delete the node past this one. Assume node is not a tail
void DeleteAfter(const shared_ptr<ListNode<int>> &node) {
  if (node && node->next) {
    node->next = node->next->next;
  }
}

int main() {
  auto n3 = make_shared<ListNode<int>>(ListNode<int>{50});
  auto n2 = make_shared<ListNode<int>>(ListNode<int>{40, n3});
  auto n1 = make_shared<ListNode<int>>(ListNode<int>{30, n2});

  auto r = SearchList(n1, 35);

  if (r) {
    int res = r->data;
    cout << res << '\n';
  }
}