
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <fstream>

class Text_File{
    private:
    std::string fname;
    unsigned n_ch;
    unsigned n_r;

    public:
    Text_File(){}
    Text_File(std::string f, unsigned ch,unsigned r):fname(f),n_ch(ch),n_r(r){}

    void input(unsigned n){
        try {
            std::ofstream file;
            file.open(fname);
            for(int i=0;i<n;i++){
                double a;
                std::cout<<"введіть дійсне число";
                std::cin>>a;
                file<<"\n"<<a;
                n_ch++;
                n_r++;
            }
            file.close();
        }
        catch (...) {
        std::cerr<<"problem with writing to file";
        }
    }

    void inputMas2(double** mas, unsigned n, unsigned m){
        try {
            std::ofstream file;
            file.open(fname);
            for(int i=0;i<n;i++){
                file<<"\n";
                for(int j=0;j<n;j++){
                    file<<"  "<<mas[i][j];
                    n_ch++;
                }
                n_r++;
            }
            file.close();
        }
        catch (...) {
        std::cerr<<"problem with writing to file";
        }
    }

    void show(){
        double a;
        std::ifstream file;
        file.open(fname);
        while (!file.eof()){
            file>>a;
            std::cout<<a<<" ";
        }
        file.close();
    }

    double getCh(unsigned n){
        if(n>n_ch){
            std::cerr<<"incorrectly set number";
            return 0;
        }
        double a;
        unsigned i=0;
        std::ifstream file;
        file.open(fname);
        while (!file.eof()){
            file>>a;
            if(i==n){
                file.close();
                return a;
            }
            i++;
        }
        file.close();
        return 0;
    }

    void inputMas(double* mas, unsigned n){
        try {
            std::ofstream file;
            file.open(fname,std::ios::app);
            file<<"\n";
            for(int i=0;i<n;i++){
                file<<"  "<<mas[i];
                n_ch++;
            }
            n_r++;
            file.close();
        }
        catch (...) {
        std::cerr<<"problem with writing to file";
        }
    }
};




int main() {
    Text_File f("qwerty.txt",0,0);
    double** mas;
    mas=new double*[3];
    for(int i=0;i<3;i++){
        mas[i]=new double[3];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            mas[i][j]=i+j+0.5;
        }
    }
    f.inputMas2(mas, 3, 3);
    f.show();
    return 0;
}
