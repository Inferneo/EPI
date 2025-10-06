// The Readers-Writers Problem

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>

using std::condition_variable;
using std::cout;
using std::endl;
using std::lock_guard;
using std::mutex;
using std::string;
using std::unique_lock;

namespace RW {
int read_count;
mutex LRm;
mutex LW;
condition_variable LR;
int data = 0;
} // namespace RW

void DoSomethingElse() { return; };

// LR and LW are variables in the RW namespace.
// They serve as read and write locks. The integer variable read_count in RW
// tracks the number of readers.
void Reader(string name) {
  while (true) {
    {
      lock_guard<mutex> lock(RW::LRm);
      ++RW::read_count;
    }
    cout << RW::data << endl;
    {
      lock_guard<mutex> lock(RW::LRm);
      --RW::read_count;
      RW::LR.notify_one();
    }
    DoSomethingElse();
  }
}

void Writer(string name) {
  while (true) {
    {
      lock_guard<mutex> lock_w(RW::LW);
      bool done = false;
      while (!done) {
        unique_lock<mutex> lock(RW::LRm);
        if (RW::read_count == 0) {
          ++RW::data;
          done = true;
        } else {
          // use wait/notify to avoid busy waiting
          while (RW::read_count != 0) {
            RW::LR.wait(lock);
          }
        }
      }
    }
    DoSomethingElse();
  }
}