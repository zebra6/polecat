/*
bablyonian square root implementation
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ASZ 16

void rotate( int* ar, int sz, int pos );
void reverse( int* ar, int start, int end );
void print_array( int* ar, int sz );
int find_pivot_r( int* ar, int start, int end );
int find_val_r( int* ar, int start, int end, int val );

int main( int argc, char** argv )
{
	int i = 0;
	int ar[ASZ] = { 0 };
	int val = rand() % ASZ;

	srand(time(NULL));

	for( i = 0; i < ASZ; i ++ )
		ar[i] = i;

	print_array( ar, ASZ );
	rotate( ar, ASZ, rand() % 16 );
	print_array( ar, ASZ );
	printf( "pivot: %i\n", find_pivot_r( ar, 0, ASZ - 1 ) );
	printf( "val %i: %i\n", val, find_val_r( ar, 0, ASZ - 1, val ) );

	printf( "\n" );
	return 0;
}


void rotate( int* ar, int sz, int pos )
{
	reverse( ar, 0, pos-1 );
	reverse( ar, pos, sz-1 );
	reverse( ar, 0, sz-1 );
	return;
}


void reverse( int* ar, int start, int end )
{
	int tmp = 0;

	for( ; start < end; start++, end-- )
	{
		tmp = ar[start];
		ar[start] = ar[end];
		ar[end] = tmp;
	}

	return;
}


void print_array( int* ar, int sz )
{
	int i = 0;

	printf( "array: " );
	for( i = 0; i < sz; i ++ )
		printf( "%2i ", ar[i] );

	printf( "\n" );
	return;
}


int find_pivot_r( int* ar, int start, int end )
{
	int mid = ( start + end ) / 2;

	/*base cases*/
	if( start > end )
		return -1;
	if( start == end )
		return start;

	/*check for a match*/
	if( mid > start && ar[mid] < ar[mid-1] )
		return mid;
	if( mid < end && ar[mid] > ar[mid+1] )
		return mid+1;
	
	/*recurse*/
	if( ar[start] > ar[mid] )
		return find_pivot_r( ar, start, mid );
	else
		return find_pivot_r( ar, mid + 1, end );

	/*all else fails*/
	return -1;
}


int find_val_r( int* ar, int start, int end, int val )
{
	int mid = ( start + end ) / 2;
	/*base cases*/
	if( start == end )
		return start;
	if( start > end )
		return -1;

	/*compare*/
	if( ar[mid] == val )
		return mid;

	/*otherwise recurse*/
	if( ar[start] < ar[mid] )
	{
		/*left half is sorted - use the above information to let us know which
		 * half to compare*/
		if( ar[start] <= val && ar[mid] >= val )
			return find_val_r( ar, start, mid-1, val );
		else
			return find_val_r( ar, mid+1, end, val );
	}
	else
	{
		/*right half is sorted*/
		if( ar[mid] <= val && ar[end] >= val )
			return find_val_r( ar, mid+1, end, val );
		else
			return find_val_r( ar, start, mid-1, val );
	}

	/*fallthrough case*/
	return -1;
}
