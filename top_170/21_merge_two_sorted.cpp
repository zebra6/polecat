/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../data_types/sll_t.h"

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;

	sll_t* a = NULL;
	sll_t* b = NULL;
	sll_t* result = NULL;


	sll_t_insert_back( &a, -2 );
	sll_t_insert_back( &a, 5 );
	sll_t_insert_back( &a, 10 );
	sll_t_insert_back( &a, 16 );
	sll_t_insert_back( &a, 22 );
	sll_t_insert_back( &a, 22 );
	sll_t_insert_back( &a, 34 );

	sll_t_insert_back( &b, -1 );
	sll_t_insert_back( &b, 9 );
	sll_t_insert_back( &b, 29 );
	sll_t_insert_back( &b, 49 );
	sll_t_insert_back( &b, 200 );

	printf( "a: " );
	sll_t_print( a );
	printf( "\nb: " );
	sll_t_print( b );

	/*this is implemented in the sll class*/
	sll_t_merge( a, b, &result );

	printf( "\nresult: " );
	sll_t_print( result );
	printf( "\n\n" );

	sll_t_remove_all( &a );
	sll_t_remove_all( &b );
	sll_t_remove_all( &result );

	return 0;
}



