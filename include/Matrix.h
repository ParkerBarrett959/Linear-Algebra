/*
 * Matrix.h
 * Author: Parker Barrett
 * Overview: Templated matrix class.
 */

// STL Include
#include <iostream>
#include <stdexcept>
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
  T& operator()(const unsigned row, const unsigned col) {
    return data_[row][col];
  }

  // Matrix Addition
  Matrix<T> operator+(Matrix<T>& M) {
    if ((M.rows() != nRows_) || (M.cols() != nCols_)) {
      throw std::invalid_argument("Matrices must have same size");
    }
    Matrix<T> Out(nRows_, nCols_);
    for (unsigned i = 0; i < nRows_; i++) {
      for (unsigned j = 0; j < nCols_; j++) {
        Out(i, j) = data_[i][j] + M(i, j);
      }
    }
    return Out;
  }

  // Matrix Subtraction
  Matrix<T> operator-(Matrix<T>& M) {
    if ((M.rows() != nRows_) || (M.cols() != nCols_)) {
      throw std::invalid_argument("Matrices must have same size");
    }
    Matrix<T> Out(nRows_, nCols_);
    for (unsigned i = 0; i < nRows_; i++) {
      for (unsigned j = 0; j < nCols_; j++) {
        Out(i, j) = data_[i][j] - M(i, j);
      }
    }
    return Out;
  }

  // Matrix Multiplication
  Matrix<T> operator*(Matrix<T>& M) {
    if (M.rows() != nCols_) {
      throw std::invalid_argument("Invalid matrix sizes for multiplication");
    }
    Matrix<T> Out(nRows_, M.cols());
    for (unsigned i = 0; i < nRows_; i++) {
      for (unsigned j = 0; j < M.cols(); j++) {
        T entry = 0;
        for (unsigned k = 0; k < nCols_; k++) {
          entry += data_[i][k] * M(k, j);
        }
        Out(i, j) = entry;
      }
    }
    return Out;
  }

  // Scalar Addition

  // Scalar Subtraction

  // Scalar Multiplication

  // Scalar Division

 private:
  // Matrix Data
  unsigned nRows_;
  unsigned nCols_;
  std::vector<std::vector<T>> data_;
};
