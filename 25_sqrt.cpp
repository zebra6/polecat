/*
bablyonian square root implementation
 */

#include <stdlib.h>
#include <stdio.h>
#define EPSILON 0.000001

float sqrt_itr( float val );

int main( int argc, char** argv )
{
	float val = atof( argv[1] );
	
	printf( "square root %lf: %lf\n\n", val, sqrt_itr( val ) );

	return 0;
}


float sqrt_itr( float val )
{
	float upper = val;
	float lower = 1.0f;

	while( ( upper - lower ) > EPSILON )
	{
		upper = ( upper + lower ) / 2;
		lower = val / upper;
	}

	return upper;
}
