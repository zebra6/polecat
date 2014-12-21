/*
o(n) and o(log n) pow() implementations
 */

#include <stdlib.h>
#include <stdio.h>

long pow_itr( int x, int y );
float pow_rec( float x, int y );

int main( int argc, char** argv )
{
	int x_i = atoi( argv[1] );
	float x_f = atof( argv[1] );
	int y_i = atoi( argv[2] );

	printf( "%i^%i, iterative: %li\n", x_i, y_i, pow_itr( x_i, y_i ) );
	printf( "%lf^%i, recursive: %lf\n\n", x_f, y_i, pow_rec( x_f, y_i ) );

	return 0;
}


long pow_itr( int x, int y )
{
	long result = 1;

	while( y-- )
		result *= x;
	
	return result;
}


float pow_rec( float x, int y )
{
	float tmp = 1.0f;

	/*base case*/
	if( y == 0 )
		return 1;

	tmp = pow_rec( x, y/2 );

	/*this uses exponentiation by squaring to complete*/
	if( y % 2 == 0 )
		return tmp * tmp;
	else
	{
		if( y > 0 )
			return tmp * tmp * x;
		else
			return ( tmp * tmp ) / x;
	}
}

