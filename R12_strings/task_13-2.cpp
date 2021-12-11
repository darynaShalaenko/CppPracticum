#include <iostream>
#include <string>


std::string newTwoDots(std::string line) {
    int firstdot = line.find(".");
    if (firstdot == std::string::npos) {
        int spaceend = line.find_first_not_of(" ");
        line.erase(0, spaceend);
    } else {
        int secdot = line.find(".", firstdot);
        if (secdot == std::string::npos) {
            line.erase(0, firstdot);
        } else {
            line.erase(firstdot, secdot-1);
        }
    }
    return line;
}


void implaceTwoDots(std::string &line) {
    int firstdot = line.find(".");
    if (firstdot == std::string::npos) {
        int spaceend = line.find_first_not_of(" ");
        line.erase(0, spaceend);
    } else {
        int secdot = line.find(".", firstdot);
        if (secdot == std::string::npos) {
            line.erase(0, firstdot);
        } else {
            line.erase(firstdot, secdot);
        }
    }
}



int main() {
    std::string str = "  Today.is a.good day";
    std::cout << newTwoDots(str);
    str = "  Today.is a good day";
    std::cout << std::endl << newTwoDots(str);
    str = "  Today is a good day";
    std::cout << std::endl << newTwoDots(str);
    implaceTwoDots(str);
    std::cout << std::endl << str;
}
