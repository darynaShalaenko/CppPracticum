
#include "stdlib.h"
#include "Predicat.h"

bool isEqual(float a, float b);

bool inArr(float* arr, unsigned n, float x);



int formSetFile(const char* finput, const char* foutput);

int inputSetFile(const char* fname);

int outputSetFile(const char* fname);

int appendSetFile(const char* fname, float x);

int popSetFile(const char* fname, int x);

bool isSetFileContaines(const char* fname, float x);

bool isSetFileEmpty(const char* fname);

float maxSetFile(const char* fname);

float minSetFile(const char* fname);

int unionSetFile(const char* finput1, const char* finput2,const char* foutput);

int subtractSetFile(const char* finput1, const char* finput2,const char* foutput);

int intersectSetFile(const char* finput1, const char* finput2,const char* foutput);

double weightSetFile(const char* fname1, const double* weights);

double diameterSetFile(const char* fname);

// output is the number of elements in foutput
int subsetSetFile(const char* finput, predicatDouble Q, const char* foutput);

bool isSubsetSetFile(const char* A, const char* B);

bool isEqualSetFile(const char* A, const char* B);

//17


