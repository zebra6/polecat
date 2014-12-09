
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

short is_letter( char val );
void check_palindrome( char* str );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	check_palindrome( "A man, a plan, a canal -- Panama!" );
	return 0;
}


/******************************************************************************
 *****************************************************************************/
void check_palindrome( char* str )
{
	int retv = 1;
	int start = 0;
	int end = strlen( str ) - 1;

	while( start < end )
	{
		if( !is_letter( str[start] ) )
			start++;
		else if( !is_letter( str[end] ) )
			end--;
		else if( str[start] == str[end] || abs( str[start] - str[end] )
				== 'A' - 'a' )
		{
			start++;
			end--;
		}
		else
		{
			retv = 0;
			goto out;
		}
	}

out:
	if( retv )
		printf( "is palindrome\n" );
	else
		printf( "is not palindrome\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
short is_letter( char val )
{
	if( ( val >= 'a' && val <= 'z' ) || ( val >= 'A' && val <= 'Z' ) )
		return true;

	return false;
}

