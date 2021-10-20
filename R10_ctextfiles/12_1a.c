#include <stdio.h>
#include <ctype.h>


int main()
{
   char ch;
   char file_name[100] = "F.txt";
   char aim_file[100] = "G.txt";
   char arr[] = {};
   int i = 0;
   FILE *fp;
   FILE *gp;

   fp = fopen(file_name, "r"); 

   while((ch = fgetc(fp)) != EOF)
      {
        arr[i] = ch;
        i++;
      }

   fclose(fp);
   gp = fopen("G.txt","w");
   for (int r = 0; r < i; r++)
   {
     fprintf(gp,"%c", tolower(arr[r]));
   }
   fclose(gp);

   printf("done\n");
   return 0;
}