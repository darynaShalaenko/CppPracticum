#include <iostream>
#include <string>
#include <cctype>


int CountWords(std::string line) {
    int space = 0, next_space = line.find(" ", space);
    int counter = 0;
    while (space != std::string::npos) {
        if (space != 0) space++;
        std::string word = line.substr(space, next_space-space);
        char start = word.substr(0, 1).c_str()[0];
        char ending = word.substr(word.size()-1, 1).c_str()[0];
        if (tolower(start) == tolower(ending)) counter++;
        space = next_space;
        next_space = line.find(" ", space+1);
    }
    return counter;
}


int main() {
    std::string str;
    std::cout << "Enter string: ";
    getline(std::cin, str);
    std::cout << "There are " << CountWords(str) << " words with same first and last letter!";
}
