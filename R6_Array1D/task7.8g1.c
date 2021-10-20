#include <stdio.h>
#include <stdlib.h>
 
#define N 15
 
void fill ( size_t* arr )
{
    size_t i;
    for ( i = 0; i < N; ++i )
    {
        printf ( "%u > ", i + 1 );
        scanf ( "%u", arr + i );
    }
}
 
void print ( size_t* arr, size_t n, char a )
{
    size_t i;
    for ( i = 0; i < n; ++i )
        printf ( "%c[%u] = %u\n", a, i + 1, arr[i] );
}
 
size_t func ( size_t* a1, size_t* a2 )
{
    size_t i, k = 0;
    size_t j;
    for ( i = 0, j = 1; i < N; ++i, j = 1 )
        if ( ! ( a1[i] & ( a1[i] - 1 ) ) )
            a2[k++] = a1[i];
    return k;
}
 
int main ( void )
{
    size_t X[N];
    size_t k[N];
    printf ( "Inpun array X:\n" );
    fill ( X );
    printf ( "This is X:\n" );
    print ( X, N, 'X' );
    size_t M = func ( X, k );
    printf ( "This is k:\n" );
    print ( k, M, 'k' );
 
    return EXIT_SUCCESS;
}