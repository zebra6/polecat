/*
   merge sort for arrays on ints
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int strstr_naive( char* n, char* h );
int strstr_bm( char* n, char* h );

int main( int argc, char** argv )
{
	char* haystack = argv[1];
	char* needle = argv[2];

	assert( argc == 3 );

	printf( "needle: %s\nhaystack: %s\n\n", needle, haystack );
	printf( "strstr naive: %i\n", strstr_naive( needle, haystack ) );
	printf( "strstr boyer-moore: %i\n", strstr_bm( needle, haystack ) );

	return 0;
}


int strstr_naive( char* n, char* h )
{
	int i = 0;
	int j = 0;
	int n_len = strlen( n );
	int h_len = strlen( h );

	/*if needle is too long*/
	if( n_len > h_len )
		return 0;

	/*if they are equal length*/
	else if( n_len == h_len )
	{
		for( i = 0; i < n_len; i ++ )
			if( n[i] != h[i] )
				return 0;

		return 1;
	}

	/*standard search*/
	for( i = 0; i < ( h_len - n_len ); i ++ )
	{
		for( j = 0; n[j] == h[i+j]; j ++ );
	
		if( j == n_len )
			return 1;
	}

	return 0;
}


int strstr_bm( char* n, char* h )
{
	int i = 0;
	int j = 0;
	int n_len = strlen( n );
	int h_len = strlen( h );

	/*if needle is too long*/
	if( n_len > h_len )
		return 0;

	/*if they are equal length*/
	else if( n_len == h_len )
	{
		for( i = 0; i < n_len; i ++ )
			if( n[i] != h[i] )
				return 0;

		return 1;
	}

	/*standard search*/
	for( i = 0; i < ( h_len - n_len ); i ++ )
	{
		for( j = 0; n[j] == h[i+j]; j ++ );
	
		if( j == n_len )
			return 1;
	}

	return 0;
}



void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
