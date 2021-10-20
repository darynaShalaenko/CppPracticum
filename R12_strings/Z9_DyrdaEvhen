#8г
#check if the sum of all numbers in a string is equal to the length of the string


#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    stringstream ss(str);
    stringstream result;
    double number, sum = 0;
    while(ss >> number)
    {
        sum+=number;
        result << (number<0?"":"+") << number;
    }
    result << "=" << sum;
    string resStr  = result.str();
    if(resStr[0]=='+')
        resStr.erase(0, 1);
    cout << resStr == str.length();
    cout<<endl;
    return 0;
}
