/*"Write a program that prints the numbers from 1 to 100. But for multiples of
three print “Fizz” instead of the number and for the multiples of five print
“Buzz”. For numbers which are multiples of both three and five print
“FizzBuzz”."*/

#include <stdio.h>

int main( int argc, char** argv )
{
	int i	= 0;

	for( i = 1; i < 101; i ++ )
	{
		if( !(i % 15) || !(i % 5) || !(i % 3) )
		{
			if( !( i % 5 ) && !( i % 3 ) )
				printf( "%i: fizzbuzz\n", i );
			if( !(i % 5) )
				printf( "%i: buzz\n", i );
			if( !(i % 3) )
				printf( "%i: fizz\n", i );
		}
		else
			printf( "%i:\n", i );
	}

	return 0;
}
