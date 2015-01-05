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
	sll_t* tmp = NULL;
	sll_t* tmp2 = NULL;

	for( i = 0; i < MAX; i++ )
		sll_t_insert_back( &a, i );

	/*make a loop*/
	tmp = a;
	tmp2 = a;
	while( tmp->l_next && i < SEC )
	{
		tmp = tmp->l_next;
		i++;
	}

	/*find the end of the list*/
	while( tmp2->l_next )
		tmp2 = tmp2->l_next;

	/*point it at the existing node*/
	tmp2->l_next = tmp;

	printf( "cycle at: %i\n", sll_t_find_cycle( a ) );
	printf( "\n" );
	sll_t_print( a );
	printf( "\n" );

	sll_t_remove_all( &a );
	return 0;
}


/******************************************************************************
 *****************************************************************************/

