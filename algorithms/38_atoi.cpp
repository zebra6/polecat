/*
   implementation of atoi
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_num( char x );
int atoi1( char* str );
int atoi2( char* str );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	char* in = argv[1];

	printf( "a1: %i\na2: %i\n", atoi1( in ), atoi2( in ) );
	printf( "\n\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int atoi1( char* str )
{
	int i = 0;
	int j = strlen(str) - 1;
	int retv = 0;
	char tmp = '0';

	/*reverse the string*/
	for( ; i < j; i++, j-- )
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}

	/*use i as an accumulator*/
	for( i = 0; i < strlen(str); i++ )
	{
		if( str[i] >= '0' && str[i] <= '9' )
		{
			/*found a digit*/
			tmp = str[i] - '0';
			retv += tmp * pow( 10, i );
		}
		else if( str[i] == '-' )
		{
			/*negative sign*/
			retv *= -1;
			break;
		}
		else
			/*non-digit*/
			break;
	}

	return retv;	
}


/******************************************************************************
 *****************************************************************************/
int is_num(char x)
{
	return ( x >= '0' && x <= '9' ) ? true : false;
}


/******************************************************************************
 *****************************************************************************/
int atoi2( char *str )
{ 
	int i = 0;
	int retv = 0;
	int sign = 1;

	if ( !str ) return 0;

	/*check for negative sign*/
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	/*iterate through the string*/
	for( ; str[i] != '\0'; i++ )
	{
		/*check for errors*/
		if( !is_num( str[i] ) ) return 0;

		/*retv is raised to the nth power of 10 as we iterate*/
		retv = ( retv * 10 ) + ( str[i] - '0' );
	}

	return retv * sign;
}

