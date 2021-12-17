#include <iostream>

using namespace std;

int quick_1(long long s)
{
    if(s<0) {s=-s;}
    //cout<<s;
    int mas[10]={0},et=0;
    long long s_res=s;
    while(s!=0){
        mas[s%10]+=1;
        //cout<<s%10;
        s=s/10;
    }

    for(int i=0;i<10;i++ )
    {
        if (mas[i]>mas[et])
        {
            et=i;
        }

    }

    int et_res=et;
    while(s_res!=0){

        if(mas[s_res%10]==mas[et]) {//cout<<et_res;
                s_res=s_res%10;

        }
        s_res=s_res/10;

    }
    return et_res;


}

int main()
{
    cout<<333444555<<": "<<quick_1(333444555)<<" "<<2123456789 <<": "<<quick_1(2123456789)<<" "<<-123456789<<": "<<quick_1(-123456789)<<" "<<-123456789324567<<": "<<quick_1(-123456789324567);
    return 0;
}
