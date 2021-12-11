
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    string line;
    ifstream infile("F.txt");
    ofstream outfile1("H.txt");
    ofstream outfile2("G.txt");
    string ans="";
    string word="";
    string text;
    char sym;
    if(infile.is_open()){
        while (getline(infile,text,'\n')) {
            if(text.size()%2==0){
                outfile2<<text<<"\n";
            }
            else{
                outfile1<<text<<"\n";
            }
        }
        infile.close();
    }
    outfile1.close();
    outfile2.close();
    return 0;
}
