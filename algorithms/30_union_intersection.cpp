#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SZ 16
#define MAX 32

void print_array( int* ar, int sz );
void qsort_r( int* ar, int start, int end );
void swap( int* a, int* b );
void ar_union( int* ar, int* br, int asz, int bsz, int* result, int rsz );
void ar_intersect( int* ar, int* br, int asz, int bsz, int* result, int rsz );

int main( int argc, char** argv )
{
	srand( time( NULL ) );
	int i = 0;
	int asz = rand() % SZ;
	int bsz = rand() % SZ;
	int rsz = asz + bsz;
	int* ar = (int*)calloc( 1, sizeof(int) * asz );
	int* br = (int*)calloc( 1, sizeof(int) * bsz );
	int* result = (int*)calloc( 1, sizeof(int) * rsz );

	for( i = 0; i < asz; i ++ )
		ar[i] = rand() % MAX;
	for( i = 0; i < bsz; i ++ )
		br[i] = rand() % MAX;

	qsort_r( ar, 0, asz - 1 );
	qsort_r( br, 0, bsz - 1 );
	print_array( ar, asz );
	print_array( br, bsz );

	printf( "union: " );
	ar_union( ar, br, asz, bsz, result, rsz );
	print_array( result, rsz );

	for( i = 0; i < rsz; i ++ )
		result[i] = 0;

	printf( "intersection: " );
	ar_intersect( ar, br, asz, bsz, result, rsz );
	print_array( result, rsz );

	if( result ) free( result );
	if( br ) free( br );
	if( ar ) free( ar );
	return 0;
}

/******************************************************************************
 *****************************************************************************/
void print_array( int* ar, int sz )
{
	int i = 0;

	for( i = 0; i < sz; i ++ )
		printf( "%i ", ar[i] );
	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void qsort_r( int* ar, int start, int end )
{
	int l = start;
	int r = end;
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
		swap( ar+start, ar+l );
		l--;
	}
	else
	{
		l--;
		swap( ar+start, ar+l );
	}

	qsort_r( ar, start, l );
	qsort_r( ar, r, end );

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
void ar_union( int* ar, int* br, int asz, int bsz, int* result, int rsz )
{
	int i = 0;
	int j = 0;
	int k = 0;

	while( i < asz && j < bsz )
	{
		if( ar[i] < br[j] )
			result[k++] = ar[i++];
		else if( ar[i] > br[j] )
			result[k++] = br[j++];
		else
		{
			result[k++] = br[j++];
			i++;
		}
	}

	while( i < asz )
		result[k++] = ar[i++];
	while( j < bsz )
		result[k++] = ar[j++];

	return;
}


/******************************************************************************
 *****************************************************************************/
void ar_intersect( int* ar, int* br, int asz, int bsz, int* result, int rsz )
{
	int i = 0;
	int j = 0;
	int k = 0;

	while( i < asz && j < bsz )
	{
		if( ar[i] < br[j] )
			i++;
		else if( ar[i] > br[j] )
			j++;
		else
		{
			result[k++] = ar[i];
			i++;
			j++;
		}
	}

	return;
}
