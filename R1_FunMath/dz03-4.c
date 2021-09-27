#include <stdio.h>
#include<math.h>

void pr(double x, double y, double z)
{
	double p = x + y + z;
	printf("%f\n", p);
	return;
}

void sq(double x, double y, double z)
{
	double pp = (x + y + z) / 2;
	double s = sqrt(pp*(pp - x)*(pp - y)*(pp - z));
	printf("%f\n", s);
	return;
}


int main(){
	double f;
	pr(4342, 5, 4);
	sq(2, 2, 1);
getchar();
getchar();
}
