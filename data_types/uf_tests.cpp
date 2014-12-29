#include <stdio.h>
#include <stdlib.h>
#include "uf_t.h"

int main( int argc, char** argv )
{
	uf_t* uf = new uf_t( 32 );

	uf->print();

	if( uf ) delete uf;
	return 0;
}
