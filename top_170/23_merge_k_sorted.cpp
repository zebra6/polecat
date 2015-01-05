/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LISTS 8
#define MAX 10

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int j = 0;
	sll_t* ar[NUM_LISTS] = { NULL };

	srand(time(NULL));

	/*populate the lists*/
	for( i = 0; i < 10; i ++ )
		for( j = 0; j < NUM_LISTS; j++ )
		{
			sll_t_insert( &ar[j], rand() % MAX );
		}



	return 0;
}



