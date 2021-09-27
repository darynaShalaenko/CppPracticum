

int isDegree(int n){

  return (n-1) & n == 0; /// 1000010 ;  0111011 - and !=0   
 
}

int isDeg3(int n){
  
  int s=1;// s = pow()
  int t =1; 
  while(t<n){
  s++;
  t*=3;
 }
 return t==n; 
}

