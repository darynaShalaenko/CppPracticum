/* 5. У файлі зберігаються назви товарів і ціни в гривнях та копійках 
 * (формат «*** hrn ** cop)).
 * Створити новий файл, перетворивши ціни товару в долари та центи додавши
 * найменування "dollars" і "cents". Цени при цьому змінюються множенням на
 * коефіцієнт kurs, що вводиться з клавіатури. */

#include <stdio.h>
#include <stdlib.h>


int main()
{
        double kurs;
        printf("Input kurs:");
        scanf("%lf", &kurs);

        char *inputpath = "hrn-products.txt";
        char *outputpath = "dollars-produts.txt";

        FILE *f_reader = fopen(inputpath, "r");
        FILE *f_writer = fopen(outputpath, "w");

        if (f_reader == NULL) {
                printf("ERROR! Can not read file!\n");
                fclose(f_reader);
                exit(1);
        }

        if (f_writer == NULL) {
                printf("ERROR! Can not write file!\n");
                fclose(f_writer);
                exit(1);
        }

        char buffer[4096], pname[1024];
        int hrn, cop, dol, cen;

        while (fgets(buffer, sizeof(buffer), f_reader)) {
                if (sscanf(buffer, "%s %d hrn %d cop", pname, &hrn, &cop) == 3) {
                        printf("Read %s %d hrn %d cop\n", pname, hrn, cop);
                } else {
                        printf("Can not parse the file!\n");
                }

                dol = ((double)hrn + (double)(cop) / 100.0) / kurs;
                cen = (((double)hrn + (double)(cop) / 100.0) / kurs - dol) * 100;
                fprintf(f_writer, "%s %d dollars %d cents\n", pname, dol, cen);
                printf("%s %d dollars %d cents\n\n", pname, dol, cen);
        }

        fclose(f_reader);
        fclose(f_writer);
}
