//Hw1 №0.0.5b
/*Умова:
 Вивести на екран текст: 
 б) a----------a
    |      a      |
    a----------a
де a – введена з клавіатури цифра.
*/

#include <stdio.h>

int main()
{
	int a;
	printf("a=");
	scanf_s("%d", &a);
	printf("%5d----------%5d\n", a, a);
	printf("|     %5d     |\n", a);
	printf("%5d----------%5d\n", a, a);
}
