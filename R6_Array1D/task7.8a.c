#inlude <float.h>

int SquaresArray(const double *mas, int n) { 
 int cnt = 0; 
 for (int i = 0; i < n; i++) { 
 //if ( fabs(sqrt(mas[i]) - int(sqrt(mas[i])<0.0001))) 
  int tmp = int(sqrt(mas[i]);  // tmp =(pow(mas[i], 1.0/3.0)
 if(tmp*tmp==mas[i])
 //if ( floor(sqrt(mas[i]) == mas[i] ))))   
 { cnt++; }
 } 
return cnt; 
}
