#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 20



typedef struct {
    string name;
    string surname;
    string middle_name;
    string sex;
    int age;
    int YearInUnivesity;
} student;

void Output(student a) {
    cout << a.surname << a.name << a.middle_name << ", " << "the " << a.sex << a.age << " years, the  " << a.YearInUnivesity << "course of university" << endl;
}


student Input() {
    student a;
    cout  << "Enter name of the student :";
    cin >> a.name;
    cout  << "Enter surname of the student :";
    cin >> a.surname;
    cout  << "Enter middle name of the student :";
    cin >> a.middle_name;
    cout  << "Enter sex of the student :";
    cin >> a.sex;
    cout  << "Enter age of the student :";
    cin >> a.age;
    cout  << "Enter course of university of the student :";
    cin >> a.YearInUnivesity;
    return a;
}


//a
void most_popular_name(student arr[], int n) {
    int maxm = 0, maxw = 0;
    string mpnm, mpnw;
    int count;
    for (int i =0; i < n; i++) {
        if (arr[i].sex == "men"){
            for (int j = 0; j < n; j++){
                if (arr[i].name == arr[j].name){
                    count += 1;
                    if (count > maxm){
                        maxm = count;
                        mpnm = arr[i].name;
                    }
                }
            }
        }
        else {
            for (int j = 0; j < n; j++){
                if (arr[i].name == arr[j].name){
                    count += 1;
                    if (count > maxw){
                        maxw = count;
                        mpnw = arr[i].name;
                    }
                }
            }
        }
    }
    cout << "Most popular men's name : " << mpnm << endl;
    cout << "Most popular women's name : " << mpnw << endl;
}


//b
void Name_of_most_popular_age (student arr[], int n) {
    int mpa = 0, nmpa;
    int count = 0;
    student a;

    for (int i =0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if (arr[i].age == arr[j].age){
                count += 1;
                if (count > mpa){
                    mpa = count;
                    nmpa = arr[i].age;
                }
            }
        }
    }
    cout << "Most popular age" << nmpa << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i].age == mpa) {
            cout << a.surname << a.name[0] << ". " << a.middle_name[0] << ". " <<endl;

        }
    }
}

int main() {

    student p[N];
    unsigned n;
    cout << "Enter number of people : ";
    cin >> n;
    for (int i = 0; i<n; i++) {
        cout << "People number " << i + 1 << " : " << endl ;
        p[i] = Input();
    }
    most_popular_name(p,n);
    Name_of_most_popular_age(p,n);

}
