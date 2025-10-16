// Implement a Sudoku Solver

#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using std::any_of;
using std::begin;
using std::end;
using std::sqrt;
using std::vector;

const int kEmptyEntry = 0;

bool ValidToAddVal(const vector<vector<int>> &partial_assignment, int i, int j,
                   int val) {
  // Check column constraints.
  for (int k = 0; k < partial_assignment.size(); ++k) {
    if (val == partial_assignment[k][j]) {
      return false;
    }
  }

  // Check row constraints.
  if (any_of(begin(partial_assignment[i]), end(partial_assignment[i]),
             [val](int a) { return val == a; })) {
    return false;
  }

  // Check region constraints.
  int region_size = sqrt(partial_assignment.size());
  int I = i / region_size, J = j / region_size;
  for (int a = 0; a < region_size; ++a) {
    for (int b = 0; b < region_size; ++b) {
      if (val == partial_assignment[region_size * I + a][region_size * J + b]) {
        return false;
      }
    }
  }
  return true;
}

bool SolvePartialSudoku(int i, int j, vector<vector<int>> *partial_assignment) {
  if (i == partial_assignment->size()) {
    i = 0; // Starts a new row.
    if (++j == (*partial_assignment)[i].size()) {
      return true; // Entire matrix has been filled without conflict.
    }
  }

  // Skips non-empty entries.
  if ((*partial_assignment)[i][j] != kEmptyEntry) {
    return SolvePartialSudoku(i + 1, j, partial_assignment);
  }

  for (int val = 1; val <= partial_assignment->size(); ++val) {
    // It's substantially quicker to check if entry val conflicts with any of
    // the constraints if we add it at (i, j) afterwards, rather than
    // adding it and then checking all constraints. The reason is that we know
    // we are starting with a valid configuration, and the only entry which can
    // cause a problem is entryval at (i, j).
    if (ValidToAddVal(*partial_assignment, i, j, val)) {
      (*partial_assignment)[i][j] = val;
      if (SolvePartialSudoku(i + 1, j, partial_assignment)) {
        return true;
      }
    }
  }

  (*partial_assignment)[i][j] = kEmptyEntry; // Undo assignment.
  return false;
}

bool SolveSudoku(vector<vector<int>> *partial_assignment) {
  return SolvePartialSudoku(0, 0, partial_assignment);
}