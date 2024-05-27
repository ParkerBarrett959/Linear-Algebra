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
      ASSERT_EQ(matrixInt(i, j), 0);
      ASSERT_EQ(matrixFloat(i, j), 0.0);
      ASSERT_EQ(matrixDouble(i, j), 0.0);
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
      ASSERT_EQ(matrixInt(i, j), 1);
      ASSERT_EQ(matrixFloat(i, j), 1.0);
      ASSERT_EQ(matrixDouble(i, j), 1.0);
    }
  }
}

// Matrix Addition
TEST(MatrixOperations, Addition) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<double> matrixDouble(2, 2, 1.0);

  // Perform Matrix Addition
  Matrix<int> matrixIntOut = matrixInt + matrixInt;
  Matrix<float> matrixFloatOut = matrixFloat + matrixFloat;
  Matrix<double> matrixDoubleOut = matrixDouble + matrixDouble;

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      ASSERT_EQ(matrixIntOut(i, j), 2);
      ASSERT_EQ(matrixFloatOut(i, j), 2.0);
      ASSERT_EQ(matrixDoubleOut(i, j), 2.0);
    }
  }
}

// Matrix Addition Exception
TEST(MatrixOperations, AdditionException) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<int> matrixInt2(3, 3);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<float> matrixFloat2(3, 3);
  Matrix<double> matrixDouble(2, 2, 1.0);
  Matrix<double> matrixDouble2(3, 3);

  // Integer Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<int> matrixIntOut = matrixInt + matrixInt2;
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Matrices must have same size", e.what());
          throw;
        }
      },
      std::invalid_argument);

  // Float Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<float> matrixFloatOut = matrixFloat + matrixFloat2;
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Matrices must have same size", e.what());
          throw;
        }
      },
      std::invalid_argument);

  // Double Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<double> matrixDoubleOut = matrixDouble + matrixDouble2;
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Matrices must have same size", e.what());
          throw;
        }
      },
      std::invalid_argument);
}

// Matrix Subtraction
TEST(MatrixOperations, Subtraction) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<double> matrixDouble(2, 2, 1.0);

  // Perform Matrix Subtraction
  Matrix<int> matrixIntOut = matrixInt - matrixInt;
  Matrix<float> matrixFloatOut = matrixFloat - matrixFloat;
  Matrix<double> matrixDoubleOut = matrixDouble - matrixDouble;

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      ASSERT_EQ(matrixIntOut(i, j), 0);
      ASSERT_EQ(matrixFloatOut(i, j), 0.0);
      ASSERT_EQ(matrixDoubleOut(i, j), 0.0);
    }
  }
}

// Matrix Subtraction Exception
TEST(MatrixOperations, SubtractionException) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<int> matrixInt2(3, 3);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<float> matrixFloat2(3, 3);
  Matrix<double> matrixDouble(2, 2, 1.0);
  Matrix<double> matrixDouble2(3, 3);

  // Integer Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<int> matrixIntOut = matrixInt - matrixInt2;
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Matrices must have same size", e.what());
          throw;
        }
      },
      std::invalid_argument);

  // Float Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<float> matrixFloatOut = matrixFloat - matrixFloat2;
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Matrices must have same size", e.what());
          throw;
        }
      },
      std::invalid_argument);

  // Double Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<double> matrixDoubleOut = matrixDouble - matrixDouble2;
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Matrices must have same size", e.what());
          throw;
        }
      },
      std::invalid_argument);
}

// Matrix Multiplication
TEST(MatrixOperations, Multiplication) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<double> matrixDouble(2, 2, 1.0);

  // Perform Matrix Multiplication
  Matrix<int> matrixIntOut = matrixInt * matrixInt;
  Matrix<float> matrixFloatOut = matrixFloat * matrixFloat;
  Matrix<double> matrixDoubleOut = matrixDouble * matrixDouble;

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      ASSERT_EQ(matrixIntOut(i, j), 2);
      ASSERT_EQ(matrixFloatOut(i, j), 2.0);
      ASSERT_EQ(matrixDoubleOut(i, j), 2.0);
    }
  }
}

