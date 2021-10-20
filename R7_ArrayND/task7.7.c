

#include <stdio.h>

#define N 100
#define M 100

int vvod(int matr[N][M], unsigned n, unsigned m){
    
   for(unsigned i=0;i<n;++i){
       for(unsigned j=0;j<m;++j){
           scanf(" %d",&matr[i][j]);
       }  
    }
}

unsigned max_col(int row[], unsigned n){

   int max_el = row[0];
   unsigned k =0;

   for(unsigned i=1;i<n;++i){
	if(max_el<row[i]){
		max_el = row[i];
		k = i;
	}
   }
   return k;
}

void vyvod(int matr[N][M], unsigned n, unsigned m){

  for(int i=0;i<n;++i){
       for(int j=0;j<m;++j){
           printf("%d, ",matr[i][j]);
       }  
       printf("\n");
    }

}

int gauss2(int matr[][M], unsigned n, unsigned m){

    for(unsigned i=0;i<n;++i){
        unsigned k = max_col(matr[i],m);
        printf("\nmax = %u",k);
        if(k==i) continue;
        // swap column

        for(unsigned j=i;j<n;j++){
            int tmp = matr[j][k];
	    matr[j][k] = matr[j][i];
            matr[j][i] = tmp;	
	}
        vyvod(matr,n,m);
    }
}



int main(){

  unsigned n,m;
  int matr[N][M];
  
  scanf("%u %u",&n,&m);

  vvod(matr,n,m);

  gauss2(matr,n,m);

  vyvod(matr,n,m);
}
