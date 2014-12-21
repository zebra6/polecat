#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#define XSZ 2
#define YSZ 4
#define MAX 2

void print_array( char* ar, int sz );
void print_array2d( int ar[YSZ][XSZ], int xsz, int ysz );
int find_max_r( int ar[YSZ][XSZ], int xsz, int ysz, int xoff, int yoff );
int find_max_i(
		int ar[YSZ][XSZ],
		int lut[YSZ][XSZ],
		int xsz,
		int ysz,
		int xoff,
		int yoff );
int max( int a, int b );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int j = 0;
	int ar[YSZ][XSZ] = { { 0 } };
	int lut[YSZ][XSZ] = { { 0 } };
	
	srand(time(NULL));

	for( i = 0; i < YSZ; i++ )
		for( j = 0; j < XSZ; j++ )
			ar[i][j] = rand() % MAX + 1;


	print_array2d( ar, XSZ, YSZ );
	printf( "max recursive: %i\n", find_max_r( ar, XSZ, YSZ, 0, 0 ) );
	

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void print_array( char* ar, int sz )
{
	int i = 0;

	for( i = 0; i < sz; i ++ )
		printf( "%2c", ar[i] );
	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void print_array2d( int ar[YSZ][XSZ], int xsz, int ysz )
{
	int i = 0;
	int j = 0;

	for( i = 0; i < ysz; i++ )
	{
		for( j = 0; j < xsz; j ++ )
			printf( "%3i", ar[i][j] );

		printf( "\n" );
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
int max( int a, int b )
{
	return ( a > b ) ? a : b;
}


/******************************************************************************
 *****************************************************************************/
int find_max_r( int ar[YSZ][XSZ], int xsz, int ysz, int xoff, int yoff )
{
	if( xoff >= xsz || yoff >= ysz )
		return 0;

	return ar[yoff][xoff] + max( find_max_r( ar, xsz, ysz, xoff+1, yoff ),
			find_max_r( ar, xsz, ysz, xoff, yoff+1 ) );
}


/******************************************************************************
 *****************************************************************************/
int find_max_i(
		int ar[YSZ][XSZ],
		int lut[YSZ][XSZ],
		int xsz,
		int ysz,
		int xoff,
		int yoff )
{
	if( xoff >= xsz || yoff >= ysz )
		return 0;


	/*similar to edit distance problem*/

	return ar[yoff][xoff] + max( find_max_r( ar, xsz, ysz, xoff+1, yoff ),
			find_max_r( ar, xsz, ysz, xoff, yoff+1 ) );
}
