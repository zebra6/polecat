/*
   find the longest subarray that sums to a given value
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SZ 16
#define MAX 8

struct offsets_t
{
	offsets_t( void ) { s_start = -1; s_end = -1; };
	int s_start;
	int s_end;
};

void find_longest( int* ar, int sz, int val, offsets_t* off );
void print_array( int* ar, int start, int end );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int ar[SZ] = { 0 };
	offsets_t off;

	srand(time(NULL));

	for( i = 0; i < SZ; i ++ )
		ar[i] = rand() % MAX;

	print_array( ar, 0, SZ-1 );
	find_longest( ar, SZ, rand() % SZ, &off );
	print_array( ar, off.s_start, off.s_end );

	printf( "\n\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void find_longest( int* ar, int sz, int val, offsets_t* off )
{
	int i = 0;
	int start = 0;
	int c_sum = 0;

	printf( "longest subarray sums to %i:\n", val );

	for( i = 0; i < sz; i ++ )
	{
		/*if the sum is too large, start removing leading elements*/
		while( c_sum > val && start < i )
			c_sum -= ar[start++];

		/*found a match*/
		if( c_sum == val )
		{
			if( off->s_end - off->s_start < i - start )
			{
				off->s_start = start;
				off->s_end = i;
				printf( "updated %i, %i\n", start, i );
			}
		}

		/*update our running sum*/
		c_sum += ar[i];
	}

	printf( "longest found: %i, %i\n", off->s_start, off->s_end );

	return;
}


/******************************************************************************
 *****************************************************************************/
void print_array( int* ar, int start, int end )
{
	int i = 0;

	if( start >= end || start < 0 || end < 0 )
		return;

	for( i = start; i < end; i++ )
		printf( "%3i", i );
	printf( "\n" );
	for( i = start; i < end; i++ )
		printf( "%3i", ar[i] );

	printf( "\n" );

	return;
}

