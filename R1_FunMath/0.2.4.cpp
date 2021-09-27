#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	//Тут потрібно вводити координати вершин еліпса
	float x1, y1, x2, y2;
	printf("x1 = ");
	scanf("%f", &x1);
	printf("y1 = ");
	scanf("%f", &y1);
	printf("x2 = ");
	scanf("%f", &x2);
	printf("y2 = ");
	scanf("%f", &y2);
	float a = sqrt(pow(x1, 2) + pow(y1, 2));
	float b = sqrt(pow(x2, 2) + pow(y2, 2));
	printf("%f", 3.14 * a * b);
	getchar();
	getchar();
}
