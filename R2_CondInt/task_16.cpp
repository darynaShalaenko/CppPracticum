#include <iostream>
#include <cmath>
using namespace std;

void solving_system(float a1,float b1,float c1,float a2,float b2,float c2) {
  float EPSILON=1.19209e-07;
  if (abs((a1 * b2) - (b1 * a2)) < EPSILON){
      if ((abs((a1 * c2) - (c1 * a2)) < EPSILON) && (abs((b1 * c2) - (c1 * b2)) < EPSILON))
         cout << "Many solutions exist" << endl;
      else 
         cout << "The system has no solution" << endl;
  }
  else{
      float x,y;
      x = ((c1*b2) - (b1*c2))/((a1*b2)-(b1*a2));
      y = ((a1*c2) - (c1*a2)) / ((a1*b2) - (b1*a2));
      cout << "The system has 1 solution" << endl;
      cout << "x=" << x << " y=" << y << endl;
  }

}

int main()
{
    float a1,b1,c1,a2,b2,c2;
    cout << "a1=" ;
    cin >> a1;
    cout << "b1=" ;
    cin >> b1;
    cout << "c1=" ;
    cin >> c1;
    cout << "a2=" ;
    cin >> a2;
    cout << "b2=" ;
    cin >> b2;
    cout << "c2=" ;
    cin >> c2;
    solving_system(a1,b1,c1,a2,b2,c2);
    return 0;

