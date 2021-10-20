#include <cstdio>

int main() {
    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    int i = 1, j = 1;
    while(i < k) {
        i += j;
        j++;
    }
    if (i == k) printf("res: %d\n", 1);
    else printf("res: %d\n", 0);
    return 0;
}