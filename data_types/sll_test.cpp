#include <stdio.h>
#include <stdlib.h>
#include "sll_t.h"

int main( int argc, char** argv )
{
	int i = 0;
	sll_t* list = NULL;

	for( i = 0; i < 10; i++ )
		sll_t_insert_back( &list, i );

	sll_t_print( list );
	printf( "\n" );

	sll_t_reverse2( list );

	sll_t_print( list );
	printf( "\n" );

	sll_t_remove_all( &list );
	printf( "\n" );
	return 0;
}
