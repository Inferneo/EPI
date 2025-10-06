#include <iostream>
#include <memory>
#include <stack>

using std::cout;
using std::make_shared;
using std::shared_ptr;
using std::stack;

template <typename T> struct ListNode {
  ListNode(T data = T(), shared_ptr<ListNode<T>> next = nullptr)
      : data(std::move(data)), next(std::move(next)) {}

  T data;
  shared_ptr<ListNode<T>> next;
};

void PrintLinkedListInReverse(shared_ptr<ListNode<int>> head) {
  stack<int> nodes;
  while (head) {
    nodes.push(head->data);
    head = head->next;
  }
  while (!nodes.empty()) {
    cout << nodes.top() << '\n';
    nodes.pop();
  }
}

int main() {

  auto n5 = make_shared<ListNode<int>>(50);
  auto n4 = make_shared<ListNode<int>>(40, n5);
  auto n3 = make_shared<ListNode<int>>(30, n4);
  auto n2 = make_shared<ListNode<int>>(20, n3);
  auto n1 = make_shared<ListNode<int>>(10, n2);

  PrintLinkedListInReverse(n1);
}
