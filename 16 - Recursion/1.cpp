// The Towers of Hanoi Problem

#include <array>
#include <iostream>
#include <stack>

using std::array;
using std::cout;
using std::stack;

const int kNumPegs = 3;

void ComputeTowerHanoiSteps(int num_rings_to_move,
                            array<stack<int>, kNumPegs> &pegs, int from_peg,
                            int to_peg, int use_peg) {
  if (num_rings_to_move > 0) {
    ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, from_peg, use_peg,
                           to_peg);
    pegs[to_peg].push(pegs[from_peg].top());
    pegs[from_peg].pop();
    cout << "Move from peg " << from_peg << " to peg " << to_peg << '\n';
    ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, use_peg, to_peg,
                           from_peg);
  }
}

void ComputeTowerHanoi(int num_rings) {
  array<stack<int>, kNumPegs> pegs;
  // Initialize pegs.
  for (int i = num_rings; i >= 1; --i) {
    pegs[0].push(i);
  }

  ComputeTowerHanoiSteps(num_rings, pegs, 0, 1, 2);
}

int main() {
    ComputeTowerHanoi(2);
}