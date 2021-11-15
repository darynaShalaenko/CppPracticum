#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin;
using std::endl; using std::string;
//using std::vector; using std::istringstream;

int parseWords(string s, string delim, int n, string words[]){
    size_t pos = 0;
    size_t k =0;
    while ((pos = s.find(delim)) != string::npos && k<n) {
        //words.push_back(text.substr(0, pos));
        words[k++] = s.substr(0, pos);
        s.erase(0, pos + delim.length());
    }
    return k;		
}


int main(){
    string text = "He said. The challenge Hector heard with joy, "
               "Then with his spear restrain'd the youth of Troy ";
    string delim = " ";
    //vector<string> words{};
    size_t k,n=10; 
	
    string words[n]; 
    /*size_t pos = 0;
    while ((pos = text.find(delim)) != string::npos && k<n) {
        //words.push_back(text.substr(0, pos));
        words[k++] = text.substr(0, pos);
        text.erase(0, pos + delim.length());
    }*/
    int m = parseWords(text,delim, 7, words);	

    for (int i=0;i<m;++i) {
        cout << words[i] << endl;
    }



    return 0;
}

