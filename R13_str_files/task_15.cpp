#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;


int geometric_mean(){
    int count=0;
    double geo, mul = 1;
    long long a;
    ifstream fin;
    fin.open("file1.txt");
    while (true) {
        fin >> a;
        if (!fin.good())
            break;
        mul = mul * a;
        count +=1;
    }
    if (mul < 0 and (count % 2 == 0)){
        cout << "Incorrect result. Rewrite number in file1.txt";
    }
    else {
        geo = pow(mul, 1.0 / count);
    }
    fin.close();
    return geo;
}

int main() {
    ifstream fin;
    fin.open("file1.txt");
    if (!fin.is_open() ){
        cout << "file didn't open" << endl;
    }
    else {
        if (geometric_mean() == 0){
            cout << endl << "Restart the program " << endl;
        }
        else {
            cout << "Geometric mean  = " << geometric_mean() << endl;
        }
    }
    fin.close();
    return 0;
}
