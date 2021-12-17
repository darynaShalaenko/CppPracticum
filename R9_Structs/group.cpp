#include <iostream>
#include <cctype>


using namespace std;

template < typename T >
T minimum (T a, T b){
    if ( a < b ){
        return a;
    }
    if ( b < a ){
        return b;
    }

}

int randRage (int low, int high){
    return rand() % ( high - low + 1 ) + low;
}

const int NUM = 50;

class people{
public:
    int age;
    string name;
    string last_name;
};

class prepod{
    string name_course;
};

class aspirrant{
    string name_course;
};


class students: public people{
    public:
        int mark [NUM];

        void sort_marks (){
            for ( int i = 0; i < NUM; i++ ){
                mark [i] = randRage ( 1, 100 );
            }

            int temp;

            for (int i = 0; i < NUM ; i++) {
                for (int j = 0; j < NUM - i ; j++) {
                    if (mark[j] > mark[j + 1]) {
                        temp = mark[j];
                        mark[j] = mark[j + 1];
                        mark[j + 1] = temp;
                    }
                }
            }
        }

        int avg_mark (){
            int sum;
            int avg;
            for ( int i = 0; i < NUM; i++ ){
                sum += mark [i];
            }
            avg = sum/NUM;
            return ( avg );
        }


};








int main()
{
    students group[NUM];
    for ( int i = 0; i < NUM; i++ ){
        group[i].sort_marks();
    }
    int x = 1;
    for ( int i = 0; i < NUM; i++ ){
        x = randRage( 1, 10 );
        switch ( x ){
        case 1:
            group[i].name = "Victor";
            break;
        case 2:
            group[i].name = "Max";
            break;
        case 3:
            group[i].name = "Valera";
            break;
        case 4:
            group[i].name = "Roman";
            break;
        case 5:
            group[i].name = "Yuriy";
            break;
        case 6:
            group[i].name = "Vasilii";
            break;
        case 7:
            group[i].name = "Artem";
            break;
        case 8:
            group[i].name = "Nikolay";
            break;
        case 9:
            group[i].name = "Vladimir";
            break;
        case 10:
            group[i].name = "Vladislav";
            break;
        }


    }
    for ( int i = 0; i < NUM; i++ ){
        //system ("cls");
        cout << "Student " << i+1 << ":" << endl;
        cout << "================================================================================" ;
        cout << "All marks:" << endl << endl;
        for ( int j = 0; j < NUM; j++ ){
            cout << group[i].mark[j] << " " ;
        }
        cout  << endl << endl;
        cout << "Average mark:" << endl << endl;
        cout << group[i].avg_mark () << endl << endl;
        cout  << endl << endl;
        cout << "Name:" << endl << endl;
        cout << group[i].name << endl << endl;
        cout  << "================================================================================" << endl;
       // Sleep (1000);
    }
}


