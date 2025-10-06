// Merge Two Sorted Doubly Linked Lists

#include <algorithm>
#include <iostream>
#include <memory>

using std::shared_ptr;

template <typename T> struct ListNode {
  ListNode(T data = T(), shared_ptr<ListNode<T>> next = nullptr,
           shared_ptr<ListNode<T>> prev = nullptr)
      : data(std::move(data)), next(std::move(next)), prev(std::move(prev)) {}

  T data;
  shared_ptr<ListNode<T>> next;
  shared_ptr<ListNode<T>> prev;
};

void AppendNode(shared_ptr<ListNode<int>> *node,
                shared_ptr<ListNode<int>> *tail) {
  (*node)->prev = (*tail);
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
  if (tail->next) {
    tail->next->prev = tail;
  }
  return dummy_head->next;
}

int main() {
  auto n5 = std::make_shared<ListNode<int>>(50);
  auto n3 = std::make_shared<ListNode<int>>(40, n5);
  auto n2 = std::make_shared<ListNode<int>>(20, n3);
  n3->prev = n2;
  n5->prev = n3;

  auto n6 = std::make_shared<ListNode<int>>(60);
  auto n1 = std::make_shared<ListNode<int>>(30, n6);
  auto n0 = std::make_shared<ListNode<int>>(0, n1);
  n1->prev = n0;
  n6->prev = n1;

  auto n4 = MergeTwoSortedLists(n0, n2);

  while (n4) {
    std::cout << '\n' << "Data: " << n4->data << '\n';
    std::cout << "Location: " << n4.get() << '\n';
    std::cout << "Next: " << n4->next.get() << '\n';
    std::cout << "Prev: " << n4->prev.get() << '\n';
    n4 = n4->next;
  }
}