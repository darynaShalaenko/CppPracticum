#include <iostream>

using namespace std;
bool check(int n1, int n2){          //не имеют одинакових битов например 106 и 149
    char a=n1, b=n2;
    for (int i=0; i<8; i++){
        if ((((1<<i)&a)^((1<<i)&b))==0) return false;
    }
    return true;
}


int main()
{
    cout<<"n1=? n2=? ";
    int n1,n2;
    cin>>n1>>n2;

    cout<<check(n1,n2);

    return 0;
}
