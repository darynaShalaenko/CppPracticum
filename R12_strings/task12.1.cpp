#include <iostream>

using namespace std;

int main()
{
  string st = "asdfg:efsfrg:awdawdadadtyhy:yjcgj ;ddrg";
  string res1, res2, res3;
  int i = -1;
  int check = 0;

  while (st[i] != ':')
  {
      i++;
      res1 += st[i];
  }

  i++;

  while (st[i] != '\0')
  {
     res2 += st[i];

     if (st[i] == ':')
     {check = 1;}

     if (check == 0)
     {res3 += st[i];}

     i++;
  }


  cout << "text before first ':' = " << res1 << endl;
  cout << "text after first ':'  = " << res2 << endl;
  cout << "text between ':'      = " << res3 << endl;

  return 0;
}