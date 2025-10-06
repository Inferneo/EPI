// Implement a Circular Queue

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;
using std::endl;
using std::length_error;
using std::rotate;
using std::size_t;
using std::vector;

class Queue {
public:
  explicit Queue(size_t capacity) : entries(capacity) {}

  void Enqueue(int x) {
    if (num_queue_elements == entries.size()) { // Needs to resize.
      // Makes the queue elements appear consecutively.
      rotate(entries.begin(), entries.begin() + head_, entries.end());
      head_ = 0, tail_ = num_queue_elements; // Resets head and tail.
      entries.resize(kScaleFactor * entries.size());
    }

    entries[tail_] = x;
    tail_ = (tail_ + 1) % entries.size();
    ++num_queue_elements;
  }

  int Dequeue() {
    if (!num_queue_elements) {
      throw length_error("empty queue");
    }
    --num_queue_elements;
    int ret = entries[head_];
    head_ = (head_ + 1) % entries.size();
    return ret;
  }

  size_t size() const { return num_queue_elements; }

private:
  const int kScaleFactor = 2;
  size_t head_ = 0, tail_ = 0, num_queue_elements = 0;
  vector<int> entries;
};

int main() {
  Queue q(5);
  q.Enqueue(10);
  q.Enqueue(20);
  q.Dequeue();
  q.Enqueue(30);
  q.Enqueue(40);
  q.Enqueue(50);
  q.Enqueue(60);

  while (q.size() > 0) {
    cout << q.Dequeue() << '\t';
  }
  cout << endl;
}