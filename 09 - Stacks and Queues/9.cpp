// Implement a Queue Using Stacks

#include <stack>
#include <stdexcept>

using std::length_error;
using std::stack;

class Queue {
public:
  void Enqueue(int x) { enq_.emplace(x); }

  int Dequeue() {
    if (deq_.empty()) {
      // Transfers the elements in enq_ to deq_.
      while (!enq_.empty()) {
        deq_.emplace(enq_.top());
        enq_.pop();
      }
    }

    if (deq_.empty()) { // deq_ is still empty!
      throw length_error("empty queue");
    }
    int ret = deq_.top();
    deq_.pop();
    return ret;
  }

private:
  stack<int> enq_, deq_;
};

// O(m) time for m operations (no element pushed more than twice, popped more
// than twice.)