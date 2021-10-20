
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <stack>

using namespace std;
//t1,t2,sum

/*
inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

//Or if you want to do it the C++11 way:

bool is_number2(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

template <typename T>
const T to(const string& sval)
{
        T val;
        stringstream ss;
        ss << sval;
        ss >> val;
        if(ss.fail())
                throw runtime_error((string)typeid(T).name() + " type wanted: " + sval);
        return val;
}
*/


class Solution
{
 
public:
	int calPoints(string arr[],int n)
	{

          int kk=0;
          while(arr[kk++]!=""){
            cout<<kk;
          }
	    int res =0;
		vector<int> tmp;
		int k=0;

	    for(int i=0;i<n;++i){
                   string x = arr[i];
		   if(isdigit(x[0])) {
                      cout<<"x="<<x; 
		      int t1=0;
		      for(int j=0;j<x.length();++j){
			    t1 = 10*t1 + (x[j]-'0');
			  }
			  tmp.push_back(t1);
                       cout<<t1<<",";
		   }
		   else if (x[0]=='-'){
		     int t1=0;
			 for(int j=1;j<x.length();++j){
			      t1 =10*t1+ (x[j]-'0');
			 }
			 tmp.push_back(-t1);
                         cout<<t1<<",";
		   }
		   else if (x=="D"){
                       int k= tmp.size();   
		       int t1 = tmp[k-1]*2;
			   tmp.push_back(t1);
                       cout<<"d"<<t1<<",";  
		   }
		   else if (arr[i]=="C"){
                     cout<<"c";  
		    tmp.pop_back();
		   }
		   else if (arr[i]=="+"){
                      int k= tmp.size(); 
		      tmp.push_back(tmp[k-1]+tmp[k-2]);
		   }
		   else{
		      cout<<"error";
		   }
	
		}

		//return stoi(arr[0]);
		for(int i=0;i<tmp.size();++i ){

		   res += tmp[i];
                   cout<<"s="<<tmp[i]<<","<<res;  
		}
		return res;
	}
};


int main()
{
	vector<string> items;
	string item;

	string line;
	getline(cin, line);
	istringstream is(line);

	while (is >> item) {
		items.push_back(item);
	}

	Solution solution;

	cout << solution.calPoints(items.data(), items.size());
}
