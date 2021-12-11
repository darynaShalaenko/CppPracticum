#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int32_t a1,b1;
    cin>>a1>>b1;
    int32_t res1;
    res1=a1+b1;
    if (abs(res1)>2147483647) cout<<"Переповнення типу!"<<endl;
    else cout<<"Cума = "<<res1<<endl;
    
    int32_t a2,b2;
    cin>>a2>>b2;
    int64_t res2;
    res2=a2*b2;
    if (abs(res2)>2147483647) cout<<"Переповнення типу!"<<endl;
    else cout<<"Добуток = "<<res2<<endl;
    return 0;
}
