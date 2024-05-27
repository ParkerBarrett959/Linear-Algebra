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

// Constructor: Default Value
TEST(MatrixConstructor, DefaultValue) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2);
  Matrix<float> matrixFloat(2, 2);
  Matrix<double> matrixDouble(2, 2);

  // Check Matrix Size
  ASSERT_EQ(matrixInt.rows(), 2);
  ASSERT_EQ(matrixInt.cols(), 2);
  ASSERT_EQ(matrixFloat.rows(), 2);
  ASSERT_EQ(matrixFloat.cols(), 2);
  ASSERT_EQ(matrixDouble.rows(), 2);
  ASSERT_EQ(matrixDouble.cols(), 2);

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      ASSERT_EQ(matrixInt(i,j), 0);
      ASSERT_EQ(matrixFloat(i,j), 0.0);
      ASSERT_EQ(matrixDouble(i,j), 0.0);
    }
  }
}

// Constructor: Set Value
TEST(MatrixConstructor, SetValue) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<double> matrixDouble(2, 2, 1.0);

  // Check Matrix Size
  ASSERT_EQ(matrixInt.rows(), 2);
  ASSERT_EQ(matrixInt.cols(), 2);
  ASSERT_EQ(matrixFloat.rows(), 2);
  ASSERT_EQ(matrixFloat.cols(), 2);
  ASSERT_EQ(matrixDouble.rows(), 2);
  ASSERT_EQ(matrixDouble.cols(), 2);

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      ASSERT_EQ(matrixInt(i,j), 1);
      ASSERT_EQ(matrixFloat(i,j), 1.0);
      ASSERT_EQ(matrixDouble(i,j), 1.0);
    }
  }
}
