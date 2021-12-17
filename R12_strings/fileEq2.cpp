#include <stdio.h>
#include <iostream>

using namespace std;

char return_letter( FILE * fp){

    while ( true ){
        char c = fgetc (fp);
        if ( c >= 'A' && c <= 'z' ){
            return c;
        }
        if (  feof(fp)  )
            break ;
    }
    return EOF;
}

int main ()
{
    FILE *fp1 = fopen("1.txt","r");
    FILE *fp2 = fopen("2.txt","r");
    char c1, c2;
    while ( true ){
        c1 = return_letter ( fp1 );
        c2 = return_letter ( fp2 );
        if ( c1 != c2 || c1 == EOF || c2 == EOF ){
            break;
        }
    }
    if ( c1 != c2 ){
        cout << "file not eq" ;
    }
    else {
        cout << "file eq" ;
    }
    fclose(fp2);
    fclose(fp1);
    return(0);
}



