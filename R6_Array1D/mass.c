#include <stdio.h>
#include <stdlib.h>

void inputmas(int* mas, int n) {
    int a;
    for (int i = 0; i<n; i++) {
        do{
            printf("mas[%d] = ", i);
            scanf("%d", &a);
            
        } while(a<1);
        mas[i]=a;
    }
}

void printmas(int* mas, int n){
    for (int i = 0; i<n; i++) {
        if (mas[i] != -3){
            printf("\n%d", mas[i]);
        }
        else{
            break;
        }
    }
}

void task_func(int* mas0, int* mas, int l1, int L){
    int i0=0;
    for (int i=0; i<l1; i++){
        if (mas0[i]%2 == 1){
            mas[i0]=mas0[i];
            mas[i0+1]=-1;
            i0+=2;
        }
        else{
            mas[i0]=mas0[i];
            i0+=1;
        }
    }
    for (int i=l1; i<L; i++){
        if (mas0[i]%2 == 0){
            mas[i0]=-2;
            mas[i0+1]=mas0[i];
            i0+=2;
        }
        else{
            mas[i0]=mas0[i];
            i0+=1;
        }
    }
    mas[i0]=-3;
}

int main(){
    int L;
    printf("Press count of numbers: ");
    scanf("%d", &L);
    int l1 = L/2;
    int* mas0 = (int*) malloc(sizeof(int)*L);
    int* mas = (int*) malloc(sizeof(int)*L*2);
    inputmas(mas0, L);
    printf("\nmas0");
    printmas(mas0, L);
    task_func(mas0, mas, l1, L);
    printf("\nmas");
    printmas(mas, 2*L);
}