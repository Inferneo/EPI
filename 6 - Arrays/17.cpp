// Compute the Spiral Ordering of a 2D Array

#include <array>
#include <cmath>
#include <vector>

using std::array;
using std::vector;

void MatrixLayerInClockwise(const vector<vector<int>> &square_matrix,
                            int offset, vector<int> *spiral_ordering) {
  if (offset == square_matrix.size() - offset - 1) {
    // square matrix has odd dimension, and we are at the center of the square
    // matrix
    spiral_ordering->emplace_back(square_matrix[offset][offset]);
    return;
  }
  for (int j = offset; j < square_matrix.size() - offset - 1; ++j) {
    spiral_ordering->emplace_back(square_matrix[offset][j]);
  }
  for (int i = offset; i < square_matrix.size() - offset - 1; ++i) {
    spiral_ordering->emplace_back(
        square_matrix[i][square_matrix.size() - offset - 1]);
  }
  for (int j = square_matrix.size() - offset - 1; j > offset; --j) {
    spiral_ordering->emplace_back(
        square_matrix[square_matrix.size() - offset - 1][j]);
  }
  for (int i = square_matrix.size() - offset - 1; i > offset; --i) {
    spiral_ordering->emplace_back(square_matrix[i][offset]);
  }
}

vector<int> MatrixInSpiralOrder(const vector<vector<int>> &square_matrix) {
  vector<int> spiral_ordering;
  for (int offset = 0; offset < std::ceil(0.5 * square_matrix.size());
       ++offset) {
    MatrixLayerInClockwise(square_matrix, offset, &spiral_ordering);
  }
  return spiral_ordering;
}

vector<int> MatrixInSpiralOrder2(vector<vector<int>> &square_matrix) {
  const array<array<int, 2>, 4> kShift{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
  int dir = 0, x = 0, y = 0;
  vector<int> spiral_ordering;

  for (int i = 0; i < square_matrix.size() * square_matrix.size(); ++i) {
    spiral_ordering.emplace_back(square_matrix[x][y]);
    square_matrix[x][y] = 0;
    int next_x = x + kShift[dir][0], next_y = y + kShift[dir][1];
    if (next_x < 0 || next_x >= square_matrix.size() || next_y < 0 ||
        next_y >= square_matrix.size() || square_matrix[next_x][next_y] == 0) {
      dir = (dir + 1) % 4;
      next_x = x + kShift[dir][0], next_y = y + kShift[dir][1];
    }
    x = next_x, y = next_y;
  }
  return spiral_ordering;
}
