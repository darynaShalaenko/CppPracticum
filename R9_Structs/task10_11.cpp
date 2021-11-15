#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 80


typedef struct {
    char surname[N], city[N], street[N];
    int house, apartment;
} Inhabitant;


void print(Inhabitant a) {
    printf("Surname: %s, City: %s, Address: %s, %i, %i\n", a.surname, a.city, a.street, a.house, a.apartment);
}

void print_array(Inhabitant arr[], int n) {
    for (int i = 0; i < n; i++)
        print(arr[i]);
}


int same_address(Inhabitant arr[], int n, char *one, char *two) {
    int m1 = 0, m2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(arr[i].city, arr[j].city)) {
                if ((!strcmp(arr[i].street, arr[j].street)) && (arr[i].house == arr[j].house) &&
                        (arr[i].apartment == arr[j].apartment)) {
                    m1 = i;
                    m2 = j;
                    strcpy(one, arr[m1].surname);
                    strcpy(two, arr[m2].surname);
                    return 1;
                }
            }
        }
    }
    return 0;
}


int main() {
    int n = 3;
    Inhabitant p[N] = {
            {"Ivanov",  "Kyiv",  "Chystyakivska", 4,  87},
            {"Petrov",  "Odesa", "Syretska",      10, 101},
            {"Sidorov", "Lviv",  "Chystyakivska", 4,  87},
    };
    print_array(p, n);

    char one[N];
    char two[N];
    if(same_address(p, n, one, two))
        printf("\nSame address: %s and %s\n", one, two);
    else
        printf("No inhabitants with the same address ");
    return 0;
}