// Matrix Multiplication Exception
TEST(MatrixOperations, MultiplicationException) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<int> matrixInt2(3, 3);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<float> matrixFloat2(3, 3);
  Matrix<double> matrixDouble(2, 2, 1.0);
  Matrix<double> matrixDouble2(3, 3);

  // Integer Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<int> matrixIntOut = matrixInt * matrixInt2;
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Invalid matrix sizes for multiplication", e.what());
          throw;
        }
      },
      std::invalid_argument);

  // Float Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<float> matrixFloatOut = matrixFloat * matrixFloat2;
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Invalid matrix sizes for multiplication", e.what());
          throw;
        }
      },
      std::invalid_argument);

  // Double Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<double> matrixDoubleOut = matrixDouble * matrixDouble2;
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Invalid matrix sizes for multiplication", e.what());
          throw;
        }
      },
      std::invalid_argument);
}

// Scalar Addition
TEST(ScalarOperations, Addition) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<double> matrixDouble(2, 2, 1.0);

  // Perform Scalar Addition
  Matrix<int> matrixIntOut = matrixInt + 2;
  Matrix<float> matrixFloatOut = matrixFloat + 2.0;
  Matrix<double> matrixDoubleOut = matrixDouble + 2.0;

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      ASSERT_EQ(matrixIntOut(i, j), 3);
      ASSERT_EQ(matrixFloatOut(i, j), 3.0);
      ASSERT_EQ(matrixDoubleOut(i, j), 3.0);
    }
  }
}

// Scalar Subtraction
TEST(ScalarOperations, Subtraction) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<double> matrixDouble(2, 2, 1.0);

  // Perform Scalar Subtraction
  Matrix<int> matrixIntOut = matrixInt - 2;
  Matrix<float> matrixFloatOut = matrixFloat - 2.0;
  Matrix<double> matrixDoubleOut = matrixDouble - 2.0;

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      ASSERT_EQ(matrixIntOut(i, j), -1);
      ASSERT_EQ(matrixFloatOut(i, j), -1.0);
      ASSERT_EQ(matrixDoubleOut(i, j), -1.0);
    }
  }
}

// Scalar Multiplication
TEST(ScalarOperations, Multiplication) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<double> matrixDouble(2, 2, 1.0);

  // Perform Scalar Multiplication
  Matrix<int> matrixIntOut = matrixInt * 2;
  Matrix<float> matrixFloatOut = matrixFloat * 2.0;
  Matrix<double> matrixDoubleOut = matrixDouble * 2.0;

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      ASSERT_EQ(matrixIntOut(i, j), 2);
      ASSERT_EQ(matrixFloatOut(i, j), 2.0);
      ASSERT_EQ(matrixDoubleOut(i, j), 2.0);
    }
  }
}

// Scalar Division
TEST(ScalarOperations, Division) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  Matrix<float> matrixFloat(2, 2, 1.0);
  Matrix<double> matrixDouble(2, 2, 1.0);

  // Perform Scalar Division
  Matrix<int> matrixIntOut = matrixInt / 2;
  Matrix<float> matrixFloatOut = matrixFloat / 2.0;
  Matrix<double> matrixDoubleOut = matrixDouble / 2.0;

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      ASSERT_EQ(matrixIntOut(i, j), 0);
      ASSERT_EQ(matrixFloatOut(i, j), 0.5);
      ASSERT_EQ(matrixDoubleOut(i, j), 0.5);
    }
  }
}

