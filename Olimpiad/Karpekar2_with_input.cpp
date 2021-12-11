#include <iostream>
#include <string>

using namespace std;


string Number_zero(int n){
    string n_zero;
    string str = to_string(n);
    if (str.length()==1) n_zero="000"+str;
    if (str.length()==2) n_zero="00"+str;
    if (str.length()==3) n_zero="0"+str;
    
    return n_zero;
}

string Sort_minus(string n){
    
    int Array [4]={int(n[0])-48,int(n[1])-48,int(n[2])-48,int(n[3])-48}; //ASCII code start of 48
    //sort Array  upper
    int temp;
    for (int i = 0; i < 4- 1; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (Array[i] > Array[j])
            {
                temp = Array[i];
                Array[i] = Array[j];
                Array[j] = temp;
            }
        }
    }
    
    string number_1=to_string(Array[0])+to_string(Array[1])+to_string(Array[2])+to_string(Array[3]); 
    
    string number_2=to_string(Array[3])+to_string(Array[2])+to_string(Array[1])+to_string(Array[0]);
 
    int answer=stoi(number_2) - stoi(number_1);
    
    return  to_string(answer);

}

int main()
{
   int N , number;
   string new_number;
  
   cout<<"Count numbers --> "<<ends;
   cin>>N;
   int Array_info [N-1][3]; // number / new_number / counter_iterator 
   
   for (int i=0; i<N; i++){
       cout<<"Input number --> "<<ends;
       cin>>number;
       
       if (number < 1000){
           new_number=Number_zero(number);
       }
       else new_number=to_string(number);
       
       // Sort and minus
      
       int counter=0;
       string start_number=new_number; // for array
       while (true){
           if(new_number!=Sort_minus(new_number)){
               counter++;
               new_number=Sort_minus(new_number);
           }
           else break;
       }
       // add to array
       Array_info[i][0]=stoi(start_number);
       Array_info[i][1]=stoi(new_number);
       Array_info[i][2]=counter;
       
   }
   
   //output Array_info --> number / new_number / counter_iterator 
   cout<<"Array_info"<<endl;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < 3; j++)
        {
            cout << Array_info[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
