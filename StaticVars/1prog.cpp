#include <iostream>
using namespace std;
 
int Hello ()
{
    static int count = 0;
    cout << "Hello world!\n";
    ++count;
    return count;
}
 
int main()
{
    cout << Hello() << '\n';
    cout << Hello() << '\n';
    cout << Hello() << '\n';
    cout << Hello() << '\n';
	cout << Hello() << '\n';
    
	return 0;
}
