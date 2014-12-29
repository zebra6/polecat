/*
   kanade's algorithm to find the longest subsum of a 1d array
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 16

void print_ar( int* ar, int start, int end );
int max3( int a, int b, int c );
void find_largest( int* ar, int sz );
void find_largest_r( int* ar, int sz );
int find_largest_r2( int* ar, int sz, int start, int end );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int ar[MAX] = { 0 };

	srand(time(NULL));

	for( i = 0; i < MAX; i++ )
	{
		ar[i] = rand() % MAX;
		if( rand() % 2 )
			ar[i] *= -1;
	}

	printf( "input arrays:\n" );
	print_ar( ar, 0, MAX-1 );
	find_largest( ar, MAX );
	find_largest_r( ar, MAX );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void print_ar( int* ar, int start, int end )
{
	int i = 0;

	for( i = start; i <= end; i++ )
		printf( "%4i", i );
	printf( "\n" );
	for( i = start; i <= end; i++ )
		printf( "%4i", ar[i] );

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
int max3( int a, int b, int c )
{
	if( a < b )
		return( b > c ) ? b : c;
	else
		return( a > c ) ? a : c;
}


/******************************************************************************
 *****************************************************************************/
void find_largest( int* ar, int sz )
{
	int i = 0;
	int max_so_far = 0;
	int max_ending_here = 0;

	for( i = 0; i < sz; i++ )
	{
		max_ending_here += ar[i];

		if( max_ending_here < 0 )
			max_ending_here = 0;
		if( max_so_far < max_ending_here )
			max_so_far = max_ending_here;
	}

	printf( "largest sum iterative: %i\n", max_ending_here );
	return;
}


/******************************************************************************
 *****************************************************************************/
void find_largest_r( int* ar, int sz )
{
	int sum = find_largest_r2( ar, sz, 0, sz-1 );

	printf( "largest sum recursive: %i\n", sum );
	return;
}


/******************************************************************************
 *****************************************************************************/
int find_largest_r2( int* ar, int sz, int start, int end )
{
	int i = 0;
	int max_here = 0;

	/*base cases*/
	if( end >= sz )
		return 0;
	if( start >= sz || start >= end )
		return 0;

	/*calculate the total*/
	for( i = start; i <= end; i++ )
		max_here += ar[i];

	/*recurse*/
	return max3(
			max_here,
			find_largest_r2( ar, sz, start+1, end ),
			find_largest_r2( ar, sz, start, end+1 ) );
}

