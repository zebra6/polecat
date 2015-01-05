/*
Question: Given an array of integers, determine the index where the sum of all the preceding values is equal to the sum of all the following values.  The value at this index should not be included in either sum.  The first balanced index should be returned in the event of the existence of many balanced indices.  -1 should be returned for any error, including the non-existence of such an index.

[0, 1, 0, 1, 0, 2 ]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SZ 16
#define MAX 2

int presum_eq_postsum_naive( int* ar, int sz );
int presum_eq_postsum_opt( int* ar, int sz );

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
		
		if( rand() % 2 )
			ar[i] *= -1;

		printf( "%i ", ar[i] );
	}

	printf( "\n" );
	presum_eq_postsum_naive( ar, SZ );
	printf( "\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int presum_eq_postsum_naive( int* ar, int sz )
{
	int j = 0;
	int mid = 0;
	int sum_left = 0;
	int sum_right = 0;

	for( mid = 0; mid < sz; mid++ )
	{
		/*reset the sums*/
		sum_left = 0;
		sum_right = 0;

		/*we can always use mid-1 since we will just bail on the loop*/
		for( j = 0; j < mid-1; j++ )
			sum_left += ar[j];
		for( j = mid+1; j < sz; j++ )
			sum_right += ar[j];

		/*we can return here if we only want the first location*/
		if( sum_left == sum_right )
			printf( "sum %i at mid = %i\n", sum_left, mid );
	}

	return -1;
}


/******************************************************************************
 *****************************************************************************/
int presum_eq_postsum_opt( int* ar, int sz )
{
	/*the optimal solution to this involves finding the remainders and checking
	 * for existing values in a hashmap.  This should run in o(n) time, but i
	 * have not been able to discover how to do it yet*/

	return -1;
}
