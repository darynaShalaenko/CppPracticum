// task Polar/Cartesian Triangle

typedef struct Point{
  double x,y;
  int coord;
} Point;

typedef struct Triangle{
   Point p1,p2,p3;
} Triangle;

int inputPoint(Point* pt){
  printf("type coordinate system(c/p):");
  char c[10];
  scanf("%s ",c);
  int coord=0; 
  while(1){
   if(strlen(c)>0){
    if(tolower(c[0])=='p') {coord=1;break;}
    if(tolower(c[0])=='c') {break;}
   }
   printf("input once more"); 
  }

  if(coord==0){
    printf("x=");
    scanf("%lf",&pt->x);
    printf("y=");
    scanf("%lf",&pt->y);
    pt->coord =0;
  }
  else{
    printf("r=");
    scanf("%lf",&pt->x);
    printf("phi=");
    scanf("%lf",&pt->y);
    pt->coord =1;
  }  
}

void to_cart(Point* p){
   double r = p->x;
   p->x = r * sin(p->y);
   p->y = r * cos(p->y);
}


double dist(Point p1,Point p2){
   Point z1=p1,z2=p2;
   if(z1.coord==1){
     to_cart(&z1);
  }
  if(z2.coord==1){
     to_cart(&z2);
  }

  double zx = (z1.x-z2.x);
  double zy = (z1.y-z2.y);
  return (zx*zx + zy*zy);
}

double area(double a, double b, double c){
   double p = (a+b+c)/2;
   return sqrt(p*(p-a)*(p-b)*(p-c)); 
}

double sqrTraingle(const Triangle* t){
   double a,b,c;
   a = dist(t->p1,t->p2);
   b = dist(t->p1,t->p3);
   c = dist(t->p3,t->p2);
   return area(a,b,c);
}

int inputTriangle(Triangle* t){
   inputPoint(&(t->p1));
   inputPoint(&(t->p2));
   inputPoint(&(t->p3));
}

int main(){
   Triangle t;
   inputTriangle(&t);
   printf("area of traingle is %lf",sqrTraingle(&t));

}
