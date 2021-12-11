
#include <stdio.h>
#include <string.h>

typedef struct Country
{
    float p;
    float s;
} Country;

typedef struct Country *s;

int main()
{
    int n, i, number_min = 0;
    float ps_min = 0, ps_cur;
    printf("n = ");
    scanf("%d", &n);
    if(n > 0){
        struct Country new_country[n];
        for(i = 0; i < n; i++){
            printf("Country №%d\n", i+1);
            printf("p = ");
            scanf("%f", &ps_cur);
            new_country[i].p = ps_cur;
            printf("s = ");
            scanf("%f", &ps_cur);
            new_country[i].s = ps_cur;
        }
        for(i = 0; i < n; i++){
            ps_cur = new_country[i].p/new_country[i].s;
            if(i == 0){
                ps_min = ps_cur;
            }
            else if(ps_min > ps_cur){
                ps_min = ps_cur;
                number_min = i;
            }
        }
        printf("Min p/s = %f, country's number = %d.", ps_min, number_min+1);
    }
}
