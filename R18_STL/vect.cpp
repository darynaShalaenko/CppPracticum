
#include <iostream>
#include <vector>

int input(std::vector<double>& v1, int d){
	std::cout<<"v=";
	double x;
	for(int i=0;i<d;++i){
		std::cin>>x;
		v1.push_back(x);
	}
	return 0;
}

double norm(const std::vector<double>& v1){
	double s=0;
	for(int i=0;i<v1.size();i++){
		double tmp = v1[i];
		s += tmp*tmp; 
	}
	return s;
}




int main(){
	int d;
	std::vector<double> v1;
	std::cin>>d;
	int n;
	std::cin>>n;

	std::vector<std::vector<double> > vectors(n);
	for(int i=0;i<n;++i){
		input(v1,d);
		vectors.at(i) = v1;
		v1.clear(); 
	}	

	double s=0;
	for(int i=0;i<vectors.size();++i){
		s += norm(vectors[i]);
	}
	std::cout<<"\ns="<<s;
}


