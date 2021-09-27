#ifndef MATRIX
#define MATRIX

#include <string>
#include <sstream>

template<class Type>
class Matrix {
private:
    unsigned n;
    unsigned m;
    Type **data;
public:
    Matrix(unsigned n, unsigned m) {
        this->n = n;
        this->m = m;
        this->data = new Type*[n];
        for(unsigned i = 0; i < n; i++)
            this->data[i] = new Type[m];
    }
    unsigned rows() const {
        return this->n;
    }
    unsigned columns() const {
        return this->m;
    }
    Type& at(unsigned i, unsigned j) const {
        return this->data[i][j];
    }
    std::string to_string() const {
        std::stringstream ss;
        ss << "[";
        for(unsigned i = 0; i < this->n; i++) {
            ss << "[";
            for(unsigned j = 0; j < this->m; j++) {
                ss << this->data[i][j];
                if((j + 1) != this->m)
                    ss << ", ";
            }
            ss << "]";
            if((i + 1) != this->m)
                ss << ", ";
        }
        ss << "]";
        return ss.str();
    }
    ~Matrix() {
        for(unsigned i = 0; i < this->n; i++)
            delete[] this->data[i];
        delete[] this->data;
    }
};

#endif //MATRIX