// Matrix Transpose
TEST(MatrixOperations, Transpose) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 1);
  matrixInt(0, 1) = 2;
  matrixInt(1, 0) = 3;
  matrixInt(1, 1) = 4;
  Matrix<float> matrixFloat(2, 2, 1.0);
  matrixFloat(0, 1) = 2;
  matrixFloat(1, 0) = 3;
  matrixFloat(1, 1) = 4;
  Matrix<double> matrixDouble(2, 2, 1.0);
  matrixDouble(0, 1) = 2;
  matrixDouble(1, 0) = 3;
  matrixDouble(1, 1) = 4;

  // Perform Scalar Division
  Matrix<int> matrixIntOut = matrixInt.transpose();
  Matrix<float> matrixFloatOut = matrixFloat.transpose();
  Matrix<double> matrixDoubleOut = matrixDouble.transpose();

  // Check Integer Matrix Values
  EXPECT_EQ(matrixIntOut(0, 0), 1);
  EXPECT_EQ(matrixIntOut(0, 1), 3);
  EXPECT_EQ(matrixIntOut(1, 0), 2);
  EXPECT_EQ(matrixIntOut(1, 1), 4);

  // Check Float Matrix Values
  EXPECT_EQ(matrixFloatOut(0, 0), 1.0);
  EXPECT_EQ(matrixFloatOut(0, 1), 3.0);
  EXPECT_EQ(matrixFloatOut(1, 0), 2.0);
  EXPECT_EQ(matrixFloatOut(1, 1), 4.0);

  // Check Double Matrix Values
  EXPECT_EQ(matrixDoubleOut(0, 0), 1.0);
  EXPECT_EQ(matrixDoubleOut(0, 1), 3.0);
  EXPECT_EQ(matrixDoubleOut(1, 0), 2.0);
  EXPECT_EQ(matrixDoubleOut(1, 1), 4.0);
}

// Matrix Inversion: 1x1 Matrix Case

// Matrix Inversion: 2x2 Matrix Case

// Matrix inversion: General Case

// Matrix Inversion 0 Determinant Exception
TEST(MatrixOperations, InverseZeroDeterminantException) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 6);
  matrixInt(0, 1) = 4;
  matrixInt(1, 0) = 3;
  matrixInt(1, 1) = 2;
  Matrix<float> matrixFloat(2, 2, 6.0);
  matrixFloat(0, 1) = 4;
  matrixFloat(1, 0) = 3;
  matrixFloat(1, 1) = 2;
  Matrix<double> matrixDouble(2, 2, 6.0);
  matrixDouble(0, 1) = 4;
  matrixDouble(1, 0) = 3;
  matrixDouble(1, 1) = 2;

  // Integer Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<int> matrixIntOut = matrixInt.inverse();
        } catch (const std::runtime_error& e) {
          EXPECT_STREQ("Matrix is singular", e.what());
          throw;
        }
      },
      std::runtime_error);

  // Float Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<float> matrixFloatOut = matrixFloat.inverse();
        } catch (const std::runtime_error& e) {
          EXPECT_STREQ("Matrix is singular", e.what());
          throw;
        }
      },
      std::runtime_error);

  // Double Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<double> matrixDoubleOut = matrixDouble.inverse();
        } catch (const std::runtime_error& e) {
          EXPECT_STREQ("Matrix is singular", e.what());
          throw;
        }
      },
      std::runtime_error);
}

// Matrix Inversion Size Exception
TEST(MatrixOperations, InverseNonSquareException) {
  // Create Matrix Objects
  Matrix<int> matrixInt(3, 2, 1);
  Matrix<float> matrixFloat(3, 2, 1.0);
  Matrix<double> matrixDouble(3, 2, 1.0);

  // Integer Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<int> matrixIntOut = matrixInt.inverse();
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Matrix must be square for inversion", e.what());
          throw;
        }
      },
      std::invalid_argument);

  // Float Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<float> matrixFloatOut = matrixFloat.inverse();
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Matrix must be square for inversion", e.what());
          throw;
        }
      },
      std::invalid_argument);

  // Double Matrix Exception
  EXPECT_THROW(
      {
        try {
          Matrix<double> matrixDoubleOut = matrixDouble.inverse();
        } catch (const std::invalid_argument& e) {
          EXPECT_STREQ("Matrix must be square for inversion", e.what());
          throw;
        }
      },
      std::invalid_argument);
}