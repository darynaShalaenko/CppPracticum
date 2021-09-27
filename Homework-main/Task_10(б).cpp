#include <iostream>
#include <set>
#include <string>
#include <list>
using namespace std;

class Auto {
private:
    string name;
    string model;
    int number;
    string id;
public:
    Auto() {};
    Auto(string x, string y, int z, string h) {
        name = x;
        model = y;
        number = z;
        id = h;
    };
    void Get_Auto() {
        cout << this->name << ", " << this->model << ", " << this->number << ", " << this->id<<endl;
    }
    bool operator>(Auto c2)
    {
        string s1 = this-> name;
        string s2 = c2.name;
        bool k = s1 > s2;
        return k;
        
    }
    bool operator<(Auto c2)
    {
        string s1 = this->name;
        string s2 = c2.name;
        bool k = s1 < s2;
        return k;

    }
    bool operator==(Auto c2)
    {
        string s1 = this->name;
        string s2 = c2.name;
        bool k = s1 == s2;
        return k;

    }

    int get_numer()
    {
        return number;
    }
    

};

ostream& operator<<(ostream& out, Auto i)
{
    out << i.get_numer();
    return out;
}

int main()
{
    Auto m("mazda", "cx5", 231, "AB1");
    Auto f("ferari", "cool", 232, "AB2");
    Auto l("lamborgini", "diablo", 233, "AB3");
    Auto w("wolsfagen", "polo", 234, "AB4");
    list <Auto> List = { m, f ,l, w };
    List.sort();

    copy(List.begin(), List.end(), ostream_iterator<Auto>(cout, " "));

 
}