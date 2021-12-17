#include <iostream>
#include <vector> 

#include <cstdio> 

using namespace std;
 
class Date{
    private:
        int day;
        int month;
        int year;
        
    
        bool vys(int year){
            bool res = false;
            if (year % 4 == 0)
                res= true;
            if (year % 100 == 0)
                res= false;
            if (year % 400 == 0)
                res = true;
            return res;
        } // проверка года на высокосность 
    
        void Add(Date &d){
            int mes[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (vys(d.year))
                mes[1]= 29;
            d.day++;
            if (d.day>mes[d.month-1]){
                d.day= 1;
                d.month++;
                if (d.month>12){
                    d.month= 1;
                    d.year++;
                }
            }
        } //увечивает дату на 1 день вперед
    
    
    public:
        
        void Input(){
            cin >> day >> month >> year;
        }
        void Output(){
            cout << day << ' ' << month << ' ' << year << endl;
        }
    
        int cmp(Date d2){
            Date d1 = *this;
            if (d1.year > d2.year)
                return 1;
            else
                if (d1.year < d2.year)
                    return -1;
                else
                    if (d1.month > d2.month)
                        return 1;
                    else
                        if (d1.month < d2.month)
                            return -1;
                        else
                            if (d1.day > d2.day)
                                return 1;
                            else
                                if (d2.day < d2.day)
                                    return -1;
            return 0;
        } // фунция для сравнения двух дат, если d1 моложе d2, то возращается 1, если старше, то возращается -1, если даты одинаковые возращается 0

        int raz(Date d){
            Date date1 = *this;
            Date date2 = d;
            if (date1.cmp(date2) > 0)
                swap(date1, date2);
            int ans=0;
            for (int i = date1.year; i < date2.year; i++){
                ans += 365;
                if (vys(i))
                    ans++;
            }
            while ((date1.day != date2.day)||(date1.month != date2.month)){
                ans++;
                Add(date1);
            }
            return ans;
        } //подсчитывает разницу между датами
 
};
 
 
 
int main(){

    freopen("input.txt", "r", stdin);

    vector <Date> arr;

    int n;
    cin >> n;

    arr.resize(n);

    for (int i = 0; i < n; i++)
        arr[i].Input();

    int min_el = 0, max_el = 0;

    for (int i = 1; i < n; i++){
        if (arr[i].cmp(arr[min_el]) == -1)
            min_el = i;
        if (arr[i].cmp(arr[max_el]) == 1)
            max_el = i;
    }

    cout << "max old = ";
    arr[min_el].Output();
    cout << "max nex = ";
    arr[max_el].Output();


    cout << "answer = " << arr[min_el].raz(arr[max_el]) << endl;

    return 0;
}
