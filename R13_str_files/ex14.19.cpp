//14.19

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void find_words(const char c, const char* filename, const char* filename1) {
    string arr[300];
    ifstream finp(filename);
    if (!finp.good())
        exit(1);
    int j=0;
    while (finp.good()) {
        string s;
        getline(finp, s);
        if (finp.fail())
            break;
        stringstream ss;
        ss << s;
        while (ss.good()) {
            string word;
            ss >> word;
            if (ss.fail())
                break;
            if (word.front()==c || word.front()==toupper(c)) {
                arr[j]=word;
                j++;
            }
        }
    }
    finp.close();
    
    ofstream fout(filename1);
    for (int i=0;i<j;i++) {
        fout<<arr[i]<<" ";
    }
    fout.close();
}

int main() {
    find_words('b',"input14.19.txt","output14.19.txt");
    return 0;
}