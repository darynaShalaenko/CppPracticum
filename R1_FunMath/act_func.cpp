#include <stdio.h>
#include <math.h>

double exp_act(double x) {	
  return x>0?x:exp(x);
}

double relu(double x, double alpha){

	return x>0?alpha*x:x;
 	
}


double Function1(double x, double alpha){
   
     return x<0?alpha*(exp(x)-1):x;
}


double gauss_act(double x) {

	return exp(-x-x);
}
double gauss_act_derivative(double x) {
	return gauss_act(x) * (-2 * x);
	
}

double sigmweight(float x) {
    return x * 1.0 / (1.0 + expf(-x));
}

double deriv(float x, float eps) {
    return (sigmweight(x + eps) - sigmweight(x)) / eps;
}

double ReLu(double x)
{
    if (x >= 0) {
        return x;
    } else {
        return 0;
    }
}

double deriv(float x, float eps) {
    return (ReLu(x + eps) - ReLu(x)) / eps;
}

int main() {
	double x;
	printf("x = ");
	scanf_s("%lf",&x);

	if (x < 0) {
		printf("%f %f",exp(x), exp_act(x));
	}
	else {
		printf("%f", x, exp_act(x));
	}
}
