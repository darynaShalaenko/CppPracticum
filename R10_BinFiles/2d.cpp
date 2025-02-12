#include <stdio.h>
#include <stdlib.h>

struct Toy
{
  char name[100];
  int value;
  int age_from;
  int age_to;
};


int main()
{
   int max_value = 0;
   FILE *fptr;
   struct Toy toi;

   if ((fptr = fopen("test.bin","rb")) == NULL)
   {
       printf("Error! opening file");
       exit(1);
   }

   for(int n = 0; n <= 3; ++n)
   {
      fread(&toi, sizeof(struct Toy), 1, fptr);
    //  printf("%s\t%d grn\tfrom %d to %d yo\n", toi.name, toi.value, toi.age_from, toi.age_to);
      if (max_value < toi.value)
      {
        max_value = toi.value;
      }
   }
   fclose(fptr);

   printf("most expensive toys:\n");

   fptr = fopen("test.bin","rb");
   for(int n = 0; n <= 3; ++n)
   {
      fread(&toi, sizeof(struct Toy), 1, fptr);
      if ((max_value - toi.value) <= 50)
      {
        printf("%s\n", toi.name);
      }
    }
   fclose(fptr);


   return 0;
}