#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    int hh, mm, ss;
} time;

void pr(time t) {
    if (t.hh<10)
    {
        printf("0%d:", t.hh);
    }
    else
    {
        printf("%d:", t.hh);
    }
    if (t.mm < 10)
    {
        printf("0%d:", t.mm);
    }
    else
    {
        printf("%d:", t.mm);
    }
    if (t.ss < 10)
    {
        printf("0%d", t.ss);
    }
    else
    {
        printf("%d", t.ss);
    }
}

int main() {
    int h, m, s;
    printf("Enter the hours, minutes and seconds:\n");
    printf("h = ");
    scanf("%d", &h);
    printf("m = ");
    scanf("%d", &m);
    printf("s = ");
    scanf("%d", &s);
    pr({ h, m, s });
}