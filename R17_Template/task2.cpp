
#include <iostream>

#include <stack>


int vvod(std::stack<std::string> & v){
	int k=0;
	std::string x;
	do{
		std::cin>>x;	
		if (x==".") break;
		// add memory
		v.push(x);
	}while(true);
}


int vyvod(std::stack<std::string> & v){


	std::string x;
	while(!v.empty()){
	
		// add memory
		x = v.top();
		std::cout<<" "<<x;
		v.pop();
	}
	return 0;
}

const size_t M = 1000;

namespace OurStack{
	template<class T>
	class stack{
		T data[M];
		size_t m; // number of elements
		public:
		stack(){
			m = 0;
		}

		int push(const T& x);
		void pop();
		T top();		
		bool empty();	
	};
	
	template<class T>
	int stack<T>::push(const T& x){
		data[m++] = x;
		return m<M;
	}

	template <typename U>
	int vvod(OurStack::stack<U>& v){
	int k=0;
	U x;
	do{
		std::cin>>x;	
		if (x==".") break;
		// add memory
		v.push(x);
		k++;
	
	}while(true);	

	return k;
	}

	template <typename U>
	int vyvod(OurStack::stack<U> & v){

	U x;
	while(!v.empty()){
	
		// add memory
		x = v.top();
		std::cout<<" "<<x;
		v.pop();
	}
	return 0;
}


}

template<class T>
void OurStack::stack<T>::pop(){
	if(empty()) return; // throw Exception
	m--;
}
	
template<class T>
T OurStack::stack<T>::top(){
	if(empty()) return T(0); // throw Exception
	return data[m-1];
}

template<class T>
bool OurStack::stack<T>::empty(){
	return m==0;
}




int main(){
	const int N = 10;
	/*OurStack::stack<int> arr;	
	OurStack::vvod(arr);
	OurStack::vyvod(arr);

	std::stack<int> st1;
	vvod(st1);
	vyvod(st1);*/

	OurStack::stack<std::string> arr;	
	OurStack::vvod<std::string>(arr);
	OurStack::vyvod<std::string>(arr);

	std::stack<std::string> st1;
	vvod(st1);
	vyvod(st1);
}
