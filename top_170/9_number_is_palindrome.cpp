/*
Determine whether an integer is a palindrome. Do this without extra space.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_palindrome( int num );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int val = atoi( argv[1] );
	printf( "is palindrome: %i\n", is_palindrome( val ) );
	printf( "\n" );
}


/******************************************************************************
 *****************************************************************************/
int is_palindrome( int num )
{
	int retv = 0;
	int num2 = num;
	int tmp = 0;

	/*this uses extra space in the form of another int, but does not do so using
	 * a string, i do not believe this is possible without at least temporary
	 * ints*/

	/*negative numbers are not palindromes*/
	if( num < 0 )
		return retv;

	while( num )
	{
		/*shift*/
		tmp *= 10;
		
		/*get the digit*/
		tmp += num % 10;

		/*reduce num*/
		num /= 10;
	}

	if( num2 == tmp )
		retv = 1;

	return retv;
}
