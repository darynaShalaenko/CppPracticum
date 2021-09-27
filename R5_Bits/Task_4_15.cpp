

#include <iostream>
using namespace std;


int checkbit(const int value, const int position) {
    return ((value & (1 << position)) != 0);
}

int main()
{
    char a;
    size_t len = sizeof(int) * CHAR_BIT;
    int count1 = 0, count2 = 0;
    cin >> a;
    for (int i = 0; i <len; i++)
    {
        if (checkbit(a, i))
        {
            count1 = i;
            break;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (checkbit(a, len -i))
        {
            count2 = i;
            break;
        }
    }
    cout << count1<<endl;
    cout << count2<<endl;
}
