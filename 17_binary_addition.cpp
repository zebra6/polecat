/*
You have two numbers decomposed in binary representation, write a
function that sums them and returns the result.

Input: 100011, 100100
Output: 1000111
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4

void swap( int* a, int* b );
void add( int* a, int* b, int* s, int sz );

int main( int argc, char** argv )
{
	int i = 0;
	int ar1[MAX] = { 0 };
	int ar2[MAX] = { 0 };
	int result[MAX+1] = { 0 };

	srand(time(NULL));

	for( i = 0; i < MAX; i ++ )
	{
		ar1[i] = rand() % 2;
		ar2[i] = rand() % 2; 
	}

	/*note these bit patters will be backwards, reverse the array for correct
	 * order*/

	printf( "inputs:\n" );
	for( i = 0; i < MAX; i ++ )
		printf( "%i", ar1[i] );
	printf( "\n" );
	for( i = 0; i < MAX; i ++ )
		printf( "%i", ar2[i] );
	printf( "\n" );

	add( ar1, ar2, result, MAX );

	for( i = 0; i < MAX+1; i ++ )
		printf( "%i", result[i] );

	printf( "\n\n" );

	return 0;
}


void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}


void add( int* a, int* b, int* s, int sz )
{
	int i = 0;
	int c = 0;

	/*basic algorithm is
	 s = a ^ b ^ c
	 c = ( a * b ) | ( b * c ) | ( a * c )*/
	for( i = 0; i < sz; i ++ )
	{
		/*calculate the sum*/
		s[i] = a[i] ^ b[i] ^ c;

		/*calculate the carry*/
		c = ( a[i] & b[i] ) | ( b[i] & c ) | ( a[i] & c );
	}

	/*fixup last carry*/
	s[i] = c;

	return;
}



