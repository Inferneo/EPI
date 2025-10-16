// Compute the Spiral Ordering of a 2D Array

#include <cmath>
#include <vector>

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
