/*
check if a given bst is a valid bst or not
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst_t.h"


int main( int argc, char** argv )
{
	bst_t t;

	t.populate_random( 16, 4, 128 );
	printf( "check valid, traversal1: %i\n", t.check_valid_traversal() );
	printf( "check valid, traversal2: %i\n", t.check_valid_from_root() );

	return 0;
}









