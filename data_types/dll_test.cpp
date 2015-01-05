#include <stdio.h>
#include <stdlib.h>
#include "dll_t.h"

int main( int argc, char** argv )
{
	int i = 0;
	dll_t* list = NULL;

	for( i = 0; i < 10; i++ )
		dll_t_insert_back( &list, i );

	dll_t_print( list );
	printf( "\n" );

	dll_t_reverse( &list );

	dll_t_print( list );
	printf( "\n" );

	dll_t_remove_all( &list );
	printf( "\n" );
	return 0;
}
