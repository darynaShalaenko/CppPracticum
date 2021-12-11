/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <fstream>

using namespace std;


void line(int x1, int y1, int x2, int y2, double& k, double& b, double& yy){
    if (abs(x1-x2)<1e-3){
        k=1;
        b=x1;
        yy=0;
    }
    else{
        k = (y2 - y1)/(x2 - x1);
        b = (x2*y1 - x1*y2)/(x2 - x1);
        yy=1;
    }
}

bool check(int x1, int y1, int x2, int y2, int x3, int y3){
    if ((abs(x1-x2)<1e-3) and (abs(x1-x3)<1e-3)) return true;
    else if ((abs(x1-x2)<1e-3) or (abs(x1-x3)<1e-3)) return false;
    else 
    {
        double k = (y1-y2)/(x1-x2);
        double b = y1 - k * x1;
        if (abs(k * x3 + b - y3)<1e-3) return true;
        else return false;
    }
}

int main()
{
    ofstream outFile("TestOut.txt");

    int n,x,y, index;
    
    cout<<"Кількість точок: ";
    cin>>n;
    const unsigned int row = n;
    const unsigned int column = 2;
    int arr[row][column];
    for (int i = 0; i < row; i++) {
        cout<<"Введіть х та у "<<i+1<<" точки ";
        cin>>arr[i][0]>>arr[i][1];
    }
    
    cout<<"Введіть х та у шуканої точки ";
    cin>>x>>y;
    bool flag=false;
    for (int i=0; i<row; i++){
        if (arr[i][0]== x and arr[i][1]==y){
            flag==true;
            index=i;
            break;
        }
    }
    if (flag){
    
    vector<int> linein;
    vector <int> linep;
    linein.push_back(index);
    double k,b,yy;
    int create;
    for (int i=0; i< row; i++){
        linep.clear();
        if (find(linein.begin(), linein.end(), i) == linein.end()){
            //line(x, y, arr[i][0], arr[i][1], k, b, yy);
            linep.push_back(i);
            create=i;
            for (int j=i+1; j<row; j++){
                if ((find(linein.begin(), linein.end(), j) == linein.end()) and check(x, y, arr[i][0], arr[i][1], arr[j][0], arr[j][1])){
                    linep.push_back(j);
                    linein.push_back(j);
                }
            }
        }
        
        if (linep.size()>0){
            linep.push_back(index);
            line(x, y, arr[create][0], arr[create][1], k, b, yy);
            outFile<<endl;
            outFile<<k<<"*x+"<<b<<"=y. Кількість точок, що належать: "<<linep.size()<<", а саме: "; 
            for (vector<int>::iterator it = linep.begin() ; it!=linep.end() ; ++it)
                outFile<<"("<<arr[*it][0]<<","<<arr[*it][1]<<") ";
            outFile<<endl;
        }
        
    }
    }
    else outFile<<"Такої точки немає";
    
    outFile.close();
    
    return 0;
    
}
