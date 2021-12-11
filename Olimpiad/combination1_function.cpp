#include <iostream>
#include <string>
using namespace std;

int Number_ways(int N ){
    
   int Array[N];
   for(int i=0; i<N; i++){
       Array[i]=i+1;
   }
   
   int Number_ways=1; // количество способов 
   for(int i=0; i<N; i++){
       if(Array[i]!=1) {
           Number_ways+=Array[N-1] - Array[i];
       }
   }
   
   return Number_ways;
    
} 


int main()
{
   int N;
   cout<<"Enter N--> "<<ends;
   cin>>N;
   
   cout<<"Number of ways --> "<<Number_ways(N)<<endl;

    
    return 0;
}
