#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define N 100

using namespace std;

void printmas(double *mas, int n){
    for (int i=0; i<n; i++){
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }
}

int main(){
    int n=0, i=0;
    char dob[N][10];
    fstream f;
    f.open("test.txt");
    if (f){
        while(!f.eof()){
            f>>dob[n];
            i=0;
            while(1){
                if(dob[n][i]==','){
                    dob[n][i]='.';
                    break;
                }
                i+=1;
            }
            n++;
        }
        f.close();
    }
    else{
        cout << "FileError!!!" << endl;
    }
    int error = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (dob[i][j] != '0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9' || '.' || ',' || '-'){
                error = 1;
                cout << "Incorrect input!!!" << endl;
                break;
            }
        }
        if(error == 1){
            break;
        }
        
    }
    if(error == 0){
        double* V = (double*) malloc(sizeof(double)*n);
        for (int i=0; i<n; i++){
            V[i] = stod(dob[i]);
        }
        printmas(V, n);
    }
}