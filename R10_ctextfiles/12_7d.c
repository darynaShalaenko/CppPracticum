#include <stdio.h>


int main ()
{
    FILE *fp;
    fp = fopen("file_with_words.txt", "r");
    int m = 0;
    int k = 0;
    int i;
    do
    {
        while ((getc(fp) != '\n') && (!feof(fp)))
            k++;
        if (k > m)
        {
          m = k;
        }
        k = 0;
    } while (!feof(fp));

    rewind (fp);

    FILE *fp_out;
    fp_out = fopen ("H.txt", "w");
    int space;
    int len;
    int begin;
    char c;
    do
    {
        space = len=0;
        begin = ftell (fp);
        while (((c = getc(fp)) != '\n') && (!feof(fp)))
        {
            if (c == ' ') space++;
            len++;
        }
        fseek (fp, begin, SEEK_SET);
        while (((c = getc(fp)) != '\n') && (!feof(fp)))
        {
            if (c !=' ') fprintf (fp_out, "%c", c);
            else
            {
                if ((m-len) % space)
                {
                    k = (m - len) / space + 2;
                    len++;
                }
                else k = (m - len) / space + 1;
                for (i = 0; i < k; i++)
                    fprintf (fp_out, " ");
            }
        }
        fprintf (fp_out, "\n");
    } while (!feof(fp));
    fclose (fp);
    fclose (fp_out);

    printf("done\n");
    return 0;
}