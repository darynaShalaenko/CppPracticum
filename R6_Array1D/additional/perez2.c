#include <stdio.h>
#include <string.h>
#define MAX 20


int main()
{
    char key[MAX];  // створимо "словник", де значення масиву key - цифри, що зустрічаються в числі num
    int value[MAX];  // value - поставлена у відповідність кожному зі значень масиву key к-кість входжень в число num даної цифри
    int ki = 0;  // індекс для проходження по словнику key та value відповідно
    
    
    char num[MAX];
    printf("Input your number: ");
    scanf("%s", num);
    
    for (int i = 0; i < strlen(num); i++) {
        int cnt = 0;
        for (int j = 0; j < MAX; j++) {  // перевіряємо наявність значення num[i] в масиві key
            if (key[j] == num[i]) {
                cnt = -1;
                break;
            }
        }
        if (cnt != -1) {
            key[ki] = num[i];
            int val = 0;
            for (int p = 0; p < strlen(num); p++) {  // рахуємо к-еість входжень num[i] в число num
                if (num[p] == num[i]) val++;
            }
            value[ki] = val;
            ki++;
        }
        
    }
    
    int max_i = 0, mem = 0;  // max_i - індекс елемента з найбільшою к-кістю входжень, mem - к-кість входжень попереднього перевіреного елемента
    char max;
    for (int i = 0; i < ki; i++) {
        if (value[i] > mem) {
            mem = value[i];
            max_i = i;
            max = key[i];
        } 
        else if (value[i] == mem) {
            if (key[i] > key[max_i]) {
                mem = value[i];
                max_i = i;
                max = key[i];
            }
        }
    }

    printf("The most common element: %c\n", max);
    printf("It occurs in an array %d times\n", value[max_i]);

    return 0;
}