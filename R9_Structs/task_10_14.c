#include <stdio.h>
#include <float.h>
#include <math.h>
#define N 255

typedef struct {
    int number;
    char sex[N];
    double height;
} HeightData;


HeightData inputData() {
    HeightData data;
    printf("\nNumber: ");
    scanf("%d", &data.number);
    printf("Sex(Male/Female): ");
    scanf("%s", &data.sex);
    printf("Height: ");
    scanf("%lf", &data.height);
    return data;
}


void fillNames(char* names[], int n) {
    for (int i=0; i<n; i++) {
        printf("Names[%d]: ", i);
        scanf("%s", &names[i]);
    }
}


void printNames(char* names[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d: %s   ", i, names[i]);
    }
}


char* findNameOfHighestMan(char* names[], HeightData *data, int m) {
    double max_height = 0;
    int number;
    for (int i=0; i<m; i++) {
        if (data[i].sex == "Male" && data[i].height > max_height) {
            max_height = data[i].height;
            number = data[i].number;
        }
    }
    return names[number];
}


int checkSameHeight(char* names[], HeightData data1, HeightData data2, int m) {
    if (fabs(data1.height-data2.height) < DBL_EPSILON) {
        printf("\n%s and %s have the same height", names[data1.number], names[data2.number]);

    }
    return 0;
}


int main() {
    int n = 6;
//    printf("n = ");
//    scanf("%d", &n);
    char* names[] = {"Bogdan", "Tatiana", "Max", "Alison", "Kate", "Danilo"};
//    fillNames(names, n);
    printNames(names, n);

    int m;
    do {
        printf("\nm(<n) = ");
        scanf("%d", &m);
    } while (m>n);
    HeightData* data = (HeightData*)malloc(sizeof(HeightData)*m);
    for (int i=0; i<m; i++) {
        data[i] = inputData();
    }

    printf("Highest man - %s", findNameOfHighestMan(names, data, m));
    checkSameHeight(names, data[0], data[1], m);
    free(data);
}
