#include "w_graph_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 8
#define NEDGE 16
#define MINW 5.0f
#define MAXW 15.0f

int main( int argc, char** argv )
{
	int i = 0;
	w_graph_t* g = new w_graph_t;

	srand(time(NULL));

	g->create_random( NMAX, NEDGE, MINW, MAXW );

	//g->print();
	g->mst_prim_lazy();
	g->mst_kruskal();

	if( g ) delete g;
	return 0;
}
