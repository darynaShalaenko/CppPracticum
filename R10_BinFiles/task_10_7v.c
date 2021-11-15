#include <stdio.h>
#include <stdlib.h>
#define S 64


void create_double_file(char filename[S],int double_num) {
    FILE* f = fopen(filename, "wb");
    if (!f) 
	exit(1);

    double arr[S];
    for(int i=0;i<double_num;i++){
        scanf("%lf", &arr[i]);
    }

    fwrite(arr, sizeof (double), double_num, f);

    fclose(f);
}

double task_solver(char filename[S]) {
    double ans,first_double,last_double;

    FILE* f = fopen(filename,"rb");
    if (!f) 
        exit(1);

    fseek(f,0,SEEK_END);
    long objects_num = ftell(f);
    int double_num = objects_num/(sizeof (double));
    fseek(f,0,SEEK_SET);

    fseek(f, 0, SEEK_SET);

    fread(&first_double,sizeof (double),1,f);
    fseek(f,(double_num-1)*sizeof (double),SEEK_SET);
    fread(&last_double,sizeof (double),1,f);

    ans = first_double-last_double;
    fclose(f);

    return ans;

}

int main(){
    char filename[S];
    printf("Input the file name: ");
    scanf("%63s", filename);

    int double_num;
    printf("Input the number of double numbers in file: ");
    scanf("%d", &double_num);

    create_double_file(filename,double_num);
    double res = task_solver(filename);

    printf("Answer = %.4lf", res);


}
