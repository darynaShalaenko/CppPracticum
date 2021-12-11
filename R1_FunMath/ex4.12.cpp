#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    float x;
    cout<<"n-->";
    cin>>n;
    cout<<"x-->";
    cin>>x;
    float y=1;
    int i=1;
    while (i<=n) 
    {
        y+=pow(x,pow(2,i));
        i+=1;
    }
    cout<<y<<endl;
    return 0;
}
