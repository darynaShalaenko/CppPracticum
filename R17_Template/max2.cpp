#include <iostream>
#include <string>

#include "Rational.h"


namespace MM{

	template<typename T>
	T max(T a, T b){
	return a>b?a:b;
	/*
	if(a>b) return a;
	return b;		
	*/
	}

}



int main(){
	int a=3,b=4;
	using namespace MM;
	int x= max(a,b);
	std::cout<<x;

	long long unsigned a1=6L, b1=7L;
	long long unsigned x1= std::max(a1,b1);
	std::cout<<x1;

	std::string s1("dddd");
	std::string s2("cccc");
	std::cout<<std::max(s1,s2);
	
	Rational r1(1,2);
	Rational r2(2,3);
	Rational r3 =max(r1,r2);
	r3.show();
}
