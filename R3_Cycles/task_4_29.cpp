#include <iostream>
#include <math.h>
using namespace std;

bool check(int x, int a, int b, int c, int d){
    return a*pow(x,3)+b*pow(x,2)+c*x+d==0;
}

void divisors(int a, int b, int c, int d)
{
	for (int i=1; i<=sqrt(abs(d)); i++)
	{
		if (d%i == 0)
		{
			if (check(i,a,b,c,d)) cout <<" "<< i;
			if (check(-i,a,b,c,d)) cout <<" "<< -i;
			if (abs(d)/i !=i ) {
			    if (check(d/i,a,b,c,d)) cout <<" "<< d/i;
			    if (check(-d/i,a,b,c,d)) cout <<" "<<-d/i;
			}
		}
	}
}

int main()
{
	cout << " a=? b=? c=? d=? ";
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    divisors(a,b,c,d);
	return 0;
}
