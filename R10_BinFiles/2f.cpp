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
   int n;
   int aim_age = 3;
   int toys_count = 4;

   FILE *fptr;
   struct Toy tois[toys_count];

   if ((fptr = fopen("test.bin","rb")) == NULL)
   {
       printf("Error! opening file");
       exit(1);
   }

   for(n = 0; n < toys_count; ++n)
   {
      fread(&tois[n], sizeof(struct Toy), 1, fptr);
   }

   fclose(fptr);

   for (int i = 0; i <= toys_count; i++)
   {
     for (int j = 0; j <= toys_count; j ++)
     {
       if (i != j)
       {
         if (((tois[i].value + tois[j].value) <= 20) &&
              (tois[i].age_from <= aim_age) && ((tois[j].age_from <= aim_age)) &&
              (tois[i].age_to >= aim_age) && (tois[j].age_to >= aim_age))
              {
                printf("%s and %s are good for you\n", tois[i].name, tois[j].name);
              }
        }
     }
   }

   return 0;
}