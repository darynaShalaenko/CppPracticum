
//

#include <iostream>
#include <stdlib.h>

typedef struct Vector{
    unsigned n;
    double* a;
}Vector;

int inputVector(Vector* p){
    printf("n=");
    scanf("%u",&p->n);
    p->a=(double*) malloc((p->n+1)*sizeof(*(p->a)));
    if(!p->a){
        printf("cannot allocate memory for vector");
        return 0;
    }
    for (unsigned i=0; i<p->n; ++i){
        printf("a[%u]=",i);
        scanf("%lf", &(p->a[i]));
    }
    return 1;
}

void printVector(Vector* p){
    printf("vector(");
    for (unsigned i=0; i<p->n-1; ++i){
        printf("%g, ", p->a[i]);
    }
    printf("%g)\n",p->a[p->n-1]);
}

void deleteVector(Vector* p){
    free(p->a);
}

int main() {
    Vector p;
    inputVector(&p);
    printVector(&p);
    deleteVector(&p);
    return 0;
}
