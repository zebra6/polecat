#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

void print_subsets( int n, int k );

/*
2.
I/P: N, k
O/P: all subset of N with exactly K elements.

eg: I/p: N = 5, K =3
O/p:

1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
2 3 4
2 3 5
3 4 5
*/


int main( int argc, char** argv )
{
	int n = 0;
	int k = 0;

	assert( argc == 3 );

	n = atoi( argv[1] );
	k = atoi( argv[2] );

	print_subsets( n, k );

	return 0;
}


void print_subsets( int n, int k )
{
	int i = 0;
	int j = 0;
	int z = 0;
	double set_sz = pow( 2, n );
	int* ar = (int*)calloc( 1, sizeof(int) * n );
	char to_print[64] = { '\0' };
	
	/*check args*/
	if( n <= k )
		printf( "arg error\n" );

	/*populate the array*/
	for( i = 0; i < n; i ++ )
		ar[i] = i+1;

	/*find the subsets*/
	for( i = 0; i < set_sz; i ++ )
	{
		z = 0;
		memset( to_print, 0, 64 );

		for( j = 0; j < n; j ++ )
			if( i & 1 << j )
				to_print[z++] = ar[j] + '0';
		
		if( z == k )
			printf( "z: %i, %s\n", z, to_print );	
	}

	return;
}


