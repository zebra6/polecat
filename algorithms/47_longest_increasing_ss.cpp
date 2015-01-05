/*
   find the longest increasing subsequence in an array.  note this reduces to
   finding the longest path in a directed acyclic graph
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SZ 16
#define MAX 10

void lis( int* ar, int sz );
int lis_r( int* ar, int sz, int* max_ref );
void lis2( int* ar, int sz );
void lis2_r( int* ar, int sz, int start, int end, int* max );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int ar[SZ] = { 0 };
	srand(time(NULL));

	printf( "array: " );

	for( i = 0; i < SZ; i++ )
	{
		ar[i] = rand() % MAX;
		printf( "%i ", ar[i] );
	}

	printf( "\n" );
	lis( ar, SZ );
	lis2( ar, SZ );
	printf( "\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void lis( int* ar, int sz )
{
	int max = 1;
	lis_r( ar, sz, &max );
	printf( "longest increasing subsequence: %i\n", max );	

	return;
}


/******************************************************************************
 *****************************************************************************/
int lis_r( int* ar, int sz, int* max_ref )
{
	int i = 0;
	int retv = 0;
	int max_ending_here = 0;

	/*base case for recursion*/
	if( sz == 1 )
		return 1;

	for( i = 1; i < sz; i++ )
	{
		/*recurse through*/
		retv = lis_r( ar, i, max_ref );

		if( ar[i-1] < ar[sz-1] && retv + 1 > max_ending_here )
			max_ending_here = retv + 1;
	}

	/*compare with overall max and update as needed*/
	if( max_ending_here > *max_ref )
		*max_ref = max_ending_here;

	/*return max of LIS in ar[0]..ar[sz-1]*/
	return max_ending_here;
}



/******************************************************************************
 *****************************************************************************/
void lis2( int* ar, int sz )
{
	int max = 1;
	int start = 0;
	int end = 0;
	lis2_r( ar, sz, start, end, &max );
	printf( "longest increasing subsequence: %i\n", max );	

	return;
}


/******************************************************************************
 *****************************************************************************/
void lis2_r( int* ar, int sz, int start, int end, int* max )
{
	int i = 0;

	/*base case*/
	if( start > end || end >= sz )
		return;

	for( i = start; i < end-1; i++ )
	{
		/*non-increasing*/
		if( ar[i] > ar[i+1] )
			return;
	}

	/*update if greater max found*/
	if( end - start > *max )
		*max = ( end - start );

	/*recurse*/
	lis2_r( ar, sz, start+1, end, max );
	lis2_r( ar, sz, start, end+1, max );

	return;
}
