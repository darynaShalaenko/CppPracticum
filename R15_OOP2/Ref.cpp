
#include "Ref.h"

RefBook::RefBook(size_t n, const Aquant *r){
		book_size = n;
		for(size_t i=0;i<n;++i){
			a[i] = r[i];
			f1<<a[i];			
		}
}

int RefBook::addAquant(const Aquant& x){
		a[book_size++] = x;
		f1<<x;	
}

long long RefBook::seekA(std::string s){

	///f1.open() ...	
	for(int i=0;i<book_size;++i){
		f1>>x;	
		if(a[i].getName() == s){
			return a[i].getPhone();
		}
	}
    //f1.close();
	return 0L;
}


int RefBook::change(std::string s, long long new_tel){
	for(int i=0;i<book_size;++i){
		if(a[i].getName() == s){
			a[i].setPhone(new_tel);
			return 1;
		}
	}
	return 0;
}

int main(){

	RefBook rb;
	
	Aquant a[3];
	for(int i=0;i<3;++i){
		std::cin>>a[i];
		rb.addAquant(a[i]);
	}
	std::string name;
	std::cin>>name;
	std::cout<<rb.seekA(name);
	
}
