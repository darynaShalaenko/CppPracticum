#include <iostream>

#include <stack>

template <class T, unsigned N=100> 
class Mystack {

    T a[N];
    unsigned num;

   public:
    Mystack(){ num=0; }

    T top(){ 
         return a[num];
    }  
    
    bool push(T b){ 

         if (num+1>=N) return false;
         a[num++]=b;
	return true;
    }  


    T pop(){ 
         if (num==0) return 0; //exception         
	return a[--num];
    }  

   void print(){
   for (int i=num-1;i>=0;--i){
       std::cout<<a[i]<<",";
       //std::cout<<std::endl;
   }
 } 

};

int main(){

   Mystack<int> s1;
   Mystack<std::string> s2;
   
   s1.push(1);s1.push(2);
   s1.print();


   s2.push("aaa");s2.push("bbbb");
   s2.print();


   std::stack<int> t1;
   std::stack<std::string> t2;

   t1.push(1);t1.push(2);
   /*for(int i=0;i<t1.size();i++){
   std::cout<<t1[i];
  }*/
  std::cout<<std::endl;
  while(!t1.empty()){
    std::cout<<t1.top()<<"; ";
    t1.pop();
  }


   t2.push("aaa");t2.push("bbbb");
   /*for(auto a=t2.begin();a!=t2.end();a++){
   std::cout<<*a;
   }*/
  while(!t2.empty()){
    std::cout<<t2.top();
    t2.pop();
  }




}

