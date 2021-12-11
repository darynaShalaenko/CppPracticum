#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Book{
public:
    Book (){
        title = "NAME";
        author = "AUTHOR";
        n_pages = "0";
        y_p = "0000";
    }
    Book(string a, string b, string c, string d){
        title = a;
        author = b;
        n_pages = c;
        y_p = d;
    }

    void print(){
        cout << title << " " << author << " " << n_pages << " " << y_p << endl;
    }

    string get_author(){
        return author;
    }

    string get_title(){
        return title;
    }

private:
    string title, author, n_pages, y_p;
};

Book* DelArr(Book* Arr, int temp, int count){
    Book* arr = new Book[temp - count];
    for (int i = 0; i < temp-count; i++)
    {
        arr[i] = Arr[i];
    }
    delete[] Arr;
    return arr;
}

void print_books(Book arr[], char ch, string a, int n){
    int j = 0;
    if (ch == 'a'){
        for (int i = 0; i < n; i++){
            if (arr[i].get_author() == a){
                arr[i].print();
                j++;
            }
        }
    }
    else {
        for(int i; i < n; i++){
            if(arr[i].get_title() == a){
                arr[i].print();
                j++;
            }
        }
    }
    if (!j)
        cout << "Books not found" << endl;
}

int main(){
    int n = 1000;
    string filename = "books.txt";
    Book* arr = new Book[n];
    int count_b = 0;
    ifstream fin(filename);
    if (!fin.good()) exit(1);
    string line;
    while (getline(fin, line)){
        stringstream input(line);
        string a, b, c, d;
        input >> a;
        input.ignore(256, ' ');
        input >> b;
        input.ignore(256, ' ');
        input >> c;
        input.ignore(256, ' ');
        input >> d;
        Book book(a, b, c, d);
        arr[count_b] = book;
        count_b++;
    }
    arr = DelArr(arr, n, n-count_b);
    cout << "Available books: " << endl;
    for(int i = 0; i < count_b; i++){
        arr[i].print();
    }
    cout << endl;

    while (true){
        cout << "Author or title ? (a / t) : ";
        char ch;
        string a;
        cin >> ch;

        if (ch == 'a'){
            cout << "Author's name : ";
            cin >> a;
            print_books(arr, ch, a, count_b);
        }
        if (ch == 't'){
            cout << "Book title : ";
            cin >> a;
            print_books(arr, ch, a, count_b);
        }
        cout << "Finish ? (y / n) : ";
        cin >> ch;
        if (ch == 'y')
            break;
    }
    return 0;
}
