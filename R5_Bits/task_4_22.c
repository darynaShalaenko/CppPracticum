#include <iostream>

using namespace std;

int main()
{
    cout<<"n=? k=? ";
    int c,k;
    cin>>c>>k;
    unsigned char n=c, p=255;

    n=n<<(8-k);
    n=n>>(8-k);
    p=p<<(k);

    unsigned char res=n|p;
    cout<<(int)res;

    return 0;
} 
