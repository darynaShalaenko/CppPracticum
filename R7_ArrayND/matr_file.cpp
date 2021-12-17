#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    int poz = 0;
    int x;
    setlocale(LC_CTYPE, "rus");
    ifstream fin;
    fin.open("test.txt");
    if(!fin.is_open())
    {
         cout << " ÏÎÌÈËÊÀ Ç×ÈÒÓÂÀÍÍß ÔÀÉËÓ " << endl;
    }
    else
    {
        cout << " ÉÄÅ Ç×ÈÒÓÂÀÍÍß ÔÀÉËÓ " << endl;
        if(poz == 0)
        {
            fin >> x;
            cout << x << endl;
        }

        int matrix[x][x];

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < x; j++)
            {
                fin >> matrix[i][j];
                poz++;
                cout << matrix[i][j] << " " ;
            }
            cout << endl;
        }
        fin.close();
    }

}
