
//
//  main.cpp
//  HW13_10.14av
//
//  Created by Air on 06.11.2021.
//

#include <iostream>
#incl
ude <string.h>
#define N 10

typedef struct Dani{
    unsigned n;
    char stat[10];
    double zrist;
}Dani;

double task_a(Dani* P ,int n){
    double s=0,k=0;
    for (int i=0; i<n; i++) {
        if(strcmp(P[i].stat,"woman")==0){
            s=s+P[i].zrist;
            k++;
        }
    }
    return s/k;
}

void task_v(char** L,Dani* P ,int n){
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if(P[i].zrist==P[j].zrist){
                printf("\n%s and %s have the same height\n",L[P[i].n-1],L[P[j].n-1]);
                return;
            }
        }
    }
    printf("\nno people are the same height\n");
}

int main() {
    Dani P[]={{1,"woman",178},{2,"man",198},{3,"woman",166},{4,"man",187},{5,"man",178}};
    char* L[]={"Мasha", "Danya","Katya","Dima","Roma"};
    printf("average height of women: %lf",task_a(P, 5));
    task_v(L, P, 5);
    return 0;
}
