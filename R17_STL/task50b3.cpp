#include <cstdio>

int main() {
    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    int n = 1, t = 9, r = 9, k1, x, i, res;
    while(k > r) {
        n++;
        t *= 10;
        r += n*t;
    }
    k1 = k - r + n*t;
    x = (t/9) + (k1 - 1)/n;
    i = n - ( (k1 - 1) % n );
    while(i > 0) {
        res = x % 10;
        x /= 10;
        i--;
    }
    printf("res: %d\n", res);
    return 0;
}