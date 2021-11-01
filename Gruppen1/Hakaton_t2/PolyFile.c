#include <stdio.h>

typedef struct Monom{
    int degree;
    double koef;
}Monom;


typedef struct PolyFile{
   int n; // power of Polynome
   int m; // number of monomials
   char fname[10];
   Monom *coefs;
}PolyFile;

//2
int inputPolyFile(PolyFile* pf){
    int m, n;
    char fname[10];
    printf("\npower of Polynome:");
    scanf("%d", &n);
    pf->n=n;
    printf("\nnumber of monomials:");
    scanf("%d", &m);
    pf->m=m;
    printf("\nfname:");
    scanf("%s", &fname);
    //pf->fname=fname;
    int st;
    float koef;
    for (int i; i<=m; i++){
        printf("\nkoef=");
        scanf("%f", &koef);
        printf("\nst=");
        scanf("%d", &st);
        pf->coefs[i].koef=koef;
        pf->coefs[i].degree=st;
    }
    return n;
}
void showPolyFile(const PolyFile* pf){
    for (int i; i<=pf->m; i++){
        printf("(%lf, %d) ",pf->coefs[i].koef,pf->coefs[i].degree);
    }
}

void derivPolyFile(const PolyFile* pf, const char* output){
    for (int i; i<=pf->m; i++){
        pf->coefs[i].koef=(pf->coefs[i].degree)*pf->coefs[i].koef;
        pf->coefs[i].degree--;
    }
}

void integralPolyFile(const PolyFile* pf, const char* output){
    for (int i; i<=pf->m; i++){
        pf->coefs[i].koef=pf->coefs[i].koef/(pf->coefs[i].degree+1);
        pf->coefs[i].degree++;
    }
}


