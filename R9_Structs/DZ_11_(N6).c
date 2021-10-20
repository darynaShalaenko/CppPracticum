#include <stdio.h>
#include <math.h>

typedef struct {
  double a, b;
  int coord;
} point;

double area(point p1, point p2, point p3) {
  double x1, y1;
  if (p1.coord == 1) {
    x1 = p1.a;
    y1 = p1.b;
  } else {
    x1 = p1.a * cos(p1.b);
    y1 = p1.a * sin(p1.b);
  }

  double x2, y2;
  if (p2.coord == 1) {
    x2 = p2.a;
    y2 = p2.b;
  } else {
    x2 = p2.a * cos(p2.b);
    y2 = p2.a * sin(p2.b);
  }

  double x3, y3;
  if (p3.coord == 1) {
    x3 = p3.a;
    y3 = p3.b;
  } else {
    x3 = p3.a * cos(p3.b);
    y3 = p3.a * sin(p3.b);
  }

  return 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

int main() {
  printf("hello world\n");

  printf("1) area = %f\n", area(
    (point){ 1.0, 1.0, 1 },
    (point){ 2.0, 5.0, 1 },
    (point){ 5.0, 3.0, 1 }
  ));

  printf("2) area = %f\n", area(
    (point){ 1.4142135623731, 0.78539816339745, 2 },
    (point){ 5.3851648071345, 1.1902899496825 , 2 },
    (point){ 5.8309518948453, 0.54041950027058, 2 }
  ));

  return 0;
}