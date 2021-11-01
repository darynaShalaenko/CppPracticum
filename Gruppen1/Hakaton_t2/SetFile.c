#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>


int formSetFile(const char* finput, const char* foutput){
    FILE* file = fopen(finput, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    float *array = (float*)malloc(sizeof(float)*(n+1));
    array[0] = n;
    int i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        array[i++] = item;
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array[i] = item;
        else i--;
    }
    fclose(file);
    FILE* file1 = fopen(foutput, "wb");
    int res = fwrite(&array, sizeof(float), n+1, file1);
    fclose(file1);
    return res;
}


int inputSetFile(const char* fname) {
    unsigned n;
    printf("n = ");
    scanf("%d", &n);
    float *array = (float*) malloc(sizeof(float)*(n+1));
    array[0] = n;
    float item;
    for (int i=1; i<=n; i++) {
        printf("a[%d] = ", i-1);
        scanf("%f", item);
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array[i] = item;
        else i--;
    }
    FILE* file1 = fopen(fname, "wb");
    int res = fwrite(&array, n+1, sizeof(float), file1);

    fclose(file1);
    free(array);
    return res;
}


int outputSetFile(const char* fname){
    FILE* file = fopen(fname, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    printf("\nNumber of numbers: %f\n", n);
    int i;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        printf("%f ", item);
    }
    fclose(file);
}

/*
int appendSetFile(const char* fname, int x){
    FILE* file = fopen(fname, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    float *array = (float*)malloc(sizeof(float)*(n+2));
    array[0] = n;
    array[n+1] = (float*) x;// ???
    int i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        array[i++] = item;
    }
    fclose(file);
    FILE* file1 = fopen(fname, "wb");
    res = fwrite(&array, n+2, sizeof(float), file1);

    fclose(file1);
    free(array);
    return res;
}
*/
/*
int popSetFile(const char* fname, int x){
    FILE* file = fopen(fname, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    float *array = (float*)malloc(sizeof(float)*(n+1));
    array[0] = n;
    int i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        array[i++] = item;
    }
    fclose(file);
    float *array1 = (float*)malloc(sizeof(float)*(n));
    int k, flag = 0;;
    for (i=0; i<n+2; i++) {
        if (fabs(array[i] - x) > DBL_EPSILON && flag == 0) array1[k++] = array[i];
        else {
            flag = 1;
            i--;
        }
    }
    FILE* file1 = fopen(fname, "wb");
    res = fwrite(&array, n, sizeof(float), file1);
    fclose(file1);
    free(array);
    free(array1);
    return res;
}
*/

bool isSetFileContaines(const char* fname, int x) {
    FILE* file = fopen(fname, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        if (fabs(item - x) < DBL_EPSILON) {
            fclose(file);
            return true;
    }
    fclose(file);
    return false;
}


bool isSetFileEmpty(const char* fname) {
    FILE* file = fopen(fname, "rb");
    if (feof(file)) {
        fclose(file);
        return true;
    } else {
        fclose(file);
        return false;
    }
}


float maxSetFile(const char* fname){
    FILE* file = fopen(fname, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    float *array = (float*)malloc(sizeof(float)*(n+1));
    array[0] = n;
    int i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        array[i++] = item;
    }
    fclose(file);

    float max_el=0;
    for (i=0; i<=n; i++) {
        if (array[i] > max_el) max_el = array[i];
    }
    free(array);
    return max_el;
}


float minSetFile(const char* fname){
    FILE* file = fopen(fname, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    float *array = (float*)malloc(sizeof(float)*(n+1));
    array[0] = n;
    int i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        array[i++] = item;
    }
    fclose(file);

    float min_el=array[i];
    for (i=0; i<=n; i++) {
        if (array[i] < min_el) min_el = array[i];
    }
    free(array);
    return min_el;
}
}
//6

/*
int unionSetFile(const char* finput1, const char* finput2,const char* foutput){
    FILE* file = fopen(finput1, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    float *array = (float*)malloc(sizeof(float)*(n+1));
    array[0] = n;
    int i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        array[i++] = item;
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array[i] = item;
        else i--;
    }
    fclose(file);
    FILE* file2 = fopen(finput2, "rb");
    float n2;
    fread(&n, sizeof(float), 1, file);
    float *array2 = (float*)malloc(sizeof(float)*(n2));
    i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file2);
        if (res_read < 1) break;
        array2[i++] = item;
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array2[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array2[i] = item;
        else i--;
    }
    fclose(file2);
    int max_i;
    float *array3 = (float*)malloc(sizeof(float)*(n2+n+1));
    for (i=0; i<n+n2+1; i++) {
        int flag1 = 0;
        array3[i] = array[i];
        for (int j=0; j<n+n2+1; j++) {
            if (fabs(array3[j]- array2[i]) < DBL_EPSILON) {
                flag1 = 1;
                break
            }
        }
        if (flag1 != 1) {
            array3[i+1] = array[i];
            i++;
        }
        max_i = i;
    }
    free(array);
    free(array2);
    float *array_res = (float*)malloc(sizeof(float)*(max_i+1));
    array_res[0] = max_i
    for (i = 1; i<=max_i; i++) {
        arra_res[i] = array3[i-1];
    }
    FILE* file1 = fopen(foutput, "wb");
    res = fwrite(&array_res, sizeof(float), max_i+1, file1);
    fclose(file1);
    free(array3);
    free(array_res);
    return res;
}*/

