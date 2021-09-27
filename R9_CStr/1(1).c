/*
 *4.Рядковий тип даних на Сі. Створення, ініціалізація та коректне використання. Функції string.h.
 *За допомогою цих функцій введіть n рядків та підрахуйте кількість різних слів в цих рядках.
Створення, ініціалізація та коректне використання:
fgets(str3,100,stdin)
char str4[100];
scanf("%s",str4);
void *memcpy(void *dest, const void *src, size_t n);	копіює n байтів з області пам'яті src в dest, які не повинні перетинатися, у іншому випадку результат невизначений (можливо як правильне копіювання, так і ні)
void *memmove(void *dest, const void *src, size_t n);	копіює n байтів з області пам'яті src в dest, які на відміну від memcpy можуть перекриватися
void *memchr(const void *s, char c, size_t n);	Повертає вказівник на перше входження з в перших n байтах s, або NULL, якщо не знайдено
int memcmp(const void *s1, const void *s2, size_t n);	порівнює перші n символів в областях пам'яті
void *memset(void *, int z, size_t);	заповнює область пам'яті одним байтом z
char *strcat(char *dest, const char *src);	дописує рядок src в кінець dest
char *strncat(char *dest, const char *, size_t);	дописує не більше n початкових символів рядка src (або всю src, якщо її довжина менше) у кінець dest
char *strchr(const char *, int);	шукає символ у рядку, починаючи з голови і повертає його адресу, або NULL якщо не знайдений
char *strrchr(const char *, int);	шукає символ у рядку, починаючи з хвоста і повертає його адресу, або NULL якщо не знайдений
int strcmp(const char *, const char *);	лексикографічне порівняння рядків
int strncmp(const char *, const char *, size_t);	лексикографічне порівняння перших n байтів рядків
int strcoll(const char *, const char *);	лексикографічне порівняння рядків з урахуванням локалі collating order
char *strcpy(char *toHere, const char *fromHere);	копіює рядок з одного місця в інше
char *strncpy(char *toHere, const char *fromHere, size_t n);	копіює до n байт рядку з одного місця в інше
char *strerror(int);	повертає строкове подання повідомлення про помилку errno (не потоко-безпечна)
size_t strlen(const char *);	повертає довжину рядка
size_t strspn(const char *s, const char *accept);	визначає максимальну довжину початкового підрядка, що складається виключно з байтів, перерахованих в accept
size_t strcspn(const char *s, const char *reject);	визначає максимальну довжину початкового підрядка, що складається виключно з байтів, не перелічених у reject
char *strpbrk(const char *s, const char *accept);	знаходить перше входження будь-якого символу, перерахованого в accept
char *strstr(const char *haystack, const char *needle);	знаходить перше входження рядка needle в haystack
char *strtok(char *, const char *);	перетворює рядок у послідовність токенів. Не потіко-безпечна, нереєнтрантна.
size_t strxfrm(char *dest, const char *src, size_t n);	створює відтрансльовану копію рядка, таку, що дослівне порівняння її (strcmp) буде еквівалентно порівнянню з коллатором.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    size_t words_counter = 0, counter = 0;
    int add ;
    char **strings;
    char temp[1024];
    FILE *in_file  = fopen("../file.txt","r");

    // know how many words
    while (fscanf(in_file, " %1023s", temp) == 1) {
        words_counter++;
    }

    // array of all different word
    strings = malloc(words_counter*sizeof(char*));
    for (size_t i = 0; i <= words_counter; i++) {
        strings[i] = malloc(sizeof(char*));
    }

    // pointer to start
    fseek(in_file, 0, SEEK_SET);

    // skip first word
    fscanf(in_file, " %1023s", temp);

    // counting different words
    while (fscanf(in_file, " %1023s", temp) == 1) {
        add = 0;
        for (size_t i = 0; i < counter; i++)
            if (strcmp(strings[i], temp) == 0)
                add = 1;

        if (add == 0) {
            counter++;
            strcpy(strings[counter-1], temp);
        }
    }

    // final result
    printf("Count strings: %zu\n", counter);

    return 0;
}
