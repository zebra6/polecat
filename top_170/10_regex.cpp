/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int matches( char* a, char * b );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	char* a = argv[1];
	char* b = argv[2];

	printf( "input a: %s\ninputb: %s\n", a, b );
	printf( "matches: %i\n\n", matches( a, b ) );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int matches( char* a, char * b )
{
	/*base case, both are end of string*/
	if( *a == '\0' && *b == '\0' )
		return true;

	/*single character or wildcard match*/
	if( *a == *b || *a == '.' )
		return matches( a+1, b+1 );

	/*multiple wildcard match*/
	if( *a == '*' )
		return
			matches( a+1, b ) ||
			matches( a, b+1 );

	/*case where we have end of string on b and characters remaining on a*/
	return false;
}
