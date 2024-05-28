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

// Zeros Matrix
TEST(MatrixCreator, Zeros) {
  // Create Matrix Objects
  Matrix<int> matrixInt = Matrix<int>::Zeros(2, 2);
  Matrix<float> matrixFloat = Matrix<float>::Zeros(2, 2);
  Matrix<double> matrixDouble = Matrix<double>::Zeros(2, 2);

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

// Ones Matrix
TEST(MatrixCreator, Ones) {
  // Create Matrix Objects
  Matrix<int> matrixInt = Matrix<int>::Ones(2, 2);
  Matrix<float> matrixFloat = Matrix<float>::Ones(2, 2);
  Matrix<double> matrixDouble = Matrix<double>::Ones(2, 2);

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

// Identity Matrix
TEST(MatrixCreator, Identity) {
  // Create Matrix Objects
  Matrix<int> matrixInt = Matrix<int>::Identity(3);
  Matrix<float> matrixFloat = Matrix<float>::Identity(3);
  Matrix<double> matrixDouble = Matrix<double>::Identity(3);

  // Check Matrix Size
  ASSERT_EQ(matrixInt.rows(), 3);
  ASSERT_EQ(matrixInt.cols(), 3);
  ASSERT_EQ(matrixFloat.rows(), 3);
  ASSERT_EQ(matrixFloat.cols(), 3);
  ASSERT_EQ(matrixDouble.rows(), 3);
  ASSERT_EQ(matrixDouble.cols(), 3);

  // Check Matrix Values
  for (unsigned i = 0; i < 3; i++) {
    for (unsigned j = 0; j < 3; j++) {
      if (i == j) {
        ASSERT_EQ(matrixInt(i, j), 1);
        ASSERT_EQ(matrixFloat(i, j), 1.0);
        ASSERT_EQ(matrixDouble(i, j), 1.0);
      } else {
        ASSERT_EQ(matrixInt(i, j), 0);
        ASSERT_EQ(matrixFloat(i, j), 0.0);
        ASSERT_EQ(matrixDouble(i, j), 0.0);
      }
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
TEST(MatrixOperations, Inverse1x1) {
  // Create Matrix Objects
  Matrix<int> matrixInt(1, 1, 5);
  Matrix<float> matrixFloat(1, 1, 5.0);
  Matrix<double> matrixDouble(1, 1, 5.0);

  // Perform Scalar Division
  Matrix<int> matrixIntOut = matrixInt.inverse();
  Matrix<float> matrixFloatOut = matrixFloat.inverse();
  Matrix<double> matrixDoubleOut = matrixDouble.inverse();

  // Check Integer Matrix Values
  EXPECT_EQ(matrixIntOut(0, 0), 0);

  // Check Float Matrix Values
  EXPECT_NEAR(matrixFloatOut(0, 0), 0.2, 1e-6);

  // Check Double Matrix Values
  EXPECT_EQ(matrixDoubleOut(0, 0), 0.2);
}

// Matrix Inversion: 2x2 Matrix Case
TEST(MatrixOperations, Inverse2x2) {
  // Create Matrix Objects
  Matrix<int> matrixInt(2, 2, 5);
  matrixInt(0, 1) = 2;
  matrixInt(1, 0) = -7;
  matrixInt(1, 1) = -3;
  Matrix<float> matrixFloat(2, 2, 5.0);
  matrixFloat(0, 1) = 2;
  matrixFloat(1, 0) = -7;
  matrixFloat(1, 1) = -3;
  Matrix<double> matrixDouble(2, 2, 5.0);
  matrixDouble(0, 1) = 2;
  matrixDouble(1, 0) = -7;
  matrixDouble(1, 1) = -3;

  // Perform Scalar Division
  Matrix<int> matrixIntOut = matrixInt.inverse();
  Matrix<float> matrixFloatOut = matrixFloat.inverse();
  Matrix<double> matrixDoubleOut = matrixDouble.inverse();

  // Check Integer Matrix Values
  EXPECT_EQ(matrixIntOut(0, 0), 3);
  EXPECT_EQ(matrixIntOut(0, 1), 2);
  EXPECT_EQ(matrixIntOut(1, 0), -7);
  EXPECT_EQ(matrixIntOut(1, 1), -5);

  // Check Float Matrix Values
  EXPECT_NEAR(matrixFloatOut(0, 0), 3.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(0, 1), 2.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(1, 0), -7.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(1, 1), -5.0, 1e-6);

  // Check Double Matrix Values
  EXPECT_EQ(matrixDoubleOut(0, 0), 3.0);
  EXPECT_EQ(matrixDoubleOut(0, 1), 2.0);
  EXPECT_EQ(matrixDoubleOut(1, 0), -7.0);
  EXPECT_EQ(matrixDoubleOut(1, 1), -5.0);
}

// Matrix inversion: General Case
TEST(MatrixOperations, InverseGeneral) {
  // Create Matrix Objects
  Matrix<int> matrixInt(3, 3);
  matrixInt(0, 1) = -3;
  matrixInt(0, 2) = -2;
  matrixInt(1, 0) = 1;
  matrixInt(1, 1) = -4;
  matrixInt(1, 2) = -2;
  matrixInt(2, 0) = -3;
  matrixInt(2, 1) = 4;
  matrixInt(2, 2) = 1;
  Matrix<float> matrixFloat(3, 3);
  matrixFloat(0, 1) = -3;
  matrixFloat(0, 2) = -2;
  matrixFloat(1, 0) = 1;
  matrixFloat(1, 1) = -4;
  matrixFloat(1, 2) = -2;
  matrixFloat(2, 0) = -3;
  matrixFloat(2, 1) = 4;
  matrixFloat(2, 2) = 1;
  Matrix<double> matrixDouble(3, 3);
  matrixDouble(0, 1) = -3;
  matrixDouble(0, 2) = -2;
  matrixDouble(1, 0) = 1;
  matrixDouble(1, 1) = -4;
  matrixDouble(1, 2) = -2;
  matrixDouble(2, 0) = -3;
  matrixDouble(2, 1) = 4;
  matrixDouble(2, 2) = 1;

  // Perform Scalar Division
  Matrix<int> matrixIntOut = matrixInt.inverse();
  Matrix<float> matrixFloatOut = matrixFloat.inverse();
  Matrix<double> matrixDoubleOut = matrixDouble.inverse();

  // Check Integer Matrix Values
  EXPECT_EQ(matrixIntOut(0, 0), 4);
  EXPECT_EQ(matrixIntOut(0, 1), -5);
  EXPECT_EQ(matrixIntOut(0, 2), -2);
  EXPECT_EQ(matrixIntOut(1, 0), 5);
  EXPECT_EQ(matrixIntOut(1, 1), -6);
  EXPECT_EQ(matrixIntOut(1, 2), -2);
  EXPECT_EQ(matrixIntOut(2, 0), -8);
  EXPECT_EQ(matrixIntOut(2, 1), 9);
  EXPECT_EQ(matrixIntOut(2, 2), 3);

  // Check Float Matrix Values
  EXPECT_NEAR(matrixFloatOut(0, 0), 4.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(0, 1), -5.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(0, 2), -2.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(1, 0), 5.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(1, 1), -6.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(1, 2), -2.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(2, 0), -8.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(2, 1), 9.0, 1e-6);
  EXPECT_NEAR(matrixFloatOut(2, 2), 3.0, 1e-6);

  // Check Double Matrix Values
  EXPECT_EQ(matrixDoubleOut(0, 0), 4.0);
  EXPECT_EQ(matrixDoubleOut(0, 1), -5.0);
  EXPECT_EQ(matrixDoubleOut(0, 2), -2.0);
  EXPECT_EQ(matrixDoubleOut(1, 0), 5.0);
  EXPECT_EQ(matrixDoubleOut(1, 1), -6.0);
  EXPECT_EQ(matrixDoubleOut(1, 2), -2.0);
  EXPECT_EQ(matrixDoubleOut(2, 0), -8.0);
  EXPECT_EQ(matrixDoubleOut(2, 1), 9.0);
  EXPECT_EQ(matrixDoubleOut(2, 2), 3.0);
}

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

// Matrix Types
TEST(MatrixTypes, Generic) {
  // Create Matrix Objects
  Matrixi matrixInt(2, 2);
  Matrixf matrixFloat(2, 2);
  Matrixd matrixDouble(2, 2);

  // Check Matrix Values
  for (unsigned i = 0; i < 2; i++) {
    for (unsigned j = 0; j < 2; j++) {
      EXPECT_EQ(matrixInt(i,j), 0);
      EXPECT_EQ(matrixFloat(i,j), 0);
      EXPECT_EQ(matrixDouble(i,j), 0);
    }
  }
}
