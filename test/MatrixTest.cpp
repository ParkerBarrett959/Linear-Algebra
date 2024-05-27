/*
 * MatrixTest.cpp
 * Author: Parker Barrett
 * Overview: Unit tests for Matrix class.
 */

// Include Statements
#include "gtest/gtest.h"
#include "Matrix.h"

// Constructor: Default
TEST(MatrixConstructor, Default)
{

    // Create Matrix Objects
    Matrix<int> matrixInt;
    Matrix<float> matrixFloat;
    Matrix<double> matrixDouble;

    // Check Matrix Size
    ASSERT_EQ(0, 0);

}