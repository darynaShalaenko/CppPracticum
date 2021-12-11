#include <stdio.h>

int main(){
    unsigned char n = 138, new_n = n;
    int lng_n = sizeof(n)*8;
    while(lng_n > 0){
        new_n = n;
        new_n = new_n << 1;
        new_n = new_n >> 1;
        if(new_n != n){
            printf("X");
        }
        else{
            printf("Y");
        }
        n = n << 1;
        lng_n -= 1;
    }
}
