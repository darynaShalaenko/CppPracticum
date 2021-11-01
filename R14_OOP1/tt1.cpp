#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
	int countElements(int arr[], int n)
	{
          int kk=0;
          while(arr[kk++]){
            cout<<kk;
          }

          int result=0;
          for(int i=0;i<n;++i){
              int tmp = arr[i];
              tmp++;
              bool exist=false;
              for(int j=0;j<n;++j){
                 if(tmp==arr[j]){
                     exist=true;
                    break;
                 }
              }
              if(exist){
                result++;
             }  
          }

         return result;
	}
};


int main()
{
	vector<int> items;
	int item;

	string line;
	getline(cin, line);
	istringstream is(line);

	while (is >> item) {
		items.push_back(item);
	}

	Solution solution;
	
	cout << solution.countElements(items.data(), items.size());
       
}

