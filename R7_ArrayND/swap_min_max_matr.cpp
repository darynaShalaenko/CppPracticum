#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

int main() {
    double min, max;
    int n, m, max_column, min_column, ans;
    cout << "Input number of rows:";
    cin >> n;
    cout << "Input number of columns:";
    cin >> m;
    cout << "File or random(1 - file| 0 - rand):";
    cin >> ans;
    double array[n][m];
    if(ans == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                array[i][j] = rand() % 100 + (-10);
            }
        }
        min = array[0][0];
        max = array[0][0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (min > array[i][j]) {
                    min = array[i][j];
                    min_column = j;
                }
                if (max < array[i][j]) {
                    max = array[i][j];
                    max_column = j;
                }
            }
        }
        cout << "Un swapped matrix:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; ++i)
        {
                swap(array[i][min_column], array[i][max_column]);
        }

        cout << "Swapped matrix:" << endl;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }

    else {
        fstream file("../test.txt");
        if (!file.is_open())
        {
            cout << "I can't find file." << endl;
        }
        else
        {
            if(n > 2 || m > 5)
            {
                throw ("size error");
            }
            int min_element[2];
            int max_element[2];
            int num;
            file >> num;

            array[0][0] = num;

            // first collum
            min_element[0] = array[0][0];
            min_element[1] = 0;

            max_element[0] = array[0][0];
            max_element[1] = 0;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if (i > 0 || j > 0) {
                        file >> num;
                        array[i][j] = num;

                        if (num < min_element[0]) {
                            min_element[0] = num;
                            min_element[1] = j;
                        }

                        if (num > max_element[0]) {
                            max_element[0] = num;
                            max_element[1] = j;
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++){
                swap(array[i][min_element[1]], array[i][max_element[1]]);
            }

            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++) {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}