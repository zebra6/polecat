/*
review to cover some of the different methods of generating subsets
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void subsets_bit_vector( int* ar, int sz );
void swap( int* a, int* b );
void print_ar( int* ar, int sz );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int ar[] = { 1, 2, 3, 4 };

	subsets_bit_vector( ar, 4 );
	printf( "\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void subsets_bit_vector( int* ar, int sz )
{
	int i = 0;
	int j = 0;
	int set_size = pow( 2, sz );

	printf( "subsets, bit vector approach:\n" );

	for( i = 0; i < set_size; i++ )
	{
		printf( "%i: ", i );
		for( j = 0; j < sz; j++ )
			if( i & ( 1 << j ) )
				printf( "%i ", ar[j] );

		printf( "\n" );
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}


/******************************************************************************
 *****************************************************************************/
void print_ar( int* ar, int sz )
{
	int i = 0;

	for( i = 0; i < sz; i++ )
		printf( "%i ", ar[i] );

	printf( "\n" );

	return;
}
