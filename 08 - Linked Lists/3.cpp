// Test for Cyclicity

#include <algorithm>
#include <iostream>
#include <memory>

using std::cout;
using std::make_shared;
using std::shared_ptr;

template <typename T> struct ListNode {
  ListNode(T data = T(), shared_ptr<ListNode<T>> next = nullptr)
      : data(std::move(data)), next(std::move(next)) {};

  T data;
  shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>> &head) {
  shared_ptr<ListNode<int>> fast = head, slow = head;

  while (fast && fast->next) {
    slow = slow->next, fast = fast->next->next;
    if (slow == fast) {
      // There is a cycle, so now let's calculate the cycle length
      int cycle_len = 0;
      do {
        ++cycle_len;
        fast = fast->next;
      } while (slow != fast);
      // Finds the start of the cycle
      auto cycle_len_advanced_iter = head;
      while (cycle_len--) {
        cycle_len_advanced_iter = cycle_len_advanced_iter->next;
      }

      auto iter = head;
      // Both iterators advance in tandem.
      //   cycle_len_advanced_iter = fast;
      while (iter != cycle_len_advanced_iter) {
        iter = iter->next;
        cycle_len_advanced_iter = cycle_len_advanced_iter->next;
      }
      return iter; // iter is the start of the cycle.
    }
  }
  return nullptr; // No cycle
}

int main() {
  auto n7 = make_shared<ListNode<int>>(70);
  auto n6 = make_shared<ListNode<int>>(60);

  auto n5 = make_shared<ListNode<int>>(50, n6);
  auto n4 = make_shared<ListNode<int>>(40, n5);
  auto n3 = make_shared<ListNode<int>>(30, n4);

  auto n2 = make_shared<ListNode<int>>(20, n3);
  auto n1 = make_shared<ListNode<int>>(10, n2);
  auto n0 = make_shared<ListNode<int>>(5, n1);

  n6->next = n0;

  auto cycle = HasCycle(n0);

  if (!cycle) {
    cout << "No cycle present!" << '\n';
  } else {
    cout << cycle->data << '\n';
  }
}