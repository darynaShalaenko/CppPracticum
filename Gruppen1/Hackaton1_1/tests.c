#include "analyze.h"

int main(){

   Team t1,t2;
   setTeam(&t1,"aaaaa",1);
   setTeam(&t2,"bbbb",2);
   
   addTeamToFile("f1.dat", t1);
   addTeamToFile("f1.dat", t2);  
   
   T_Match z1,z2;
   setMatch(&z1,1,2,1,1); 
   setMatch(&z2,1,2,1,1);  
   addMatchToFile("fm1.dat", z1);
   addMatchToFile("fm1.dat", z2);
  
   printf("%u", getLeader("f1.dat", "fm1.dat"));

}
