/*
Implement atoi to convert a string to an integer.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>

using std::string;

int atoi( string in );
int atoi2( string in );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	string in = argv[1];
	printf( "atoi: %i\n", atoi( in ) );
	printf( "atoi2: %i\n", atoi2( in ) );

	printf( "\n" );
}


/******************************************************************************
 *****************************************************************************/
int atoi( string in )
{
	int i = 0;
	int retv = 0;
	int sign = 1;

	if( in[0] == '-' )
	{
		sign = -1;
		i = 1;
	}

	for( ; i < in.length(); i++ )
	{
		/*check for valid input*/
		if( in[i] < '0' || in[i] > '9' )
		{
			retv = 0;
			break;
		}

		/*could check for overflow here using a tmp variable*/

		/*shift and add the input*/
		retv *= 10;
		retv += ( in[i] - '0' );
	}

	/*adjust for sign*/
	retv *= sign;

	return retv;
}


/******************************************************************************
 *****************************************************************************/
int atoi2( string in )
{
	int i = 0;
	int retv = 0;
	int tmp = 0;
	int sign = 1;

	/*check for negative sign*/
	if( in[0] == '-' )
	{
		sign = -1;
		i++;
	}

	while( i < in.length() )
	{
		/*check for valid input*/
		if( in[i] < '0' || in[i] > '9' )
			return 0;

		/*store current value*/
		tmp = retv;

		/*shift and check for overflow*/
		retv *= 10;
		if( retv < tmp )
			return 0;

		/*add the number*/
		retv += ( in[i] - '0' );

		i++;
	}

	/*keep track of sign and return*/
	retv *= sign;
	return retv;
}
