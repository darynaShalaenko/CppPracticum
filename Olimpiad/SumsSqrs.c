#include <stdio.h>
int sum_sqrs(int n){
    int next_num, sum_sq = 0;
    while(n > 0){
        next_num = n % 10;
        //printf("%d", next_num);
        sum_sq += next_num * next_num;
        n /= 10;
    }
    return sum_sq;
}
int main()
{
    int n, i = 0, j, iterations = 30, k = 0, counter = 0, q, n_cur;
    int *array;
    int *arr_pr;
    printf("n (1000 by conditions) = ");
    scanf("%d", &q);
    int arr_lengs[q];
    int max_leng = 0, max_number = 1;
    for(n = 1; n <= q; n++){
        k = 0, counter = 0, i = 0, j = 0;
        printf("\n******\n");
        printf("For n = %d\n", n);
        n_cur = n;
        while(counter != 2){
            n_cur = sum_sqrs(n_cur);
            array[i] = n_cur;
            if((array[i] == array[k]) && i != k){
                counter = i;
                break;
            }
            //printf("n = %d\n", n);
            if(counter == 0 && i != 0){
                for(j = 0; j < i; j++){
                    if((array[i] == array[j]) && (i != j)){
                        counter = 1;
                        //printf("\nfind %d\n", array[j]);
                        k = i;
                        break;
                    }
                }
            }
            i++;
        }
        printf("\nstart = %d, stop = %d\n", k, counter);
        /*for(i = k; i < counter+1; i++){
            printf("n = %d\n", array[i]);
            }*/
        printf("Lenght = %d\n", counter - k);
        arr_lengs[n] = (counter - k);
    }
    for(n = 1; n <= q; n++){
        if(arr_lengs[n] > max_leng){
            max_leng = arr_lengs[n];
            max_number = n;
        }
    }
    printf("Max number = %d with %d iterations\n", max_number, max_leng);
}
