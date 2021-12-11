#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int zeroline(string name){
    ifstream is(name);
    string line;
    int n=0;
    while (!is.eof()) {
        getline(is, line);
        if (line.length() == 0) n++;
    }
    return n;
}

int maxlength(string name){
    ifstream is(name);
    string line;
    int maxlen=0;
    while (!is.eof()) {
        getline(is, line);
        if (line.length() > maxlen) maxlen==line.length();
    }
    return maxlen;
}



int main()
{
    cout<<zeroline("C:\\Input\\input.txt");
    cout<<maxlength("C:\\Input\\input.txt");
    return 0;
} 
