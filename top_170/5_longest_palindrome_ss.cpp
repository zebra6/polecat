/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;

void check_longest_palindrome( char* in );
int is_palindrome( char* str, int start, int end );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	char* in = argv[1];

	check_longest_palindrome( in );

	printf( "\n" );
}


/******************************************************************************
 *****************************************************************************/
void check_longest_palindrome( char* in )
{
	int i = 0;
	int j = 0;
	char* pal = (char*)calloc( 1, strlen(in) + 1 );

	for( i = 0; i < strlen( in ); i++ )
		for( j = strlen( in ) - 1; j > i; j-- )
			if( is_palindrome( in, i, j ) )
			{
				/*need +1 here, i.e. 7-0 = 7*/
				memcpy( pal, in+i, j-i+1 );
				goto out;
			}

out:
	if( pal[0] )
		printf( "longest found: %s\n", pal );
	else
		printf( "none found\n" );

	if( pal ) free( pal );
	return;
}


/******************************************************************************
 *****************************************************************************/
int is_palindrome( char* str, int start, int end )
{
	int retv = 1;

	for( ; start < end; start++, end-- )
		if( str[start] != str[end] )
		{
			retv = 0;
			goto out;
		}

out:
	return retv;
}

