#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

using namespace std;



int getRandom(unsigned N){
  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number*/
  int iSecret = rand() % N;
  return iSecret;
}

template<class T, unsigned Size=1>
class BlackBox{
    T* data;
    size_t num;

    public:
    BlackBox(){ num=0; 
     data = new T[Size];
  }

    bool push(T x){
       data[num++] = x;
      return true;
    }    

    void top(){
       int z = getRandom(num);
      cout<< data[z]; 
   }

   T pop(){
    int z = getRandom(num);

    T rez=data[z];     

    for(int i=z;i<num-1;i++){
	data[i]=data[i+1];
    }
    num--;        

     return rez;
   }

  // destructor

  // operator=
  // copy-constructor
 
};


int main(){

 BlackBox<int> b1;

 BlackBox<string> b2;

  b1.push(1);
  b1.push(2);
  b1.push(3);
  b1.push(1);

  b1.top();
  cout<<b1.pop();
  cout<<b1.pop();
  b1.top();
}
