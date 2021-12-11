#include <stdio.h>
#include <iostream>
using namespace std;

float** input_mart(int n, int m){
    int i, j;
    if(n > 0 && m > 0){
        float** array = new float*[n];
        for(i = 0; i < n; i++)
            array[i] = new float[m];
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                printf("a[%d][%d] = ", i, j);
                scanf("%f", &array[i][j]);
                }
            }
        return array;    
        }
    return 0;
}
void del_matr(float** array, int n){
    for(int i = 0; i < n; i++){
        delete[] array[i];
    }
    delete[] array;
    printf("\nMatrix is deleted.");
}

float** incr_mart(float** array, float** array2, int n, int m, int n2, int m2){
    int i, j, i2, j2, i3, j3;
    float sum_res = 0;
    if(m == n2){
        float** array_new = new float*[n];
        for(i = 0; i < n; i++)
            array_new[i] = new float[m2];
        for(i = 0; i < n; i++){
            for(j = 0; j < m2; j++){
                for(j2 = 0; j2 < m; j2++){
                    sum_res += array[i][j2] * array2[j2][j];
                }
                array_new[i][j] = sum_res;
            }
        }
    return array_new;    
    }
    else{
        return 0;
    }

}

int main()
{   
    int i, j, km, n, m, nr, mr;
    printf("Number of arrays = ");
    scanf("%d", &km);
    if(km > 0){
        for(i = 0; i < km; i++){
            printf("i = %d", i);
            printf("n = ");
            scanf("%d", &n);
            printf("m = ");
            scanf("%d", &m);
            float** array1 = input_mart(n, m);
            if(i == 0){
                float** array_res = array1;
                mr = m;
                nr = n;
            }
            else{
                float** array_res = incr_mart(array_res, array1, nr, mr, n, m);
                for(i = 0; i < n; i++){
                    printf("\n");
                    for(j = 0; j < m; j++){
                        printf("a[%d][%d] = %f ", i, j, array_res[i][j]);
                    }
                }
            }
        }
    }
}
