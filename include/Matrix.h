/*
 * Matrix.h
 * Author: Parker Barrett
 * Overview: Templated matrix class.
 */

// Includes
#include <iostream>
#include <vector>

// Matrix Class Implementation
template <typename T>
class Matrix {
 public:
  // Default Constructor
  Matrix() : nRows_(0), nCols_(0) {}

  // Construct Matrix of Size with Specific Value
  Matrix(unsigned rows, unsigned cols, T val = 0) : nRows_(rows), nCols_(cols) {
    data_.resize(nRows_);
    for (unsigned i = 0; i < data_.size(); i++) {
      data_[i].resize(nCols_, val);
    }
  }

  // Destructor
  ~Matrix() {}

  // Get Number of Rows
  unsigned rows() const { return nRows_; }

  // Get Number of Columns
  unsigned cols() const { return nCols_; }

  // Index Operator
  T operator()(const unsigned row, const unsigned col) {
    return data_[row][col];
  }

 private:
  // Matrix Data
  unsigned nRows_;
  unsigned nCols_;
  std::vector<std::vector<T>> data_;
};