/*
int intersectSetFileSetFile(const char* finput1, const char* finput2,const char* foutput){
    FILE* file = fopen(finput1, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    float *array = (float*)malloc(sizeof(float)*(n+1));
    array[0] = n;
    int i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        array[i++] = item;
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array[i] = item;
        else i--;
    }
    fclose(file);

    FILE* file2 = fopen(finput2, "rb");
    float n2;
    fread(&n, sizeof(float), 1, file);
    float *array2 = (float*)malloc(sizeof(float)*(n2));
    i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file2);
        if (res_read < 1) break;
        array2[i++] = item;
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array2[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array2[i] = item;
        else i--;
    }
    fclose(file2);

    float* array3 = (float*) malloc(sizeof(float)*(max(n, n2)));
    int k = 0, max_k;
    for (i = 1; i<max(n,n2); i++) {
        if (fabs(array[i] - array2[i]) < DBL_EPSILON) array3[k++] = array[i];
        max_k = k;
    }
    float* array_res = (float*) malloc(sizeof(float)*(max_k+1));
    array_res[0] = max_k;
    for (i=1; i<=max_k; i++) {
        array_res[i] = array3[i-1];
    }
    free(array);
    free(array3);
    free(array2);

    FILE* file3 = fopen(foutput, "wb");
    res = fwrite(&array_res, sizeof(float), max_k, file3);
    fclose(file3);
    free(array_res);
    return res;
}


int subtractSetFileSetFile(const char* finput1, const char* finput2,const char* foutput){
    FILE* file = fopen(finput1, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    float *array = (float*)malloc(sizeof(float)*(n+1));
    array[0] = n;
    int i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        array[i++] = item;
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array[i] = item;
        else i--;
    }
    fclose(file);

    FILE* file2 = fopen(finput2, "rb");
    float n2;
    fread(&n, sizeof(float), 1, file);
    float *array2 = (float*)malloc(sizeof(float)*(n2));
    i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file2);
        if (res_read < 1) break;
        array2[i++] = item;
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array2[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array2[i] = item;
        else i--;
    }
    fclose(file2);

    float* array3 = (float*) malloc(sizeof(float)*(n+n2));
    int k = 0, max_k;
    for (i = 1; i<(n+n2); i++) {
        if (fabs(array[i] - array2[i]) > DBL_EPSILON) {
            for (int j=0; j<(n+n2); j++) {}
            array3[k++] = array[i];

        }
        max_k = k;
    }
    float* array_res = (float*) malloc(sizeof(float)*(max_k+1));
    array_res[0] = max_k;
    for (i=1; i<=max_k; i++) {
        array_res[i] = array3[i-1];
    }
    free(array);
    free(array3);
    free(array2);

    FILE* file3 = fopen(foutput, "wb");
    res = fwrite(&array_res, sizeof(float), max_k, file3);
    fclose(file3);
    free(array_res);
    return res;
}*/

/*
double weightSetFile(const char* fname1, const double* weights){
    double weight_res = 0;
    for (int i=1; i<weights[0]; i++) {
        weight_res += fabs(weights[i]);
    }

    FILE* file = fopen(fname1, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    while (!feof(file)) {
        res_read = fread(&item, sizeof(float), 1, file);
        if (read_read < 1) break;
        weight_res += fabs(item);
    }
    fclose(file);
    return weight_res;
}


double diameterSetFile(const char* fname){
    return maxSetFile(fname)-minSetFile(fname);
}


bool isSubsetSetFile(const char* A, const char* B){
    FILE* file = fopen(A, "rb");
    float n, item;
    fread(&n, sizeof(float), 1, file);
    float *array = (float*)malloc(sizeof(float)*(n));
    int i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file);
        if (res_read < 1) break;
        array[i++] = item;
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array[i] = item;
        else i--;
    }
    fclose(file);

    FILE* file2 = fopen(B, "rb");
    float n2;
    fread(&n, sizeof(float), 1, file);
    float *array2 = (float*)malloc(sizeof(float)*(n2));
    i = 1;
    while (!feof(file)) {
        int res_read = fread(&item, sizeof(float), 1, file2);
        if (res_read < 1) break;
        array2[i++] = item;
        int flag = 0;
        for (int k=1; k<=n; k++){
            if (fabs(array2[k] - item) < DBL_EPSILON) flag = 1;
        }
        if (flag != 1) array2[i] = item;
        else i--;
    }
    fclose(file2);

    for (i=0; i<n; i++) {
        int flag = 0;
        for (int j=0; j<n2; j++) {
            if (array2[j] == array[i]) flag = 1
        }
        if (flag == 0) return false;
    }
    return true;
}

bool isEqualSetFile(const char* A, const char* B) {
    return isSubsetSetFile(A, B) && isSubsetSetFile(B, A);
}
*/


