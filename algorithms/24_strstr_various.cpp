/*
   merge sort for arrays on ints
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int strstr_naive( char* n, char* h );
int strstr_kmp( char* n, char* h );
void precalc_kmp( char* n, int n_len, int* lookup_table );

int main( int argc, char** argv )
{
	char* haystack = argv[2];
	char* needle = argv[1];

	assert( argc == 3 );

	printf( "needle: %s\nhaystack: %s\n\n", needle, haystack );
	printf( "strstr naive: %i\n", strstr_naive( needle, haystack ) );
	printf( "strstr kmp: %i\n", strstr_kmp( needle, haystack ) );

	return 0;
}


int strstr_naive( char* n, char* h )
{
	int n_len = strlen( n );
	int h_len = strlen( h );
	int retv = -1;
	int n_off = 0;
	int h_off = 0;

	for( h_off = 0; h_off <= ( h_len - n_len ); h_off ++ )
	{
		for( n_off = 0; n_off < n_len; n_off ++ )
		{
			if( h[h_off+n_off] != n[n_off] )
				break;
		}
		if( n_off == n_len )
		{
			retv = h_off;
			return retv;
		}
	}

	return retv;
}


int strstr_kmp( char* n, char* h )
{
	int n_len = strlen( n );
	int h_len = strlen( h );
	int n_off = 0;
	int h_off = 0;
	int* lut = NULL;

	/*first check the lengths*/
	if( n_len > h_len )
	{
		printf( "needle too long\n" );
		return -1;
	}

	/*set up the lookup table and calculate it*/
	lut = (int*)calloc( 1, sizeof(int) * n_len );
	precalc_kmp( n, n_len, lut );

	/*start checking*/
	while( h_off < h_len )
	{
		if( n[n_off] == h[h_off] )
		{
			/*found a match*/
			n_off++;
			h_off++;
		}
		if( n_off == n_len )
		{
			/*found the end of the string*/
			printf( "found match at offset %i\n", h_off - n_off );
			if( lut ) free( lut );
			return h_off - n_off;
		}
		else if( n[n_off] != h[h_off] && h_off < h_len )
		{
			/*no match*/
			if( n_off != 0 )
			{
				/*see how far back into n we need to look*/
				n_off = lut[n_off-1];
			}
			else
			{
				/*needle offset is already zero so just move index*/
				h_off++;
			}
		}
	}

	if( lut )
		free( lut );

	return -1;
}


void precalc_kmp( char* n, int n_len, int* lookup_table )
{
	int i = 0;
	int suffix_len = 0;

	/*the first offset is always zero*/
	lookup_table[i++] = 0;

	while( i < n_len )
	{
		/*there was a match*/
		if( n[i] == n[suffix_len] )
		{
			/*calculate the longest running suffix*/
			suffix_len++;
			lookup_table[i] = suffix_len;
			i++;
		}
		else
		{
			/*there was no match*/
			if( suffix_len != 0 )
			{
				/*this keeps us from running off the end of the array*/
				suffix_len = lookup_table[suffix_len-1];
			}
			else
			{
				/*otherwise reset*/
				lookup_table[i++] = 0;
			}
		}
	}

	return;
}



void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
