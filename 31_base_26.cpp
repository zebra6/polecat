#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SZ 16
#define MAX 10

void print_array( int* ar, int sz );
int count_ways_r( int* ar, int asz, int off );
int count_ways_i( int* ar, int* ways, int asz, int off );

int main( int argc, char** argv )
{
	srand( time( NULL ) );
	int i = 0;
	int asz = rand() % SZ;
	int* ar = (int*)calloc( 1, sizeof(int) * asz );
	int* ways = (int*)calloc( 1, sizeof(int) * asz );
	int br[4] = { 1, 3, 1, 3 };

	for( i = 0; i < asz; i ++ )
		ar[i] = rand() % MAX;

	print_array( ar, asz );
	printf( "ways: %i\n", count_ways_r( ar, asz, 0 ) );
	printf( "ways: %i\n", count_ways_i( ar, ways, asz, 0 ) );

	if( ways ) free( ways );
	if( ar ) free( ar );
	return 0;
}

/******************************************************************************
 *****************************************************************************/
void print_array( int* ar, int sz )
{
	int i = 0;

	for( i = 0; i < sz; i ++ )
		printf( "%i", ar[i] );
	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
int count_ways_r( int* ar, int asz, int off )
{
	int retv = 0;

	/*base cases*/
	if( off > asz )
		return 0;
	if( off == asz )
		return 1;

	/*recurse - take care of the case where we use this as two numbers*/
	if( ar[off] >= 0 && ar[off] < 2 )
		retv = count_ways_r( ar, asz, off+2 );
	
	retv += count_ways_r( ar, asz, off+1 );

	return retv;
}


/******************************************************************************
 *****************************************************************************/
int count_ways_i( int* ar, int* ways, int asz, int off )
{
	int retv = 0;

	if( ar[off] >= 0 && ar[off] < 2 )
		retv = count_ways_r( ar, asz, off+2 );
	
	if( ways[off] )
		retv += ways[off];
	else
		retv += count_ways_r( ar, asz, off+1 );

	ways[off] = retv;
	return retv;
}

