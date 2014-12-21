/*
merge sort for arrays on ints
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 16

void msort( int* ar, int sz );
void msort_r( int* ar, int start, int end );
void swap( int* a, int* b );

int main( int argc, char** argv )
{
	int i = 0;
	int ar[MAX] = { 0 };

	srand(time(NULL));

	printf( "int array before: " );

	for( i = 0; i < MAX; i ++ )
	{
		ar[i] = rand() % 32;
		printf( "%i ", ar[i] );
	}

	msort( ar, MAX );

	printf( "\nint array after: " );
	for( i = 0; i < MAX; i ++ )
		printf( "%i ", ar[i] );

	printf( "\n\n" );

	return 0;
}


void msort( int* ar, int sz )
{
	int i = 0;
	int tmp[sz];

	for( i = 0; i < sz; tmp[i++] = 0 );

	msort_r( ar, tmp, 0, sz - 1 );

	return;
}


void msort_r( int* ar, int* br, int start, int end )
{
	int l = start;
	int mid = ( start + end ) / 2;
	int r = mid;

	if( start > end )
		return;

	msort_r( ar, br, start, mid );
	msort_r( ar, bt, mid + 1, end );

	for( i = start; i < end; i ++ )
	{
		if( r >= end || ( l < mid && ar[l] < ar[r] ) )
			tmp[i] = ar[l++];
		else
			tmp[i] = ar[r++];
	}

	for( i = start; i < end; i ++ )
		ar[i] = tmp[i];

	return;
}


void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
