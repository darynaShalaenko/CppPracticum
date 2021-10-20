#include <iostream>

using namespace std;
int main()
{
   int nominals[] = {50, 25, 10, 5, 2, 1};
   int sum;
   cout << "Enter Sum: ";
   cin >> sum;
   int i = 0, amount;
   if (sum<99){
       cout << "Amount can be exchanged \n";
       while(sum > 0){
            if(sum >= nominals[i]){
                amount = sum / nominals[i];
                cout << "Number of coins : " << amount << " worth "
                << nominals[i] <<" kopeсk" << endl;
                sum = sum - amount * nominals[i];
                i++;
            }

        else{
            i++;
        }
   }
   }
}
