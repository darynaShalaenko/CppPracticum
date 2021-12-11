/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <exception>
using namespace std;


double sin_teylor(long double x, long double eps) {
  long double result = 0;
  int sign = 1;
  long double xx = x*x, powx = x, facti = 1.0;
  int i=1;
  long double temp=1;
  while (abs(temp)>eps) {
    facti /= i;
    
    temp=sign * powx * facti;
    result += temp;
    
    
    facti /= ( i + 1 );
    sign = -sign;
    powx *= xx;
    i+=2;
  }
  return result;
}

int main()
{
    
    while (true) 
    {
        cout<<"Точність: ";
        long double x,eps;
        cin>>eps;  
        
 
        if (cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(32767,'\n'); 
            cout << "That input is invalid.  Please try again.\n";
        }
        else
        {
            cout<<"Х: ";
            cin>>x;
            cout<<sin_teylor(35, eps);
            break;
        }
    }
    
    
    
    return 0;
}
