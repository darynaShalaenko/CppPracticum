//19.12

#include <iostream>
#include <vector>
using namespace std;


template<class T>
class Matrix {

public:
    vector<vector<T>> matrix;
    int n;
    int m;
    Matrix() {}
    Matrix(int n1,int m1) {
        n=n1;
        m=m1;
    }
    Matrix(const Matrix& matrix1) {
        n=matrix1.n;
        m=matrix1.m;
        vector<T> row;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                row.push_back(matrix1.matrix[i][j]);
            }
            matrix.push_back(row);
            row.clear();
        }
    }
    
    void input() {
        vector<T> row;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                T item;
                cin>>item;
                row.push_back(item);
            }
            matrix.push_back(row);
            row.clear();
        }
    }
    void print(ostream& out=cout) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                out<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    friend ostream& operator<<(ostream& out, Matrix& matrix) {
        matrix.print(out);
        return out;
    }
    Matrix operator+(const Matrix& other) {
        if (n!=other.n || m!=other.m) {
            throw logic_error("These matrices can`t be added!");
        }
        Matrix sum(n,m);
        vector<T> row;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                T item;
                item=matrix[i][j]+other.matrix[i][j];
                row.push_back(item);
            }
            sum.matrix.push_back(row);
            row.clear();
        }
        return sum;
    }
    Matrix operator*(const Matrix& other) {
        if (m!=other.n) {
            throw logic_error("These matrices can`t be multiplied!");
        }
        Matrix product(n,other.m);
        vector<T> row;
        for (int i=0; i<n; i++) {
            for (int j=0; j<other.m; j++) {
                T item;
                item=0;
                for (int k=0; k<m; k++) {
                    item+=matrix[i][k]*other.matrix[k][j];
                }
                row.push_back(item);
            }
            product.matrix.push_back(row);
            row.clear();
        }
        return product;
    }
    
};


int main() {
    Matrix<int> one(2,3);
    Matrix<int> two(3,2);
    one.input();
    two.input();
    Matrix<int> three;
    three=one+two;
    cout<<three<<endl;
    return 0;
}