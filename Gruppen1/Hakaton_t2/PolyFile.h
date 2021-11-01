
#include "Predicat.h"

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


int inputPolyFile(PolyFile* pf);

int deletePolyFile(PolyFile* pf);

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

PolyFile subsetPolyFile(const PolyFile* pf1, double d, double c, const char* output);

PolyFile subsetPolyFile2(const PolyFile* pf1, double d, const char* output);

int zerosFoundPolyFile(const PolyFile* pf1);

int maxIndexPolyFile(const PolyFile* pf1, predicatDouble Q);

Monom minPolyFile(const PolyFile* pf1, predicatDouble Q);

double valPolyFile(const PolyFile* pf1, double x);

//18




