#include <iostream>
#include <fstream>
#include <map>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

void createTestFile(const std::string &name){
    std::ofstream f1(name,std::ios_base::out | std::ios_base::trunc);

    assert(f1.is_open());
    f1<<"12 11 2020; 20 July 2004; 17 September 2017; 01 07 2009; 17 09 2017; 12 10 2020";
    f1.close();
}

std::vector<std::string> split (const std::string& s, const std::string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr(pos_start));
    return res;
}

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

struct Date{
    int day;
    int month;
    int year;

    bool operator==(const Date &rhs) const {
        return day == rhs.day &&
               year == rhs.year &&
               month == rhs.month;
    }

    bool operator!=(const Date &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Date &rhs) const {
        if (year < rhs.year)
            return true;
        if (rhs.year < year)
            return false;

        if (month < rhs.month)
            return true;
        if (rhs.month < month)
            return false;

        return day < rhs.day;
    }

    bool operator>(const Date &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Date &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Date &rhs) const {
        return !(*this < rhs);
    }
};

int rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

int datediff(Date date1, Date date2){
    return rdn(date1.year, date1.month, date1.day) - rdn(date2.year, date2.month, date2.day);
}

void task2(const std::string &filename){
    std::map<std::string, int> months = {
            {"December",12},
            {"January",1},
            {"February",2},
            {"March",3},
            {"April",4},
            {"May",5},
            {"June",6},
            {"July",7},
            {"August",8},
            {"September",9},
            {"October",10},
            {"November",11}
    };

    std::map<int,std::string> months_reverse;

    for (std::pair<std::string,int> p: months){
        std::pair<int,std::string> p_rev(p.second,p.first);
        months_reverse.insert(p_rev);
    }

    std::ifstream f2(filename, std::ios_base::in);

    assert(f2.is_open());

    std::stringstream buffer;
    buffer << f2.rdbuf();
    std::string data = buffer.str();

    f2.close();

    std::cout<<"Dates:\n    "<<data<<std::endl<<std::endl;

    std::vector<std::string> dates = split(data,";");

    std::set<Date> realDates;

    for (std::string date: dates){
        trim(date);
        std::vector<std::string> DD_MM_YYYY = split(date," ");
        int day = std::stoi(DD_MM_YYYY[0]);
        int month;
        if (months.count(DD_MM_YYYY[1])){
            month = months[DD_MM_YYYY[1]];
        } else {
            month = std::stoi(DD_MM_YYYY[1]);
        }
        int year = std::stoi(DD_MM_YYYY[2]);


        realDates.insert({day,month,year});
        //std::cout<<year<<'/'<<months_reverse[month]<<'/'<<day<<std::endl;
    }

    Date minDate = *realDates.begin();
    Date maxDate = *realDates.rbegin();

    std::cout<<"Min date: "<<minDate.year<<'/'<<months_reverse[minDate.month]<<'/'<<minDate.day<<std::endl;
    std::cout<<"Max date: "<<maxDate.year<<'/'<<months_reverse[maxDate.month]<<'/'<<maxDate.day<<std::endl;

    //Date d1 = {12,10,2020};
    //Date d2 = {12,9,2020};
    //std::cout<<"Date difference (test): "<<datediff(d1,d2)<<std::endl;

    std::cout<<"Date difference (max_date-min_date, in days): "<<datediff(maxDate,minDate)<<std::endl;
}

int main() {
    std::string filename = "dates.txt";

    createTestFile(filename);
    task2(filename);
    int x;
    std::cin>>x;
    return 0;
}
