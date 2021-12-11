#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    string line, temp = "";
    vector<int> v;
    ifstream F;
    F.open("input.txt", ios::in);
    int a,i,j,v1,n;
    while (getline(F, line)) {
        for (char c : line + " ") {
            if (isdigit(c)) {
                temp += c;
            } else if (temp.size() > 0) {
                a=atoi(temp.c_str());
                v.push_back(a);
                n=v.size();
                for (i=0; i<n-2; i++) {
                    for (j=1; j<n-1; j++) {
                        if (v[i]>v[j]){
                            //i=find(v.begin(), v.end(), v[i])
                            v1=v[i]*v[i];
                            v[i]=v1;
                            //cout<<v[i]<<endl;
                            //v.erase(i);
                            //v.insert(i,v1);
                        }   
                    }
                 }

                temp = "";
            }
        }
    }
    F.close();

    ofstream G;
    G.open("output.txt", ios::out);
    for (int i : v) {
        if (i >= 0)
            G << i << " ";
    }
    G.close();
    return 0;
}
