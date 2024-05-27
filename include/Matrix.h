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

    // Constuct Matrix of Size with Specific Value
    Matrix(unsigned rows, unsigned cols, T val = 0) :
        nRows_(rows), nCols_(cols) {
	data_resize(nRows_);
        for (unsigned i = 0; i < data_.size(); i++) {
	    data_[i].resize(nCols_, val);
	}
    }

    // Destructor
    ~Matrix() {}

 private:
    // Matrix Data
    unsigned nRows_;
    unsigned nCols_;
    std::vector<std::vector<T>> data_;

};
