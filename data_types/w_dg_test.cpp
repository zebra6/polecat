#include <stdio.h>
#include <stdlib.h>
#include "w_dg_t.h"
#include "time.h"

int main( int argc, char** argv )
{
	w_dg_t* g = new w_dg_t;
	srand(time(NULL));

	g->create_random( 8, 16, 1.0f, 10.0f );
	g->print();

	if( g ) delete g;
	return 0;
}
