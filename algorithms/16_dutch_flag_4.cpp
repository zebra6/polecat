/*
   Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[].
   The functions should put all 0s first, then all 1s and all 2s in last.

   Example Input = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}; Output = {0, 0, 0, 0,
   0, 1, 1, 1, 1, 1, 2, 2}

   The problem is similar to our old post Segregate 0s and 1s in an array, and
   both of these problems are variation of famous Dutch national flag problem.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 16

void swap( int* a, int* b );
void dflag( int* ar, int sz );

int main( int argc, char** argv )
{
	int i = 0;
	int ar[MAX] = { 0 };

	srand(time(NULL));

	printf( "array before: " );
	for( i = 0; i < MAX; i ++ )
	{
		ar[i] = rand() % 4;
		printf( "%i ", ar[i] );
	}

	dflag( ar, MAX );

	printf( "\narray after:  " );
	for( i = 0; i < MAX; i ++ )
		printf( "%i ", ar[i] );

	printf( "\n" );

	return 0;
}


void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}


void dflag( int* ar, int sz )
{
	int low = 0;
	int mid = 0;
	int mid2 = sz - 1;
	int high = sz - 1;

	/*basically we maintain an undefined region of the array that is constantly
	 * shrinking (in the middle) so we switch on mid*/

	/*http://stackoverflow.com/questions/3433797/mauritus-national-flag-problem*/
	/*TODO - there is an off by one error at the end of the array*/

	while( mid < mid2 )
	{
		switch( ar[mid] )
		{
			case 0:
				swap( ar + low, ar + mid );
				low++;
				mid++;
				break;

			case 1:
				mid++;
				break;

			case 2:
				mid2--;
				swap( ar + mid, ar + mid2 );
				break;

			case 3:
				swap( ar + ( high - 1 ), ar + ( mid2 - 1 ) );
				swap( ar + mid, ar + high - 1 );
				high--;
				mid2--;
				break;
		}
	}

	return;
}
