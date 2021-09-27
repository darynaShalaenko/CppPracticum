#include <iostream>
#include "Matrix.hpp"

Matrix<bool> in() {
    unsigned n, m;
    std::cout << "Enter n and m: ";
    std::cin >> n >> m;
    Matrix<bool> matrix(n, m);
    for(unsigned i = 0; i < n; i++) {
        std::cout << "Row " << (i+1) << ". ";
        std::cout << "Enter " << m << " elements: ";
        for(unsigned j = 0; j < m; j++)
            std::cin >> matrix.at(i, j);
    }
    return matrix;
}

unsigned calc(const Matrix<bool> &matrix) {
    unsigned max = 0;
    for(unsigned i0 = 0; i0 < matrix.rows(); i0++) {
        for(unsigned j0 = 0; j0 < matrix.columns(); j0++) {
            if(matrix.at(i0, j0)) {
                unsigned length = 1, height = 1;
                for(unsigned j1 = (j0 + 1); j1 < matrix.columns(); j1++) {
                    if(matrix.at(i0, j1))
                        length++;
                    else
                        break;
                }
                for(unsigned i1 = (i0 + 1); i1 < matrix.rows(); i1++) {
                    if(matrix.at(i1, j0)) {
                        unsigned currentLength = 1;
                        for(unsigned j2 = (j0 + 1); j2 < (j0 + length); j2++) {
                            if(matrix.at(i1, j2))
                                currentLength++;
                            else 
                                break;
                        }
                        if(currentLength < length)
                            length = currentLength;
                        height++;
                    }
                    else 
                        break;
                }
                unsigned square = length * height;
                if(square > max)
                    max = square;
            }
        }
    }
    return max;
}

void out(unsigned res) {
    std::cout << "res: " << res << std::endl;
}

int main() {
    Matrix<bool> matrix = in();
    unsigned res = calc(matrix);
    out(res);
    return 0;
}