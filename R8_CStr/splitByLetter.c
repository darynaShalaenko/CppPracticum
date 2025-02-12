
// ЗАДАЧА
// для використання макроса assert (до прикладу assert 1 > 0 викличе помилку)
#include <assert.h>
// для вводу-виводу
#include <stdio.h>
// для динамічного виділення пам'ят
#include <stdlib.h>
// для ф-цій оброблення рядківі
#include <string.h>

// ф-ція, що повертає масив слів, утворених з рядка str та розділені символами з
// стрічки delim у size запишеться майбутній розмір того масиву
char **split(const char *str, const char *delim, int *size) {
  // для копії стрічки, так як strtok модифікує стрічку
  char *aux;
  // для кожного слова
  char *p;
  // для результуючого масиву стрічок
  char **res;
  // тимчасовий масив із заданим розміром, так як початково ми не знаємо його
  char *strings[2 << 6];
  // кількість оброблених слів
  int n = 0;

  // скопіюємо str y aux -> якщо буде якась помилка, передана strdup, assert про
  // це повідомить
  assert(aux = strdup(str));
  // доки є слова у стрічці
  for (p = strtok(aux, delim); p; p = strtok(NULL, delim))
    // записуємо їх у масив
    strings[n++] = p;

  // виділяємо уже відому к-кість пам'яті для результуючого масиву
  assert(res = calloc(n, sizeof(char *)));
  // копіюємо відповідні значення слів
  for (int i = 0; i < n; i++)
    res[i] = strings[i];

  // встановлюємо розмір для повернення
  *size = n;

  // повертаємо
  return res;
}

int main(void) {
  char str[255];
  char letter;

  // зчитування
  printf("Enter a sentence: ");
  fgets(str, 255, stdin);

  printf("Enter first letter: ");
  letter = getchar();

  // змінна для розміру масиву слів
  int size;

  // визначаємо масив слів за допомогою попередньо описаної функції
  char **words = split(str, " \n", &size);

  for (int i = 0; i < size; i++) {
    if (words[i][0] == letter) {
      printf("%s\n", words[i]);
    }
  }

  // вивільнення пам'яті
  // від слів
  free(words);

  return 0;
}
