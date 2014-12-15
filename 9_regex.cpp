#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
   In Java: Write a function in language of your choice that takes in two strings,
   and returns true if they match. Constraints are as follows: String 1, the text
   to match to, will be alphabets and digits. String 2, the pattern, will be
   alphabets, digits, '.' and '*'. '.' means either alphabet or digit will be
   considered as a "match". "*" means the previous character is repeat 0 or more #
   of times. For example: Text: Facebook Pattern: F.cebo*k returns true.
 */

int string_match( char* n, char* h );
int string_match_r( char* n, char *h );

int main( int argc, char** argv )
{
	char* n = argv[1];
	char* h = argv[2];

	assert( argc == 3 );

	printf( "needle: %s\n", n );
	printf( "haystack: %s\n", h );

	printf( "match: %i\n", string_match( n, h ) );

	return 0;
}


int string_match( char* n, char* h )
{
	int len_n = strlen( n );
	int len_h = strlen( h );

	if( len_n > len_h )
		return -1;
	
	return string_match_r( n, h );
}

/* . = single, * = multiple */

int string_match_r( char* n, char *h )
{
	/*base case*/
	if( *n == '\0' && *h == '\0' )
		return true;

	/*single character match*/
	if( *n == *h || *n == '.' )
		return string_match_r( n + 1, h + 1 );

	/*multiple character match*/
	if( *n == '*' )
		return(
				string_match_r( n + 1, h ) ||
				string_match_r( n, h + 1 ) );

	/*default failure path*/
	return false;
}

