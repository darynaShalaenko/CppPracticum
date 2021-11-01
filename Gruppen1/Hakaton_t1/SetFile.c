#include "SetFile.h"
#include <stdio.h>
#include <math.h>

bool isEqual(float a, float b)
{
    float eps = 0.00001;
    return abs(a-b) < eps;
}

bool inArr(float* arr, unsigned n, float x)
{
    for (int i=0; i<n; i++)
    {
        if (isEqual(arr[i], x)) return 1;
    }
    return 0;
}

int formSetFile(const char* finput, const char* foutput)
{
    FILE* fin = fopen(finput, "rb");
    FILE* fout = fopen(foutput, "wb");

    if (fin == NULL || fout == NULL) return -1;

    unsigned n;
    fread(&n, sizeof(n), 1, fin);
    float tmp, set[n];
    unsigned k = 0;
    for (int i=0; i<n; i++)
    {
        if (!fread(&tmp, sizeof(tmp), 1, fin))
        {
            fclose(fin);
            fclose(fout);
            return -2;
        }
        if (!inArr(set, k, tmp)) set[k++] = tmp;

    }
    if (!fwrite(&k, sizeof(k), 1, fout))
    {
        fclose(fin);
        fclose(fout);
        return -3;
    }
    if (fwrite(set, sizeof(*set), k, fout) != k)
    {
        fclose(fin);
        fclose(fout);
        return -3;
    }
    fclose(fin); fclose(fout);
    return 0;
}

int inputSetFile(const char* fname){
    unsigned  N, max_n=2*pow(10,9);
    float n0;
    FILE *fp;
    fp=fopen(fname,"wb");
    do {
        printf("N=");
        scanf("%d",&N);
    } while (N<1 || N>100000);
    fwrite(&N, sizeof(N), 1, fp);
    for (int i=1; i<=N; i++){
        do{
            printf("%d element: ",i);
            scanf("%f",&n0);
        }while (abs(n0)>max_n);
        fwrite(&n0, sizeof(n0), 1, fp);
    }
    fclose(fp);
}

int outputSetFile(const char* fname){

    FILE* f = fopen(fname, "rb");
    unsigned n;
    fread(&n, sizeof(n), 1, f);

    float tmp;
    printf("File %s\n", fname);
    for (int i=0; i<n; i++)
    {
        fread(&tmp, sizeof(tmp), 1, f);
        printf("%f\n", tmp);
    }

    fclose(f);
    return 0;
}

int appendSetFile(const char* fname, float x)
{
    if (isSetFileContaines(fname, x)) return 0;

    FILE* f = fopen(fname, "rb");

    unsigned n;
    fread(&n, sizeof(n), 1, f);
    float arr[n];
    fread(arr, sizeof(*arr), n, f);

    fclose(f);
    f = fopen(fname, "wb");
    n++;
    fwrite(&n, sizeof(n), 1, f);
    fwrite(arr, sizeof(*arr), n-1, f);
    fwrite(&x, sizeof(x), 1, f);

    fclose(f);
}

bool isSetFileContaines(const char* fname, float x)
{
    FILE* fin = fopen(fname, "rb");

    unsigned n;
    fread(&n, sizeof(n), 1, fin);
    float tmp;
    for (int i=0; i<n; i++)
    {
        if (!fread(&tmp, sizeof(tmp), 1, fin)) return false;
        if (isEqual(tmp, x))
        {
            fclose(fin);
            return 1;
        }
    }
    fclose(fin);
    return false;
};

//
//double diameterSetFile(const char* fname)
//{
//    return maxSetFile(fname) - minSetFile(fname);
//}

int subsetSetFile(const char* finput, predicatDouble Q, const char* foutput)
{
    FILE* fin = fopen(finput, "rb");

    unsigned n;
    if (!fread(&n, sizeof(n), 1, fin))
    {
        fclose(fin);
        return -1;
    }

    float tmp;
    for (int i=0; i<n; i++)
    {
        if (!fread(&tmp, sizeof(tmp), 1, fin))
        {
            fclose(fin);
            return -1;
        }
        if (Q(tmp)) appendSetFile(foutput, tmp);
    }
    fclose(fin);
}

bool isSubsetSetFile(const char* A, const char* B)
{
    FILE* fin = fopen(A, "rb");
    unsigned n;
    fread(&n, sizeof(n), 1, fin);

    float tmp;
    for (int i=0; i<n; i++)
    {
        fread(&tmp, sizeof(tmp), 1, fin);
        if (!isSetFileContaines(B, tmp)) {fclose(fin); return 0;}
    }
    fclose(fin);
    return 1;
}

bool isEqualSetFile(const char* A, const char* B)
{
    return isSubsetSetFile(A, B) && isSubsetSetFile(B, A);
}


bool func(double x)
{
    return x>0;
}


//8
/*
int main()
{
    const char fname1[] = "A";
    const char fname2[] = "B";
    const char fname3[] = "C";
    inputSetFile(fname1);
    inputSetFile(fname2);

    appendSetFile(fname1, 5);

    outputSetFile(fname1);
    outputSetFile(fname2);

    printf("%d\n", isSetFileContaines(fname1, 4));

    printf("%d\n", isEqualSetFile(fname1, fname2));

    printf("%d\n", isSubsetSetFile(fname1, fname2));

//    subsetSetFile(fname1, &func, fname3);
//    outputSetFile(fname3);

    return 0;
}*/

