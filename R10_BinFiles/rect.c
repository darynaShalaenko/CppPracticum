#include <stdio.h>
#include <stdlib.h>

typedef struct Coord{
   float x,y;
}Coord;


typedef struct Rect{
  unsigned num; // number of rect

  Coord LD; // left-upper
  Coord RU; // right-bottom

} Rect;

int vvod(Rect* r){
    
  printf("input n, x,y :");
  scanf("%u",&(r->num));
  printf("left-down vertex:");
  scanf("%f",&(r->LD.x));
  scanf("%f",&(r->LD.y));
  printf("right-upper vertex:");
  scanf("%f",&(r->RU.x));
  scanf("%f",&(r->RU.y));
  
  return EXIT_SUCCESS;
}


int addRect(const char* fname){

  unsigned n;
  Rect r1;
  printf("Number or rectangles:");
  scanf("%u", &n);

  FILE* f = fopen(fname, "wb");
  
  for(unsigned i=0; i<n;++i){
     vvod(&r1);
     fwrite(&r1,1,sizeof(r1),f);
  }

  fclose(f);
}


double rectArea(const Rect * r){
     float x1 = r->LD.x;
     float x2 = r->RU.x;

     float y1 = r->LD.y;
     float y2 = r->RU.y;
     return (x2-x1)*(y2-y1);
}


unsigned maxrect(const char * fname){

  unsigned n=-1;
  Rect r1;
  FILE* f = fopen(fname, "rb");
  double maxarea = 0;

  while(!feof(f)){
     
     int r =fread(&r1,sizeof(r1),1,f);
     if(r<1) break;

     double z =  rectArea(&r1);
     
     if(z>maxarea){
        maxarea = z;
        n = r1.num;
    }     

  }

  fclose(f);

  printf("Max area = %lf\n", maxarea);
  return n;
}

int deleteRectByNumber(const char * fname, unsigned num){
    
    FILE* f = fopen(fname, "rb");
    FILE* g = fopen("tmpfile.dat", "wb");
    Rect r1;
    while(!feof(f)){
     
     int r =fread(&r1,sizeof(r1),1,f);
     if(r<1) break;

     if(r1.num != num){
          fwrite(&r1,1,sizeof(r1),g);
     }  

     }

  fclose(f);
  fclose(g);

  rename("tmpfile.dat", fname);
  
  return EXIT_SUCCESS;
}


int editRectByNumber(const char * fname, unsigned num, const Rect* rect){

    FILE* f = fopen(fname, "rb");
    FILE* g = fopen("tmpfile.dat", "wb");
    Rect r1;
    while(!feof(f)){
     
     int r =fread(&r1,sizeof(r1),1,f);
     if(r<1) break;

     if(r1.num != num){
          fwrite(&r1,1,sizeof(r1),g);
     }  
     else{
        fwrite(&rect,1,sizeof(r1),g);
     }
     }

  fclose(f);
  fclose(g);

  rename("tmpfile.dat", fname);
  
  return EXIT_SUCCESS;
}


int main(){

  addRect("rect.dat");

  deleteRectByNumber("rect.dat",1);

  printf("%u", maxrect("rect.dat")); 
}


