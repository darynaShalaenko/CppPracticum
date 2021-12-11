#include <iostream>

using namespace std;

void sigma(int arr[], int n, int max, int ligma)
{
    int l = 1;
    for (int i=1; i < n; i++)
    {
        if (ligma * arr[i] > ligma * arr[i-1])
        {
            l++;
        }
        else
        {
            if (max == l)
            {
                for(int j=i-max; j < i; j++)
                {
                    cout << arr[j] << " ";
                }
                cout << endl;
            }
                
            l = 1;
            
        }
    }
    
    if (max == l)
            {
                for(int j=n-max; j < n; j++)
                {
                  cout << arr[j] << " ";
                }
                cout << endl;
            }

}

int Thelongest(int arr[], int n, int ligma)
{
    int max = 1;
    int l = 1;
    
    for (int i=1; i < n; i++)
    {
        if (ligma * arr[i] > ligma * arr[i-1])
        {
            l++;
        }
        else
        {
            if (max < l)
                max = l;
            l = 1;
        }
    }
    
    if (max < l)
       max = l;
    
    return max;
}

int main()
{
    int n, m;
    cin >> n;
    int arr [n];
    int max;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        arr[i] = m;
    }
    
    int max1  = Thelongest(arr, n, 1);
    int max2  = Thelongest(arr, n, -1);
    
    if (max1 >= max2){
        max = max1;
    }
    else{
        max = max2;
    }
    
    sigma(arr, n, max, 1);
    sigma(arr, n, max, -1);
    
    return 0;
}