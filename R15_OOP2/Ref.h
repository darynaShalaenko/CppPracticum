#ifndef __REF__
#define __REF__

#include "Aquant.h"

#include <fstream>

class RefBook{

	size_t book_size;
	Aquant a[100];

	/*FIlE *fp;
	const char* fname ="ref.txt"*/	
	
	std::fstream f1("ref1.txt");

	public:
	RefBook(){
		book_size = 0;
	}

	RefBook(size_t n){
		book_size = n;
	}

	RefBook(size_t n, const Aquant *r);

	int addAquant(const Aquant& x);

	long long seekA(std::string s);

	int change(std::string s, long long new_tel);
	
	
};

#endif // class __REF__
