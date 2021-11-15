
#include <
iostream>
#include <math.h>
using namespace std;
const int N = 3;

struct Point
{
    float x;
    float y;
    char sys;
};

void print_mas(Point arr[]);
void input_mas(Point arr[]);
Point input_point(Point p);
void print_point(Point p);

Point input_point(Point p)
{
    while(true)
    {
        printf("Which system polar or decart you want to use (p/d) - > ");
        cin >> p.sys;
        printf("Enter the point - > ");
        cin >> p.x >> p.y;
        if(p.sys == 'd')
            break;
        else if(p.sys == 'p')
        {
            if(p.y >= 0 && p.y <= 360)
                break;
        }
        else
            throw invalid_argument("0 <= phi <= 360");
    }
    return p;
}

void input_mas(Point arr[])
{
    for (int i = 0; i < N; i++)
    {
        Point p;
        arr[i] = input_point(p);
    }
}

void print_mas(Point arr[])
{
    for (int i = 0; i < N; i++)
    {
        print_point(arr[i]);
    }
}

void print_point(Point p)
{
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

void trans(Point arr[], Point arr1[])
{

    for(int i = 0; i < N; i++)
    {
        arr1[i].x = arr[i].x * cos(arr[i].y * (M_PI / 180));
        arr1[i].y = arr[i].x * sin(arr[i].y * (M_PI / 180));
        cout << '(' << arr1[i].x << ',' << " " << arr1[i].y << ')' << endl;
    }

}

void triag_square_dec(Point arr[],Point arr1[])
{
    float a, b, c, p, s;
    if(arr[0].sys == 'd')
    {

    a = sqrt(pow(arr[1].x - arr[0].x, 2) + pow(arr[1].y - arr[0].y, 2));
    b = sqrt(pow(arr[2].x - arr[1].x, 2) + pow(arr[2].y - arr[1].y, 2));
    c = sqrt(pow(arr[0].x - arr[2].x, 2) + pow(arr[0].y - arr[2].y, 2));

    p = (a + b + c) / 2;

    s =  sqrt(p * ( p - a ) * ( p - b ) * ( p - c));
    }
     if (arr[0].sys == 'p')
    {
        trans(arr,arr1);
        a = sqrt(pow(arr1[1].x - arr1[0].x, 2) + pow(arr1[1].y - arr1[0].y, 2));
        b = sqrt(pow(arr1[2].x - arr1[1].x, 2) + pow(arr1[2].y - arr1[1].y, 2));
        c = sqrt(pow(arr1[0].x - arr1[2].x, 2) + pow(arr1[0].y - arr1[2].y, 2));

        p = (a + b + c) / 2.0;

        s =  sqrt(p * ( p - a ) * ( p - b ) * ( p - c));

    }

    cout << "The square of triangle = " << s << endl;

}



int main()
{
    Point arr[N] = {};
    Point arr1[N] = {};
    input_mas(arr);
    print_mas(arr);

    triag_square_dec(arr,arr1);

}
