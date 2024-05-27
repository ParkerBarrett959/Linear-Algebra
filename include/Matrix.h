/*
 * Matrix.h
 * Author: Parker Barrett
 * Overview: Templated matrix class.
 */

// STL Include
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>

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
  Matrix<T> operator+(T val) {
    Matrix<T> Out(nRows_, nCols_);
    for (unsigned i = 0; i < nRows_; i++) {
      for (unsigned j = 0; j < nCols_; j++) {
        Out(i, j) = data_[i][j] + val;
      }
    }
    return Out;
  }

  // Scalar Subtraction
  Matrix<T> operator-(T val) {
    Matrix<T> Out(nRows_, nCols_);
    for (unsigned i = 0; i < nRows_; i++) {
      for (unsigned j = 0; j < nCols_; j++) {
        Out(i, j) = data_[i][j] - val;
      }
    }
    return Out;
  }

  // Scalar Multiplication
  Matrix<T> operator*(T val) {
    Matrix<T> Out(nRows_, nCols_);
    for (unsigned i = 0; i < nRows_; i++) {
      for (unsigned j = 0; j < nCols_; j++) {
        Out(i, j) = data_[i][j] * val;
      }
    }
    return Out;
  }

  // Scalar Division
  Matrix<T> operator/(T val) {
    Matrix<T> Out(nRows_, nCols_);
    for (unsigned i = 0; i < nRows_; i++) {
      for (unsigned j = 0; j < nCols_; j++) {
        Out(i, j) = data_[i][j] / val;
      }
    }
    return Out;
  }

  // Transpose
  Matrix<T> transpose() {
    Matrix<T> Out(nCols_, nRows_);
    for (unsigned i = 0; i < nRows_; i++) {
      for (unsigned j = 0; j < nCols_; j++) {
        Out(j, i) = data_[i][j];
      }
    }
    return Out;
  }

  // Inverse
  Matrix<T> inverse() {
    if (nRows_ != nCols_) {
      throw std::invalid_argument("Matrix must be square for inversion");
    }
    if (calculateDeterminant() < 1e-6) {
      throw std::runtime_error("Matrix is singular");
    }

    T d = 1 / calculateDeterminant();
    Matrix<T> Out(nRows_, nCols_);

    for (unsigned i = 0; i < nCols_; i++) {
      for (unsigned j = 0; j < nRows_; j++) {
        Out(i,j) = data_[i][j];
      }
    }

    Out = (Out.calculateCofactor()).transpose();

    for (unsigned i = 0; i < nCols_; i++) {
      for (unsigned j = 0; j < nRows_; j++) {
        Out(i,j) = Out(i,j) * d;
      }
    }
    return Out;
  }

 private:
  // Matrix Data
  unsigned nRows_;
  unsigned nCols_;
  std::vector<std::vector<T>> data_;

  // Calculate Matrix Determinant
  T calculateDeterminant() {
    // Check for Basic Cases
    unsigned size = nRows_;
    if (size == 0) {
      return 1;
    } else if (size == 1) {
      return data_[0][0];
    } else if (size == 2) {
      return ((data_[0][0] * data_[1][1]) - (data_[0][1] * data_[1][0]));
    }

    // Calculate general Result
    T result = 0;
    T sign = 1;
    for (unsigned i = 0; i < size; i++) {
      // Create Submatrix
      Matrix<T> subMatrix(size-1, size-1);
      for (unsigned j = 1; j < size; j++) {
        unsigned z = 0;
        for (unsigned k = 0; k < size; k++) {
          if (k != i) {
            subMatrix(j-1,z) = data_[j][k];
            z++;
          }
        }
      }

      // Recursion Call
      result = result + sign * data_[0][i] * subMatrix.calculateDeterminant();
      sign = -sign;
    }
    return result;
  }

  // Calculate Matrix Cofactor
  Matrix<T> calculateCofactor() {
    Matrix<T> result(nRows_, nCols_);
    Matrix<T> subMatrix(nRows_-1, nCols_-1);
    for (unsigned i = 0; i < nRows_; i++) {
      for (unsigned j = 0; j < nCols_; j++) {
        unsigned p = 0;
        for (unsigned k = 0; k < nRows_; k++) {
          if (k == i) {
            continue;
          }
          unsigned q = 0;
          for (unsigned l = 0; l < nRows_; l++) {
            if (l == j) {
              continue;
            }
            subMatrix(p,q) = data_[k][l];
            q++;
          }
          p++;
        }
        result(i,j) = std::pow(-1, i+j) * subMatrix.calculateDeterminant();
      }

    }
    return result;
  }
};
