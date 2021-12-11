#pragma once
#include <cstddef>


typedef double PTYPE;

/*
  P(x) = a0*x^n + a1*x^n-1 + ... + a_n
   
**/

class Poly{

	size_t n;
	PTYPE * a; // aray of n+1 values
	
	public:
	Poly(){ 
	 n = 0;
	 a = NULL; // nullptr C++11
	}
	Poly(size_t n_);
	Poly(size_t n_, PTYPE * arr);

	Poly(const Poly& p){
		n = p.n;
		a = new PTYPE[n+1];
		for(int i=0;i<n+1;++i){
			a[i] = p.a[i];
		}
	}

	~Poly(){
	   delete[] a;
	}

	Poly operator=(const Poly & p){
		n = p.n;
		if(a) delete[] a;		
		a = new PTYPE[n+1];
		for(int i=0;i<n+1;++i){
			a[i] = p.a[i];
		}
		return *this;		
	}

	void setPoly(size_t n_, PTYPE * arr); // setter
	void setCoef(size_t k, PTYPE a); // set k-th coefficient p[k] = a; 

	void show();
	PTYPE value(PTYPE x);// operator()

	friend int inputFromFile(const char* fname, Poly& p);

	friend int outputToFile(const char* fname, const Poly& p);
};


