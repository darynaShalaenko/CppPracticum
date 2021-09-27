#include <stdio.h>
#include <math.h>
int main(){
	double x_1,x_2,x_3,x_4,x_5,y_1,y_2,y_3,y_4,y_5;
	printf("x1 = ");
	scanf_s("%lf", &x_1);
	printf("x2 = ");
	scanf_s("%lf", &x_2);
	printf("x3 = ");
	scanf_s("%lf", &x_3);
	printf("x4 = ");
	scanf_s("%lf", &x_4);
	printf("x5 = ");
	scanf_s("%lf", &x_5);
	x_1 = x_1 * x_1 * (-1);
	x_2 = x_2 * x_2 * (-1);
	x_3 = x_3 * x_3 * (-1);
	x_4 = x_4 * x_4 * (-1);
	x_5 = x_5 * x_5 * (-1);
	y_1 = exp(x_1);
	y_2 = exp(x_2);
	y_3 = exp(x_3);
	y_4 = exp(x_4);
	y_5 = exp(x_5);
	printf("x\t        1 \t        2 \t        3 \t        4\t        5\ny\t%9lf\t%9lf\t%9lf\t%9lf\t%9lf\n",y_1,y_2,y_3,y_4,y_5);
}
