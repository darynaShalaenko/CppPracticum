//20.09

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


template<class Container>
void print(const Container& a) {
    for (const auto& item: a) {
        cout<<item<<" ";
    }
    cout<<endl;
}

void filter(string filename1, string filename2) {
    set<string> ms1={""};
    set<string> ms2={""};
    
    ifstream finp1(filename1);
    if (!finp1.good())
        exit(1);
    while (finp1.good()) {
        string s1;
        getline(finp1, s1);
        if (finp1.fail())
            break;
        stringstream ss1;
        ss1<<s1;
        while (ss1.good()) {
            string word1;
            ss1>>word1;
            if (ss1.fail())
                break;
            ms1.insert(word1);
        }
    }
    finp1.close();
    
    ifstream finp2(filename2);
    if (!finp2.good())
        exit(1);
    while (finp2.good()) {
        string s2;
        getline(finp2, s2);
        if (finp2.fail())
            break;
        stringstream ss2;
        ss2<<s2;
        while (ss2.good()) {
            string word2;
            ss2>>word2;
            if (ss2.fail())
                break;
            ms2.insert(word2);
        }
    }
    finp2.close();
    
    //print(ms1);
    //print(ms2);
    
    cout<<endl<<"Common words: "<<endl;

    vector<string> v11(max(ms1.size(), ms2.size()));

    vector<string>::iterator it11=set_intersection(
        ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), v11.begin()
    );
    set<string> ms31(v11.begin(), it11);
    print(ms31);
    
    cout<<endl<<"Words that are not common: "<<endl;
    
    vector<string> v12(max(ms1.size(), ms2.size()));
    
    vector<string>::iterator it12=set_symmetric_difference(
        ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), v12.begin()
    );
    set<string> ms32(v12.begin(), it12);
    print(ms32);
}

int main() {
    filter("input1_20.09.txt","input2_20.09.txt");
    return 0;
}