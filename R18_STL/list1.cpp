#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    deque <int> mylist = {};
    int n;
    cout << "Enter length of list ->";
    cin >> n;

    for (int i = 0; i < n; i++){
        cout << "Enter elem of list ->";
        int a;
        cin >> a;
        mylist.push_back(a);
    }
    sort( mylist.begin(), mylist.end() );

    while( ! mylist.empty() ) {

            cout << mylist.front() << '\n';
            mylist.pop_front();
    }


}
