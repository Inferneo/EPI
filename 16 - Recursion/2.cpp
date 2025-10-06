// Generate All Non-Attacking Placements of N-Queens

#include <cstdlib>
#include <iostream>
#include <vector>

using std::abs;
using std::cout;
using std::vector;

// Test if a newly placed queen will conflict any earlier queens placed before.
bool IsValid(const vector<int> &col_placement) {
  int row_id = col_placement.size() - 1;
  for (int i = 0; i < row_id; ++i) {
    int diff = abs(col_placement[i] - col_placement[row_id]);
    if (diff == 0 || diff == row_id - i) {
      // A column or diagonal constraint is violated.
      return false;
    }
  }
  return true;
}

void SolveNQueens(int n, int row, vector<int> *col_placement,
                  vector<vector<int>> *result) {
  if (row == n) {
    // All queens are legally placed.
    result->emplace_back(*col_placement);
  } else {
    for (int col = 0; col < n; ++col) {
      col_placement->emplace_back(col);
      if (IsValid(*col_placement)) {
        SolveNQueens(n, row + 1, col_placement, result);
      }
      col_placement->pop_back();
    }
  }
}

vector<vector<int>> NQueens(int n) {
  vector<vector<int>> result;
  vector<int> col_placement;
  SolveNQueens(n, 0, &col_placement, &result);
  return result;
}

int main() {
  auto v = NQueens(4);
  for (auto x : v) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << '\n';
  }
}