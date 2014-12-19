#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "min_heap_t.h"
#define MAX 16

int main( int argc, char** argv )
{
	int i = 0;
	min_heap_t* h = new min_heap_t( 64 );
	srand(time(NULL));

	for( i = 0; i < 16; i ++ )
		h->insert( rand() % MAX + 1 );

	h->print_levels();

	printf( "deleting minimums: " );

	for( i = 0; i < 16; i ++ )
		printf( "%i ", h->delmin() );

	printf( "\n\n" );

	if( h ) delete h;
	return 0;
}
