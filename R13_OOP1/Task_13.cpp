#include <iostream>
#include <math.h>
using namespace std;

class Vector3
{
private:
    double x; double y; double z;
public:
    Vector3() {};
    Vector3(double j, double k, double i)
    {
        x = j;
        y = k;
        z = i;
    };
    void input()
    {
        cout << "x, y, z =";
        cin >> x >> y >> z;
    }

    void output()
    {
        cout << "x = " << x << " y = " << y << " z = " << z << endl;
    }


    double get_x()
    {
        return x;
    }

    double get_y()
    {
        return y;
    }
    double get_z()
    {
        return z;
    }
    Vector3 operator+(Vector3 c2)
    {
        Vector3 test(this->x + c2.x, this->y + c2.y, this->z + c2.z);
        return test;
    }
    Vector3 operator-(Vector3 c2)
    {
        Vector3 test(this->x - c2.x, this->y - c2.y, this->z - c2.z);
        return test;
    }
    Vector3 operator*(Vector3 c2)
    {
        double x1 = this->x;
        double y1 = this->y;
        double z1 = this->z;
        double x2 = c2.x;
        double y2 = c2.y;
        double z2 = c2.z;
        Vector3 test(y1*z2 - z1*y2, z1 * x2 - x1 * z2, x1*y2 - x2*y1);
        return test;
    }
    double mod()
    {
        return pow(this->x * this->x + this->y * this->y + this->z * this->z, 0.5);
    }

};
class Matrix3
{
private:
    double* x = new double[3];
    double* y = new double[3];
    double* z = new double[3];
public:
    Matrix3() {};
    Matrix3(double* j, double* k, double* i)
    {
        x = j;
        y = k;
        z = i;
    };

    void output()
    {
        
        for (int i = 0; i < 3; i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << y[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << z[i] << " ";
        }
        cout << endl;
    }
    Matrix3 operator+(Matrix3 c2)
    {
        double* newx = new double[3];
        double* newy = new double[3];
        double* newz = new double[3];
        for (int i = 0; i < 3; i++)
        {
            newx[i] = this->x[i] + c2.x[i];
        }
        for (int i = 0; i < 3; i++)
        {
            newy[i] = this->y[i] + c2.y[i];
        }
        for (int i = 0; i < 3; i++)
        {
            newz[i] = this->z[i] + c2.z[i];
        }
        Matrix3 test(newx, newy, newz);
        return test;
    }
    Matrix3 operator-(Matrix3 c2)
    {
        double* newx = new double[3];
        double* newy = new double[3];
        double* newz = new double[3];
        for (int i = 0; i < 3; i++)
        {
            newx[i] = this->x[i] - c2.x[i];
        }
        for (int i = 0; i < 3; i++)
        {
            newy[i] = this->y[i] - c2.y[i];
        }
        for (int i = 0; i < 3; i++)
        {
            newz[i] = this->z[i] - c2.z[i];
        }
        Matrix3 test(newx, newy, newz);
        return test;
    }
    Matrix3 operator*(Matrix3 c2)
    {
        double* newx = new double[3];
        double* newy = new double[3];
        double* newz = new double[3];
        for (int i = 0; i < 3; i++)
        {
            newx[i] = this->x[0] * c2.x[i] + this->x[1] * c2.y[i] + this->x[2] * c2.z[i];
        }
        for (int i = 0; i < 3; i++)
        {
            newy[i] = this->y[0] * c2.x[i] + this->y[1] * c2.y[i] + this->y[2] * c2.z[i];
        }
        for (int i = 0; i < 3; i++)
        {
            newz[i] = this->z[0] * c2.x[i] + this->z[1] * c2.y[i] + this->z[2] * c2.z[i];
        }
        Matrix3 test(newx, newy, newz);
        return test;
    }
    Vector3 operator*(Vector3 c2)
    {
        double newx ;
        double newy ;
        double newz ;
        for (int i = 0; i < 3; i++)
        {
            newx = this->x[0] * c2.get_x() + this->x[1] * c2.get_y() + this->x[2] * c2.get_z();
        }
        for (int i = 0; i < 3; i++)
        {
            newy = this->y[0] * c2.get_x() + this->y[1] * c2.get_y() + this->y[2] * c2.get_z();
        }
        for (int i = 0; i < 3; i++)
        {
            newz = this->z[0] * c2.get_x() + this->z[1] * c2.get_y() + this->z[2] * c2.get_z();
        }
        Vector3 test(newx, newy, newz);
        return test;
    }
    Matrix3 operator+(Vector3 c2)
    {
        double* newx = new double;
        double* newy = new double;
        double* newz = new double;
        for (int i = 0; i < 3; i++)
        {
            newx[i] = this->x[i] + c2.get_x() ;
        }
        for (int i = 0; i < 3; i++)
        {
            newy[i] = this->y[i] + c2.get_x() ;
        }
        for (int i = 0; i < 3; i++)
        {
            newz[i] = this->z[i] + c2.get_x() ;
        }
        Matrix3 test(newx, newy, newz);
        return test;
    }
    double det()
    {
        double* a1 = this->x;
        double* a2 = this->y;
        double* a3 = this->z;
        double det = a1[0] * a2[1] * a3[2] + a1[1] * a2[2] * a3[0] + a1[2] * a2[0] * a3[1] - a1[2] * a2[1] * a3[0] - a1[1] * a2[0] * a3[2] - a1[0] * a2[2] * a3[1];
        return det;
    }

};
int main()
{
    double x[3] = { 2 , 3 , 4 };
    double y[3] = { 4 , 3 , -1 };
    double z[3] = { 2 , 1 , 4 };
    Matrix3 k(x, y, z);
    Matrix3 k1(x, z, y);
    Vector3 res;
    Vector3 v(1, 2, 3);
    res = k * v;
    res.output();
    cout << res.mod() << endl;
    cout << k.det() << endl;

}
