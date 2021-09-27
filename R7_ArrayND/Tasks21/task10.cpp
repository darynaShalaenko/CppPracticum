#include <iostream>
#include "Matrix.hpp"

Matrix<double> in() {
    unsigned n;
    std::cout << "Enter n: ";
    std::cin >> n;
    Matrix<double> matrix(n, n);
    for(unsigned i = 0; i < n; i++) {
        std::cout << "Row " << (i+1) << ". ";
        std::cout << "Enter " << n << " elements: ";
        for(unsigned j = 0; j < n; j++)
            std::cin >> matrix.at(i, j);
    }
    return matrix;
}

Matrix<double> invert(const Matrix<double> &matrix) {
    unsigned n = matrix.rows();
    Matrix<double> result(n, n);
    for(unsigned i = 0; i < n; i++)
        result.at(i, i) = 1;
    Matrix<double> big(n, 2*n);
    for(unsigned i = 0; i < n; i++) {
        for(unsigned j = 0; j < n; j++) {
            big.at(i, j) = matrix.at(i, j);
            big.at(i, (j + n)) = result.at(i, j);
        }
    }
    for(unsigned k = 0; k < n; k++) {
        for(unsigned i = 0; i < 2*n; i++)
            big.at(k, i) = big.at(k, i) / matrix.at(k, k);
        for(unsigned i = k + 1; i < n; i++) {
            double K = big.at(i, k) / big.at(k, k);
            for(unsigned j = 0; j < 2*n; j++)
                big.at(i, j) = big.at(i, j) - ( big.at(k, j) * K );
        }
        for(unsigned i = 0; i < n; i++)
            for(unsigned j = 0; j < n; j++)
                matrix.at(i, j) = big.at(i, j);
    }
    for(int k = n - 1; k > -1; k--) {
        for(int i = 2*n - 1; i > -1; i--)
            big.at(k, i) = big.at(k, i) / matrix.at(k, k);
        for(int i = k - 1; i > -1; i--) {
            double K = big.at(i, k) / big.at(k, k);
            for(int j = 2*n - 1; j > -1; j--)
                big.at(i, j) = big.at(i, j) - ( big.at(k, j) * K );
        }
    }
    for(unsigned i = 0; i < n; i++)
        for(unsigned j = 0; j < n; j++)
            result.at(i, j) = big.at(i, (j + n));
    return result;
}

void out(const Matrix<double> &matrix) {
    std::cout << "Result matrix: " << std::endl;
    for(unsigned i = 0; i < matrix.rows(); i++) {
        std::cout << "( ";
        for(unsigned j = 0; j < matrix.columns(); j++) {
            std::cout << matrix.at(i, j);
            if((j + 1) != matrix.columns())
                std::cout << " ";
        }
        std::cout << " )";
        std::cout << std::endl;
    }
}

int main() {
    Matrix<double> matrix = in();
    Matrix<double> result = invert(matrix);
    out(result);
}