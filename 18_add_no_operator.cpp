/*
do addition with no operator
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 128


int main( int argc, char** argv )
{
	srand(time(NULL));
	int a = rand() % MAX;
	int b = rand() % MAX;
	int c = 0;

	printf( "a: %6i\nb: %6i\n", a, b );
	while( b )
	{
		/*carry stores all the bits set in a and b*/
		c = a & b;

		/*a xor b calculates the sum and stores it back in a*/
		a ^= b;
		
		/*shift the carry field to the left one so they are aligned with the
		 * correct bits*/
		b = c << 1;
	}

	printf( "s: %6i\n", a );
	printf( "\n\n" );

	return 0;
}


