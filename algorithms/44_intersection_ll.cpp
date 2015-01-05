/*
find the intersection point of two linked lists
 */

#include <stdio.h>
#include <stdlib.h>
#include "sll_t.h"

#define MAX 12
#define SEC 4


/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	sll_t* a = NULL;
	sll_t* b = NULL;
	sll_t* tmp = NULL;
	sll_t* tmp2 = NULL;

	for( i = 0; i < MAX; i++ )
		sll_t_insert_back( &a, i );

	for( i = 0; i < SEC; i++ )
		sll_t_insert_back( &b, 99 );

	/*make them intersect*/
	tmp = a;
	tmp2 = b;
	while( tmp2->l_next )
	{
		tmp2 = tmp2->l_next;
		tmp = tmp->l_next;
	}

	tmp2->l_next = tmp->l_next;

	printf( "a: " );
	sll_t_print( a );
	printf( "\nb: " );
	sll_t_print( b );
	printf( "\n" );

	printf( "intersection: %i\n", sll_t_find_intersection( a, b ) );

	printf( "\n" );
	return 0;
}


/******************************************************************************
 *****************************************************************************/

