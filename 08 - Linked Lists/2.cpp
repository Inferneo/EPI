// Reverse a Single Sublist

#include <algorithm>
#include <iostream>
#include <memory>

using std::cout;
using std::make_shared;
using std::shared_ptr;

template <typename T> struct ListNode {
  ListNode(T data = T(), shared_ptr<ListNode<T>> next = nullptr)
      : data(std::move(data)), next(std::move(next)) {}
  T data;
  shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
  if (start == finish) { // No need to reverse since start == finish.
    return L;
  }

  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto sublist_head = dummy_head;
  int k = 1;

  while (k++ < start) {
    sublist_head = sublist_head->next;
  }

  // Reverses sublist
  auto sublist_iter = sublist_head->next;
  while (start++ < finish) {
    auto temp = sublist_iter->next;
    sublist_iter->next = temp->next;
    temp->next = sublist_head->next;
    sublist_head->next = temp;
  }
  return dummy_head->next;
}

int main() {
  auto n6 = make_shared<ListNode<int>>(60);
  auto n5 = make_shared<ListNode<int>>(50, n6);
  auto n4 = make_shared<ListNode<int>>(40, n5);
  auto n3 = make_shared<ListNode<int>>(30, n4);

  auto n2 = make_shared<ListNode<int>>(20, n3);
  auto n1 = make_shared<ListNode<int>>(10, n2);
  auto n0 = make_shared<ListNode<int>>(5, n1);

  auto n_sort = ReverseSublist(n1, 3, 5);

  while (n_sort) {
    cout << n_sort->data << '\n';
    n_sort = n_sort->next;
  }
}