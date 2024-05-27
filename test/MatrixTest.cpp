/*
 * MatrixTest.cpp
 * Author: Parker Barrett
 * Overview: Unit tests for Matrix class.
 */

// Include Statements
#include "Matrix.h"
#include "gtest/gtest.h"

// Constructor: Default
TEST(MatrixConstructor, Default) {
  // Create Matrix Objects
  Matrix<int> matrixInt;
  Matrix<float> matrixFloat;
  Matrix<double> matrixDouble;

  // Check Matrix Size
  ASSERT_EQ(matrixInt.rows(), 0);
  ASSERT_EQ(matrixInt.cols(), 0);
  ASSERT_EQ(matrixFloat.rows(), 0);
  ASSERT_EQ(matrixFloat.cols(), 0);
  ASSERT_EQ(matrixDouble.rows(), 0);
  ASSERT_EQ(matrixDouble.cols(), 0);

}
