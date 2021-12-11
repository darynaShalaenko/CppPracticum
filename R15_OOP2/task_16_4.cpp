#include <iostream>
#include <fstream>
#include <cmath>
#define filename "inf.txt"

using namespace std;


class Person {
    string name;
    unsigned byear;

public:
    Person(istream& infile) {
        infile >> name >> byear;
    }

    Person(string name, unsigned byear): name(name), byear(byear) {}

    void input() {
        cin >> name;
        cin >> byear;
    }

    void print() {
        cout << name << ", " << byear << endl;
    }

    string get_name() {return name;}
    void set_name(string n) {name = n;}
    unsigned get_byear() {return byear;}
    void set_byear(unsigned b) {byear = b;}
};


class Student: public Person {
    unsigned* points, exam_number, average_5;
    float average_100;
    bool scholarship_old, scholarship_new;

public:
    Student(istream& infile, unsigned exam_number) : Person(infile), exam_number(exam_number) {
        points = new unsigned[exam_number];
        unsigned sum = 0;
        for (int i = 0; i < exam_number; i++) {
            infile >> points[i];
            sum += points[i];
        }
        average_100 = (float) sum/exam_number;
        average_5 = (unsigned) round(average_100*0.05);
    }

    Student(string name="STUDENT", unsigned byear=2000): Person(name, byear) {}

    void print() {
        Person::print();
        cout << average_100 << ", " << average_5 << endl;
        cout << endl;
    }

    void scholarship_old_method() {
        scholarship_old = (average_5 >= 4);
    }

    void scholarship_new_method(Student* students, int file_len) {
        int per_40 = file_len*4/10;
        scholarship_new = false;
        for (int i = 0; i < file_len; i++) {
            int largest_ind = i;
            for(int j = i; j < file_len; j++) {
                if (students[j].get_average_100() > students[largest_ind].get_average_100())
                    largest_ind = j;
            }
            swap(students[i], students[largest_ind]);
        }


        for (int i = 0; i < per_40; i++) {
            if (get_name() == students[i].get_name()) {
                scholarship_new = true;
                break;
            }
        }
    }

    float get_average_100() {return average_100;}

    void has_scholarship_old() {
        if (scholarship_old) {
            cout << get_name() << " has scholarship using old method" << endl;
        } else {cout << get_name() << " hasn't scholarship using old method" << endl;}
    }

    void has_scholarship_new() {
        if (scholarship_new) {
            cout << get_name() << " has scholarship using old method" << endl;
        } else {cout << get_name() << " hasn't scholarship using old method" << endl;}
    }
};


int main() {
    ifstream infile;
    infile.open(filename);
    int file_len = 0;
    string str;
    while (getline(infile, str)) {
        if (str != "")
            file_len += 1;
    }
    infile.clear();
    infile.seekg(0);

    Student* students = new Student[file_len];
    int i = 0;
    while (i < file_len){
        Student student(infile, 4);
        student.print();
        students[i++] = student;
    }

    for(int j = 0; j<i; j++){
        students[j].scholarship_old_method();
        students[j].scholarship_new_method(students, file_len);
        students[j].has_scholarship_old();
        students[j].has_scholarship_new();
        cout << endl;
    }

    return 0;
}
