// Paint a Boolean Matrix

#include <array>
#include <deque>
#include <vector>

using std::array;
using std::deque;
using std::vector;

void FlipColor(int x, int y, vector<deque<bool>> *A_ptr) {
  vector<deque<bool>> &A = *A_ptr;
  const array<array<int, 2>, 4> kDirs = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
  const bool color = A[x][y];

  A[x][y] = !color; // Flips.
  for (auto dir : kDirs) {
    const int next_x = x + dir[0], next_y = y + dir[1];
    if (next_x >= 0 && next_x < A.size() && next_y >= 0 && next_y < A[next_x].size() && A[next_x][next_y] == color) {
        FlipColor(next_x, next_y, A_ptr);
    }
  }
}