#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

void print_array( char* ar, int sz );
int edit_dist_r( char* str1, char* str2, int off1, int off2 );
int edit_dist_i( char* str1, char* str2, int len_1, int len_2 );
int edit_dist_i2( char* str1, char* str2, int len_1, int len_2 );
int indel_cost( char a, char b );
int min3( int a, int b, int c );


/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	char* str1 = argv[1];
	char* str2 = argv[2];
	int len_1 = strlen( str1 );
	int len_2 = strlen( str2 );
	assert( argc == 3 );

	printf( "strings:\n" );
	print_array( str1, len_1 );
	print_array( str2, len_2 );
	printf( "\n" );
	printf( "cost: %i\n", edit_dist_r( str1, str2, 0, 0 ) );
	printf( "cost: %i\n", edit_dist_i( str1, str2, len_1, len_2 ) );
	printf( "cost: %i\n", edit_dist_i2( str1, str2, len_1, len_2 ) );

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
int indel_cost( char a, char b )
{
	if( a == b ) 
		return 0;

	return 1;
}


/******************************************************************************
 *****************************************************************************/
int min3( int a, int b, int c )
{
	if( a < b )
		return ( a < c ) ? a : c;
	else
		return ( b < c ) ? b : c;
}


/******************************************************************************
 *****************************************************************************/
int edit_dist_r( char* str1, char* str2, int off1, int off2 )
{
	int c_left = 0;
	int c_right = 0;
	int c_diag = 0;

	if( str1[off1] == '\0' && str2[off2] == '\0' )
		return 0;
	if( str1[off1] == '\0' )
		return strlen(str2) - off2;
	if( str2[off2] == '\0' )
		return strlen(str1) - off1;

	c_left = edit_dist_r( str1, str2, off1+1, off2 )
		+ 1;

	c_right = edit_dist_r( str1, str2, off1, off2+1 )
		+ 1;

	c_diag = edit_dist_r( str1, str2, off1+1, off2+1 )
		+ ( str1[off1+1] != str2[off2+1] );

	return min3( c_left, c_right, c_diag );
}


/******************************************************************************
 *****************************************************************************/
int edit_dist_i( char* str1, char* str2, int len_1, int len_2 )
{
	int i = 0;
	int j = 0;
	int y = len_1 + 1;
	int x = len_2 + 1;
	int retv = 0;
	int lut[32][32] = { { 0 } };
	//int* lut = (int*)calloc( 1, sizeof(int) * y * x );

	/*build the table - first rows*/
	for( i = 0; i < y; i ++ )
		lut[0][i] = i;
	for( j = 0; j < x; j ++ )
		lut[j][0] = j;

	for( i = 1; i < y; i ++ )
	{
		for( j = 1; j < x; j ++ )
		{
			/*no change*/
			if( str1[i] == str2[j] )
				lut[i][j] = lut[i-1][j-1];

			/*otherwise get the minimum from the values*/
			else
				lut[i][j] += min3(
						( lut[i-1][j] ) + 1,		//insert		
						( lut[i][j-1] ) + 1,		//delete
						( lut[i-1][j-1] ) + 1 );	//substitution
		}
	}

/*	for( i = 0; i < y; i ++ )
	{
		for( j = 0; j < x; j ++ )
			printf( "%2i ", lut[i][j] );

		printf( "\n" );
	}
*/
	retv = lut[len_1][len_2];
	return retv;	
}


int edit_dist_i2( char* str1, char* str2, int len_1, int len_2 )
{
	int i = 0;
	int j = 0;
	int max = ( ( len_1 > len_2 ) ? len_1 : len_2 ) + 1;
	int retv = 0;
	int lut[32][32] = { { 0 } };

	/*build the table - first rows*/
	for( i = 0; i < max; i ++ )
		lut[0][i] = i;
	for( j = 0; j < max; j ++ )
		lut[j][0] = j;

	for( i = 1; i < max; i ++ )
	{
		for( j = 1; j < max; j ++ )
		{
			/*no change*/
			if( str1[i] == str2[j] )
				lut[i][j] = lut[i-1][j-1];

			/*otherwise get the minimum from the values*/
			else
				lut[i][j] += min3(
						( lut[i-1][j] ) + 1,		//insert		
						( lut[i][j-1] ) + 1,		//delete
						( lut[i-1][j-1] ) + 1 );	//substitution
		}
	}

	retv = lut[len_1][len_2];
	return retv;	
}
