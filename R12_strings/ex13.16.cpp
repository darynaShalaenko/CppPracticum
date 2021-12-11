//13.16

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int num_of_art(const string& s) {
    int count=0;
    stringstream ss;
    ss<<s;
    while (ss.good()) {
        string word;
        ss>>word;
        if (ss.fail())
            break;
        if (word=="a" || word=="an" || word=="the")
            count++;
    }
    return count;
}

void get_index(int *arr2, int n, const string& s) {
    int count=-1;
    int i=-1;
    stringstream ss;
    ss<<s;
    while (ss.good()) {
        i++;
        string word;
        ss>>word;
        if (ss.fail())
            break;
        if (word=="a" || word=="an" || word=="the") {
            count++;
            *(arr2+count)=i+1;
        }
    }
}

int num_of_words(const string& s) {
    int count=0;
    stringstream ss;
    ss<<s;
    while (ss.good()) {
        string word;
        ss>>word;
        if (ss.fail())
            break;
        count++;
    }
    return count;
}

void create_arr_of_words(string *arr1, int n, const string& s) {
    int count=-1;
    stringstream ss;
    ss<<s;
    while (ss.good()) {
        count++;
        string word;
        ss>>word;
        if (ss.fail())
            break;
        *(arr1+count)=word;
    }
}

void to_upper(string *arr1, int n1, int *arr2, int n2, const string& s) {
    for (int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            if (i==*(arr2+j)){
                (*(arr1+i)).front()=toupper((*(arr1+i)).front());
            }
        }
    }
}

void print(string *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}


int main() {
    string s="I had a dream last night  my father is an engineer  the water is too hot";
    
    int na=num_of_art(s);
    int *arra=new int[na];
    get_index(arra,na,s);
    
    int nw=num_of_words(s);
    string *arrw=new string[nw];
    create_arr_of_words(arrw,nw,s);
    
    to_upper(arrw,nw,arra,na,s);
    
    print(arrw,nw);
    return 0;
}