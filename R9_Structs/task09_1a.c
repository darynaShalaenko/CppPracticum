
#include <stdio.h>


typedef struct Date{
   int day;
   int month;
   int year; 
} Date;


Date inputDate(){
   int d,m,y;
   printf("input day:");
   scanf("%d",&d);
   printf("input month:");
   scanf("%d",&m);
   printf("input year:");
   scanf("%d",&y);

   Date res = {d,m,y};
   return res;
}

int inputDate2(Date * date){
   printf("Input day:");
   scanf("%d",&date->day); // ->  
   printf("input month:");
   scanf("%d",&(*date).month);
   printf("input year:");
   scanf("%d",&date->year);
   return 0;
}


void printDate(const Date* date1){
      printf(" %d.%d.%d \n",date1->day,date1->month,date1->year); 
}


int main(){

  Date date1;
  //scanf("%struct?",&date1);
  //cin>>date1;
  date1.day = 12;
  date1.month = 10;
  date1.year = 2021;

  //cout<<date1;
  printDate(date1);

  Date date2, date3;
  date2 = inputDate();  
  printDate(date2);

  inputDate2(&date3);
  printDate(date3);
}
