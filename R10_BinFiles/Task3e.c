

      
    
  

    

  


  



        
          
              

            
          

          
        
  



            
              
                
                


        
      



    
    
          }




    
    
          





    
    
          int main() {




    
    
              const char* fname="F.dat";




    
    
              FILE* F=fopen(fname, "wb");




    
    
              if(F==NULL){




    
    
                  fprintf(stderr, "Error open file %s",fname);




    
    
                  return -1;




    
    
              }




    
    
              int n;




    
    
              printf("n=");




    
    
              scanf("%d",&n);




    
    
              double x;




    
    
              for(int i=0;i<n;i++){




    
    
                  printf("x=");




    
    
                  scanf("%lf",&x);




    
    
                  fwrite(&x, sizeof(x), 1, F);




    
    
              }




    
    
              fclose(F);




    
    
              double a;




    
    
              printf("a=");




    
    
              scanf("%lf",&a);




    
    
              F=fopen(fname, "rb");




    
    
              double mas[10];




    
    
              const char* fname2="G.dat";




    
    
              FILE* G=fopen(fname2, "wb");




    
    
              int i=0;




    
    
              int k=0;




    
    
              while (1) {




    
    
                  if(feof(F))break;




    
    
                  fread(&x,sizeof(x),1,F);




    
    
                  if (isFibonacci(x)){




    
    
                      fwrite(&x, sizeof(x), 1, G);




    
    
                  }




    
    
                  else{




    
    
                      mas[k++]=x;




    
    
                  }




    
    
                  i++;




    
    
              }




    
    
              fclose(F);




    
    
              fclose(G);




    
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isFibonacci(int  w)
{
       double X1 = 5 * pow(w, 2) + 4;
       double X2 = 5 * pow(w, 2) - 4;

       long X1_sqrt = (long)sqrt(X1);
       long X2_sqrt = (long)sqrt(X2);

       return (X1_sqrt*X1_sqrt == X1) || (X2_sqrt*X2_sqrt == X2) ;
/*https://ru.stackoverflow.com/questions/970873/%D0%9E%D0%BF%D1%80%D0%B5%D0%B4%D0%B5%D0%BB%D0%B8%D1%82%D1%8C-%D1%8F%D0%B2%D0%BB%D1%8F%D0%B5%D1%82%D1%81%D1%8F-%D0%BB%D0%B8-%D1%87%D0%B8%D1%81%D0%BB%D0%BE-%D1%8D%D0%BB%D0%B5%D0%BC%D0%B5%D0%BD%D1%82%D0%BE%D0%BC-%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8-%D0%A4%D0%B8%D0%B1%D0%BE%D0%BD%D0%B0%D1%87%D1%87%D0%B8
*/
}

int main() {
    const char* fname="F.dat";
    FILE* F=fopen(fname, "wb");
    if(F==NULL){
        fprintf(stderr, "Error open file %s",fname);
        return -1;
    }
    int n;
    printf("n=");
    scanf("%d",&n);
    double x;
    for(int i=0;i<n;i++){
        printf("x=");
        scanf("%lf",&x);
        fwrite(&x, sizeof(x), 1, F);
    }
    fclose(F);
    double a;
    printf("a=");
    scanf("%lf",&a);
    F=fopen(fname, "rb");
    double mas[10];
    const char* fname2="G.dat";
    FILE* G=fopen(fname2, "wb");
    int i=0;
    int k=0;
    while (1) {
        if(feof(F))break;
        fread(&x,sizeof(x),1,F);
        if (isFibonacci(x)){
            fwrite(&x, sizeof(x), 1, G);
        }
        else{
            mas[k++]=x;
        }
        i++;
    }
    fclose(F);
    fclose(G);
