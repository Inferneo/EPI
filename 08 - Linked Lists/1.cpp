// Merge Two Sorted Lists

#include <iostream>
#include <memory>

using std::shared_ptr;

template <typename T> struct ListNode {
  ListNode(T data = T(), shared_ptr<ListNode<T>> next = nullptr)
      : data(std::move(data)), next(std::move(next)) {}
  T data;
  shared_ptr<ListNode<T>> next;
};

void AppendNode(shared_ptr<ListNode<int>> *node,
                shared_ptr<ListNode<int>> *tail) {
  (*tail)->next = *node;
  *tail = *node; // Updates tail.
  *node = (*node)->next;
}

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // Creates a placeholder for the result.
  shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
  auto tail = dummy_head;

  while (L1 && L2) {
    AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
  }

  // Appends the remaining nodes of L1 or L2
  tail->next = L1 ? L1 : L2;
  return dummy_head->next;
}

int main() {
  auto n3 = std::make_shared<ListNode<int>>(40);
  auto n2 = std::make_shared<ListNode<int>>(20, n3);
  auto n1 = std::make_shared<ListNode<int>>(30);
  auto n0 = std::make_shared<ListNode<int>>(0, n1);

  auto n4 = MergeTwoSortedLists(n0, n2);

  while (n4) {
    std::cout << n4->data << '\n';
    n4 = n4->next;
  }
}