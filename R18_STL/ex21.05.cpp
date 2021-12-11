//21.05

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string line;
    cout<<"Enter the line -> ";
    getline(cin,line);
    transform(
            line.begin(), line.end(), line.begin(), [](char l) {return toupper(l);}
        );
    cout<<line<<endl;

    return 0;
}