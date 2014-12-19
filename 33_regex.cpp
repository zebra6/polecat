#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void print_array( char* ar, int sz );
int match_r( char* c1, char* c2 );

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

	printf( "match: %i\n", match_r( str1, str2 ) );

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
int match_r( char* c1, char* c2 )
{
	/*
	 * - match any
	 . - match one
	 */

	/*we reached the end of the string, so finished*/
	if( *c1 == '\0' && *c2 == '\0' )
		return 1;

	/*failure case for string two terminates with str1 on a wildcard*/
	if( *c1 == '*' && *(c1+1) == '\0' && *c2 == '\0' )
		return 0;

	/*general continue case*/
	if( *c1 == '.' || *c1 == *c2 )
		return match_r( c1+1, c2+1 );

	/*continue case for wildcard - can go two ways here*/
	if( *c1 == '*' )
		return ( match_r( c1+1, c2 ) || match_r( c1, c2+1 ) );

	return 0;
}
