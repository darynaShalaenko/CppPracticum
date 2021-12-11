include <iostream>
#include <algorithm>

using namespace std;


class Rectangle
{
private:

    int length,width,x1,x2,y1,y2;

    void input_length()
    {
        cout << "input length: ";
        cin >> length;
    }

    void input_width()
    {
        cout << "input width: ";
        cin >> width;
    }

    void input_x1()
    {
        cout << "input x1: ";
        cin >> x1;
    }

    void input_y1()
    {
        cout << "input y1: ";
        cin >> y1;
    }

    void all_x_y()
    {
        x2=x1+length;
        y2=y1-width;
    }

public:

    Rectangle()
    {
        length=1;
        width=1;
        x1=1;
        y1=1;
        all_x_y();
        //cout << "Rectangle ";
        //print();
    }

    Rectangle(int length,int width,int x1,int y1)
    {
        if ((length == 0) or (width==0))
        {
            cerr << "Zero param!\n";
            throw;
        }
        this->length = length;
        this->width = width;
        this->x1 = x1;
        this->y1 = y1;
        cout << "Creating Rectangle "<<endl;
        all_x_y();
        print();
    }

    Rectangle(const Rectangle& a)
    {
        length = a.length;
        width = a.width;
        x1= a.x1;
        y1 = a.y1;
        all_x_y();
        cout << "Copying Rectangle "<<endl;
        print();
    }

    ~Rectangle()
    {
        cout << "Deleting Rectangle "<<endl;
        print();
    }



    int a()
    {
        return length;
    }
    int c()
    {
        return length;
    }
    int b()
    {
        return width;
    }
    int d()
    {
        return width;
    }
    void new_l_w()
    {
        length=x2-x1;
        width=y1-y2;
    }

    int square()
    {
        return length*width;
    }

    int perimetr()
    {
        return 2*(length+width);
    }

    void input()
    {
        input_length();
        input_width();
        input_x1();
        input_y1();
        all_x_y();
    }

    void print()
    {
        cout << "length " << length << endl;
        cout << "width " << width << endl;
        cout << "x1 " << x1 << endl;
        cout << "y1 " << y1 << endl<<endl;
    }

    void intersection(const Rectangle& other);
};


void Rectangle::intersection(const Rectangle& other)
{
    if (((x1 <= other.x1 && other.x1 <= x2) || (other.x1 <= x1 && x1 <= other.x2)) && ((y1 >= other.y1 && other.y1 >= y2) || (other.y1 >= y2 && y2 >= other.y2))) 
    {
        int xs[4] = {x1, x2, other.x1, other.x2};
        int ys[4] = {y1, y2, other.y1, other.y2};
        sort(xs, xs+4);
        sort(ys, ys+4);
        x1=xs[1]; 
        y1=ys[2]; 
        x2=xs[2]; 
        y2=ys[1];
        new_l_w();
    }
    else 
    {
        x1=-1;
        x2=-1;
        y1=-1;
        y2=-1;
    }
}


int main()
{
    Rectangle a{5,5,0,5}, b{4,4,2,3};
    //a.input();
    //b.input();
    a.print();
    b.print();

    cout << "intersection: ";
    a.intersection(b);
    a.print();


    Rectangle c{1, 4, 2, 3};
    c.print();

    Rectangle d(c);
    d.print();

    return 0;
}
