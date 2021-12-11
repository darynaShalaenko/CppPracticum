#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{   
    int n = 1, m = 1, i, j, k;
    float arth, sum_x = 0;
    printf("<= 0 for n or n to break\n");
    while(n != 0 && m != 0){
        printf("n = ");
        scanf("%d", &n);
        printf("m = ");
        scanf("%d", &m);
        if(n > 0 && m > 0){
            float** array = new float*[n];
            for(i = 0; i < n; i++){
                array[i] = new float[m];
            }
            //float *array = new float[n][m];
            for(i = 0; i < n; i++){
                for(j = 0; j < m; j++){
                    printf("a[%d*][%d*] = ", i, j);
                    scanf("%f", &array[i][j]);
                    }
                }
        printf("k = ");
        scanf("%d", &k);
        if(k < 0){
            printf("Error: k < 0\n");
        }
        else if(k > 0){
            float** array2 = new float*[n+k];
            for(i = 0; i < n + k; i++){
                array2[i] = new float[m];
            }
            for(i = 0; i < n; i++){
                for(j = 0; j < k; j++){
                    array2[i][j] = array[i][j];
                }
            }            
            for(i = n; i < n + k; i++){
                for(j = 0; j < k; j++){
                    printf("a[%d*][%d*] = ", i, j);
                    scanf("%f", &array2[i][j]);
                }
            }
            for(i = 0; i < n + k; i++){
                printf("\n");
                for(j = 0; j < k; j++){
                    printf("a[%d*][%d*] = %f ", i, j, array2[i][j]);
                }
            }
            for(int i = 0; i < n + k; i++){
                delete[] array2[i];
            }
            delete[] array2;
        }
        for(int i = 0; i < n; i++){
            delete[] array[i];
        }
        delete[] array;
        }
    }

