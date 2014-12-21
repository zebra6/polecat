/*
quicksort for arrays and strings
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 16

void quicksort( int* ar, int sz );
void quicksort_r( int* ar, int start, int end );
void swap( int* a, int* b );

int main( int argc, char** argv )
{
	int i = 0;
	int ar[MAX] = { 0 };
	char br[] = "The quick brown fox jumped over the lazy dog.";
	char len = strlen( br );

	srand(time(NULL));

	printf( "int array before: " );

	for( i = 0; i < MAX; i ++ )
	{
		ar[i] = rand() % 32;
		printf( "%i ", ar[i] );
	}

	quicksort( ar, MAX );

	printf( "\nint array after: " );
	for( i = 0; i < MAX; i ++ )
		printf( "%i ", ar[i] );

	/*printf( "\n\nchar array before: " );
	for( i = 0; i < len; i ++ )
		printf( "%c", br[i] );*/

	/*this doesn't work due to pointer sizing
	quicksort( (int*)br, len );*/

	/*printf( "\nchar array after: " );
	for( i = 0; i < len; i ++ )
		printf( "%c", br[i] );*/

	printf( "\n\n" );

	return 0;
}


void quicksort( int* ar, int sz )
{
	quicksort_r( ar, 0, sz - 1 );
	return;
}


void quicksort_r( int* ar, int start, int end )
{
	int l = start;
	int r = end;
	int m = ( start + end ) / 2;
	int p = ar[start];

	if( start >= end )
		return;

	while( l < r )
	{
		if( ar[l] <= p )
			l++;
		else if( ar[r] >= p )
			r--;
		else
			swap( ar+l, ar+r );
	}

	if( ar[l] < p )
	{
		swap( ar+l, ar+start );
		l--;
	}
	else
	{
		l--;
		swap( ar+l, ar+start );
	}
	quicksort_r( ar, start, l );
	quicksort_r( ar, r, end );

	return;
}


void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
