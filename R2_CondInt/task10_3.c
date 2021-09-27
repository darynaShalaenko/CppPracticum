#include <stdio.h>

int main() {
    long long a, b, c;
    printf("Enter numbers:\n");
    scanf("%Ld, %Ld, %Ld", &a, &b, &c);
    long long res = a*b*c;
    printf("Composition: %Ld",res);
    return 0;
}
