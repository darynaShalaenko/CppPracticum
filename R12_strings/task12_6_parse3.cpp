#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;

int main(){
    string text = "He said. The challenge Hector heard with joy, "
               "Then with his spear restrain'd the youth of Troy ";

    istringstream iss(text);
    copy(std::istream_iterator<string>(iss),
         std::istream_iterator<string>(),
         std::ostream_iterator<string>(cout, "\n"));


    return EXIT_SUCCESS;
}

