/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int reverse_int( int val );
int reverse_int2( int val );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int val = atoi( argv[1] );
	printf( "reversed: %i\n", reverse_int( val ) );
	printf( "reversed2: %i\n", reverse_int2( val ) );
	printf( "\n" );
}


/******************************************************************************
 *****************************************************************************/
int reverse_int( int val )
{
	int i = 0;
	int j = 0;
	int sign = 1;
	int retv = val;
	char tmp[32] = { '\0' };
	char tmp2 = '\0';

	
	/*keep track of the sign*/
	if( val < 0 )
	{
		sign = -1;
		val *= -1;
	}

	/*print to a character buffer*/
	sprintf( tmp, "%i", val );
	for( i = 0, j = strlen(tmp) - 1; i < j; i++, j-- )
	{
		tmp2 = tmp[i];
		tmp[i] = tmp[j];
		tmp[j] = tmp2;
	}

	/*check overflow - probably better to use math instead for this*/

	/*restore the sign*/
	retv = atoi( tmp );
	retv *= sign;
	return retv;
}


/******************************************************************************
 *****************************************************************************/
int reverse_int2( int val )
{
	int i = 0;
	int retv = 0;
	int sign = 1;

	/*keep track of the sign*/
	if( val < 0 )
	{
		sign = -1;
		val *= -1;
	}

	/*could check for overflow here with a temp value*/
	while( val )
	{
		retv = ( retv * 10 ) + val % 10;
		val /= 10;
	}

	retv *= sign;
	return retv;
}


