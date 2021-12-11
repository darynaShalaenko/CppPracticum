
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


class Product {

private:

    string name,measure,date;
    int code, price;


public:

    Product(string _name, string _measure, int _code, int _price, string _date): 
        name(_name), measure(_measure), code(_code), price(_price), string(_date) {}


    string& get_name() {return name;}
    string& get_measure() {return measure;}
    int& get_code() {return code;}
    int& get_price() {return price;}
    string& get_date() {return date;}

    void set_price(int _price) {this->price = _price;}

    virtual void input(istream& inp = cin) {
        inp >> name >> measure >> code >> price >> date;
    }

    virtual void print(ostream& out = cout, bool endline = true) {
        out << name << ' ' << measure << ' ' << code << ' ' << price << ' ' << date;
        if (endline) out << endl;
    }

    Product istream& operator>>(istream& inp, Product& p) {
        p.input(inp);
        return inp;
    }

    Product ostream& operator<<(ostream& out, Product& p) {
        p.print(out, false);
        return out;
    }

};


class Food: public Product {

private:

    int suitable;

public:

    Food(string _name, string _measure, int _code, int _price, string _date, int _suitable):
        Product(_name, _measure, _code, _price, _date), suitable(_suitable) {}

    int& get_suitable() {return suitable;}
    void set_suitable(string suitable) {this->suitable = suitable;}

    virtual void input(istream& inp = cin) {
        Product::input(inp);
        inp >> suitable;
    }

    virtual void print(ostream& out = cout, bool endline = true) {
        Product::print(out, false);
        out << ' ' << suitable;
        if (endline) out << endl;
    }

};

class Toys: public Product {

private:

    string age_restrictions;

public:

    Toys(string _name, string _measure, int _code, int _price, string _date, string _age_restrictions):
        Product(_name, _measure, _code, _price, _date), age_restrictions(_age_restrictions) {}

    string& get_age_restrictions() {return age_restrictions;}
    void set_age_restrictions(string age_restrictions) {this->age_restrictions = age_restrictions;}

    virtual void input(istream& inp = cin) {
        Product::input(inp);
        inp >> age_restrictions;
    }

    virtual void print(ostream& out = cout, bool endline = true) {
        Product::print(out, false);
        out << ' ' << age_restrictions;
        if (endline) out << endl;
    }

};

class Technique: public Product {

private:

    bool guarantee;
    int garantee_time;

public:

    Technique(string _name, string _measure, int _code, int _price, string _date, bool _guarantee, int _guarantee_time):
        Product(_name, _measure, _code, _price, _date), guarantee(_guarantee), guarantee_time(_guarantee_time) {}

    bool& get_guarantee() {return guarantee;}
    void set_guarantee(string guarantee) {this->guarantee = guarantee;}

    int& get_garantee_time() {return garantee_time;}
    void set_garantee_time(string garantee_time) {this->garantee_time = garantee_time;}


    virtual void input(istream& inp = cin) {
        Product::input(inp);
        inp >> guarantee;
        inp >> guarantee_time;
    }

    virtual void print(ostream& out = cout, bool endline = true) {
        Product::print(out, false);
        out << ' ' << guarantee << ' ' << guarantee_time;
        if (endline) out << endl;
    }

};


class Book {

private:

    string filename;

public:

    Book(string filename): filename(filename) {}

    void create() {
        ofstream f(filename);
        f.close();
    }

    void add_product(Product& t) {
        ofstream f(filename, ofstream::app);
        f << t << endl;
        f.close();
    }

    Product find_product(string name) {
        ifstream f(filename);
        Product t("PRODUCT");
        while (f.good()) {
            f >> t;
            if (f.fail())
                throw logic_error("Cannot find product " + name);
            if (t.get_name() == name)
                break;
        }
        f.close();
        return t;
    }

    void change_price(string name, int price) {
        ifstream finp(filename);
        Product p("PRODUCT");

        ostringstream oss;
        while (finp.good()) {
            finp >> p;
            if (finp.fail())
                break;
            if (p.get_name() == name)
                p.set_price(price);
            oss << p << endl;
        }
        finp.close();

        ofstream fout(filename);
        fout << oss.str();
        fout.close();
    }

    void sale() {
        ifstream finp(filename);
        Product p("PRODUCT");

        ostringstream oss;
        while (finp.good()) {
            finp >> p;
            if (finp.fail())
                break;
            if (p.get_suitable() < 5 or p.get_garantee_time <5)
                p.set_price(p.price*0.8);
            oss << p << endl;
        }
        finp.close();

        ofstream fout(filename);
        fout << oss.str();
        fout.close();
    }


};



int main() {
    Toys c("car", "piece", 111, 150, "13.02.2021", "more than 2");
    Food i("ice cream", "kg", 222, 50, "21.12.2021", 7);
    Technique b("bicycle", "piece", 333, 1000, "1.12.2021", true, 365);

    Book book("Book.txt");
    book.create();
    book.add_product(c);
    book.add_product(i);
    book.add_product(b);

    Product a;
    a=find_product("car");

    book.sale();

    return 0;
} 
