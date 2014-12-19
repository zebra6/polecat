#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sll_t.h"

#define SZ 16
#define MAX 32

int main( int argc, char** argv )
{
	int i = 0;
	sll_t* list = NULL;
	srand(time(NULL));

	for( i = 0; i < SZ; i ++ )
		sll_t_insert( &list, SZ - i - 1 );

	sll_t_set_all_randoms( list, SZ );
	sll_t_print( list );
	
	sll_t_deep_copy( list );	

	sll_t_remove_all( &list );

	return 0;
}


