#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
int main() {
	float x1, y1, radius1, x2, y2, radius2,result;
	printf("input values x1 y1 radius\n");
	scanf_s("\n%f\n%f\n%f", &x1, &y1, & radius1);
	//printf("%f", radius1);
	printf("input values x2 y2 radius\n");
	scanf_s("\n%f\n%f\n%f", &x2, &y2, &radius2);
	//x,y - represent center of circle
	result = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
	if (result > (radius1 + radius2)) {
		printf("circles do not cross");
	}
	else {
		printf("cross of circles");
	}
}