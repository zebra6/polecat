/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SZ 16

void three_sum( int* ar, int sz );
void qsrt_r( int* ar, int start, int end );
void swap( int* a, int* b );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int ar[SZ] = { 0 };

	srand(time(NULL));

	for( i = 0; i < SZ; i++ )
	{
		ar[i] = rand() % 10;
		if( rand() % 2 )
			ar[i] *= -1;
	}

	qsrt_r( ar, 0, SZ-1 );

	printf( "array: " );
	for( i = 0; i < SZ; i ++ )
		printf( "%i ", ar[i] );
	printf( "\n" );

	three_sum( ar, SZ );

	return 0;
}



/******************************************************************************
 *****************************************************************************/
void three_sum( int* ar, int sz )
{
	int i = 0;
	int l = 0;
	int target = 0;
	int r = sz-1;

	for( i = 0; i < ( sz - 3 ); i++ )
	{
		target = ar[i] * -1;
		l = i+1;
		r = sz-1;

		while( l < r )
		{
			if( ar[l] + ar[r] < target )
				l++;
			else if( ar[l] + ar[r] > target )
				r--;
			else
			{
				printf( "%i+%i=%i\n", ar[l], ar[r], target );
				l++;
				r--;
			}
		}
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void qsrt_r( int* ar, int start, int end )
{
	int l = start;
	int r = end;
	int p = ar[l];

	/*base case*/
	if( l >= r )
		return;

	/*partition and sort*/
	while( l < r )
	{
		if( ar[l] <= p )
			l++;
		else if( ar[r] >= p )
			r--;
		else
			swap( &ar[l], &ar[r] );
	}
	if( ar[l] < p )
	{
		swap( &ar[l], &ar[start] );
		l--;
	}
	else
	{
		l--;
		swap( &ar[l], &ar[start] );
	}

	/*recurse*/
	qsrt_r( ar, start, l );
	qsrt_r( ar, r, end );

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
