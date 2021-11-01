
#include "PolyFile.h"
#include <string.h>
#include <stdlib.h>

int inputPolyFile(PolyFile* pf){
  PolyFile z;
  z.n = 5; // power of Polynome
  z.m = 3; // number of monomials
  strcpy(z.fname,"a.dat");
  z.coefs = calloc(z.m,sizeof(*(z.coefs)));     
  z.coefs[0].degree = 1;
  z.coefs[0].koef = 1;
  *pf = z;
  return 0;
}


int maxIndexPolyFile(const PolyFile* pf1, predicatDouble Q){
        printf("f %d", pf1->m);
   for(int i=0; i<pf1->m;i++){
     if(Q(pf1->coefs[i].koef)){
        printf("fffffff");
     }
   }
  return 0;
}

/*
void showPolyFile(const PolyFile* pf);

PolyFile derivPolyFile(const PolyFile* pf, const char* output);

PolyFile integralPolyFile(const PolyFile* pf, const char* output);

void rankDegrees(const PolyFile* pf);

void correctMonoms(const PolyFile* pf);

PolyFile addPolyFile(const PolyFile* pf1, const PolyFile* pf2, const char* output);

PolyFile subPolyFile(const PolyFile* pf1, const PolyFile* pf2, const char* output);

PolyFile multPolyFile(const PolyFile* pf1, const PolyFile* pf2, const char* output);

PolyFile divPolyFile(const PolyFile* pf1, const PolyFile* pf2, const char* output);

PolyFile remPolyFile(const PolyFile* pf1, const PolyFile* pf2, const char* output);

PolyFile subPolyFile(const PolyFile* pf1, double d, double c, const char* output);

PolyFile subPolyFile(const PolyFile* pf1, double d, const char* output);

int zerosFoundPolyFile(const PolyFile* pf1);

int maxIndexPolyFile(const PolyFile* pf1, predicatDouble Q);

Monom minPolyFile(const PolyFile* pf1, predicatDouble Q);

double valPolyFile(const PolyFile* pf1, double x);

*/




