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
    

 private:
    // Matrix Data
    unsigned nRows_;
    unsigned nCols_;
    std::vector<std::vector<T>> data_;

};
