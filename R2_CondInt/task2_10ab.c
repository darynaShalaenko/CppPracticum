#include <iostream>
using namespace std;

int main1()
{
    int x,y,z;
    cin >> x >> y >> z;
    int k = 0;
    if (x==y && y==z){
        k = 3;
    }
    else if ((x==y && x!=z) || (y==z && x!=y) || (x==z && x!=y)){
        k = 2;
    }
    cout <<k <<endl;
    return 0;
}

int main()
{
    int x,y,z;
    cin >> x >> y >> z;

    int a;
    cin >> a;

    int k = 0;
    if (x>a && y>a && z>a){
        k = 3;
    }
    else if((x>a && y>a && z<a) || (x>a && z>a && y<a) || (y>a && z>a && x<a)){
        k = 2;
    }
    else if((x>a && y<a && z<a) || (x<a && z<a && y>a) || (y<a && z>a && x<a)){
        k = 1;
    }
    cout <<k <<endl;
    return 0;
}
