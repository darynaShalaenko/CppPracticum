#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct{
    char surname[10];
    char name[10];
    char fname[10];
    char gender[1];
    int age;
    int course;
} Student;

void input(Student* m){
    printf("Student data: ");
    scanf("%s", m->surname);
    scanf("%s", m->name);
    scanf("%s", m->fname);
    scanf("%s", m->gender);
    scanf("%d", &(m->age));
    scanf("%d", &(m->course));
}

void print(Student m){
    printf("%s %c.%c., %s, %d, %d course", m.surname, m.name[0], m.fname[0], m.gender, m.age, m.course);
}

int find_age(Student* m, int n){
    int max = 0, count, el;
    for (int i=0; i<n; i++){
        count = 0;
        for (int j=0; j<n; j++){
            if (m[i].age == m[j].age){
                count += 1;
            }
        }
        if (count > max){
            max = count;
            el = m[i].age;
        }
    }
    return el;
}

void func_b(Student* m, int n){
    int age;
    age = find_age(m, n);
    for (int i=0; i<n; i++){
        if (m[i].age == age){
            printf("\n%s %c.%c.", m[i].surname, m[i].name[0], m[i].fname[0]);
        }
    }
}

int main(){
    int n;
    printf("N=");
    scanf("%d",&n);
    Student arr[N];
    for (int i=0; i<n; i++){
        input(&arr[i]);
    }
    func_b(arr,n);
} 
