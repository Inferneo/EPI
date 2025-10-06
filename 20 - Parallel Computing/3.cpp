// Implement Synchronization for Two Interleaving Threads

#include <condition_variable>
#include <iostream>
#include <mutex>

using std::condition_variable;
using std::cout;
using std::endl;
using std::lock_guard;
using std::mutex;
using std::unique_lock;

class OddEvenMonitor {
public:
  static const bool ODD_TURN = true;
  static const bool EVEN_TURN = false;

  OddEvenMonitor() : turn_(ODD_TURN) {};

  void WaitTurn(bool old_turn) {
    unique_lock<mutex> lock(mx_);
    while (turn_ != old_turn) {
      cond_.wait(lock);
    }
  }

  void ToggleTurn() {
    lock_guard<mutex> lock(mx_);
    turn_ = !turn_;
    cond_.notify_one();
  }

private:
  bool turn_;
  condition_variable cond_;
  mutex mx_;
};

void OddThread(OddEvenMonitor &monitor) {
  for (int i = 1; i <= 100; i += 2) {
    monitor.WaitTurn(OddEvenMonitor::ODD_TURN);
    cout << i << endl;
    monitor.ToggleTurn();
  }
}

void EvenThread(OddEvenMonitor &monitor) {
  for (int i = 2; i <= 100; i += 2) {
    monitor.WaitTurn(OddEvenMonitor::EVEN_TURN);
    cout << i << endl;
    monitor.ToggleTurn();
  }
}