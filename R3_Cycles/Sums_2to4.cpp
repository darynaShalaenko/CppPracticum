//Представити дане натуральне число як суму двох натуральних чисел. 
//Якщо це неможливо представити як суму трьох квадратів.
//Якщо і це неможливо представити у вигляді чотирьох квадратів натуральних чисел.

#include <iostream>
#include <iomanip>
using namespace std;

bool SumOfTwo(int number, int* pn1, int* pn2)
{
    for (int n1 = 1; n1 * n1 < number / 2; n1++)
    {
        for (int n2 = 1; n1 * n1 + n2 * n2 <= number; n2++)
        {
            if (n1 * n1 + n2 * n2 == number) {
                *pn1 = n1;
                *pn2 = n2;
                return true;
            }
        }
    }
    return false;
}

bool SumOfThree(int number, int* pn1, int* pn2, int* pn3)
{
    for (int n1 = 1; n1 * n1 < number / 3; n1++)
    {
        for (int n2 = 1; n1 * n1 + n2 * n2 < number * 2 / 3; n2++)
        {
            for (int n3 = 1; n1 * n1 + n2 * n2 + n3 * n3 <= number; n3++)
            {
                if (n1 * n1 + n2 * n2 + n3 * n3 == number) {
                    *pn1 = n1;
                    *pn2 = n2;
                    *pn3 = n3;
                    return true;
                }
            }
        }
    }
    return false;
}

bool SumOfFour(int number, int* pn1, int* pn2, int* pn3, int* pn4)
{
    for (int n1 = 1; n1 * n1 < number / 4; n1++)
    {
        for (int n2 = 1; n1 * n1 + n2 * n2 < number / 2; n2++)
        {
            for (int n3 = 1; n1 * n1 + n2 * n2 + n3 * n3 < number * 3 / 4; n3++)
            {
                for (int n4 = 1; n1 * n1 + n2 * n2 + n3 * n3 + n4 * n4 <= number; n4++)
                {
                    if (n1 * n1 + n2 * n2 + n3 * n3 + n4 * n4 == number) {
                        *pn1 = n1;
                        *pn2 = n2;
                        *pn3 = n3;
                        *pn4 = n4;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


int main()
{
    int n, n1, n2, n3, n4;
    std::cout << "N = ";
    std::cin >> n; //читаємо число n з клавіатури
    if (SumOfTwo(n, &n1, &n2))
    {
        std::cout << "Found: " << n << " = " << n1 << "^2 + " << n2 << "^2";
    }
    else if (SumOfThree(n, &n1, &n2, &n3))
    {
        std::cout << "Found: " << n << " = " << n1 << "^2 + " << n2 << "^2 + " << n3 << "^2";
    }
    else if (SumOfFour(n, &n1, &n2, &n3, &n4))
    {
        std::cout << "Found: " << n << " = " << n1 << "^2 + " << n2 << "^2 + " << n3 << "^2 + " << n4 << "^2";
    }
    else
    {
        std::cout << "Can't find solution for N = " << n;
    }
    std::cout << "\n";
    system("pause");
}
