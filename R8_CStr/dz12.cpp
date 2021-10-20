#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count1=0, count_max=0;
    char a, b;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j]) {
                a = s[i];
                count1++;
            }
        }
        if (count1 > count_max) {
            count_max = count1;
            b = a;
        }

        count1 = 0;
    }
    cout<<"Max:" << b << count_max<<endl;
    
}

