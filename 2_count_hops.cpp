
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <vector>

using std::vector;

void count_hops( int* ar, int sz );
int count_hops_r( int* ar, int sz, int off );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int ar[] = { 1, 2, 3, 1, 1, 1 };

	count_hops( ar, 6 );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void count_hops( int* ar, int sz )
{
	printf( "reachable: %i\n", count_hops_r( ar, sz, 0 ) );	
	return;
}


/******************************************************************************
 *****************************************************************************/
int count_hops_r( int* ar, int sz, int off )
{
	int retv = 0;
	int i = 0;

	if( off >= sz )
		return 0;
	if( off == sz - 1 )
		return 1;
	
	for( i = 0; i < ar[off]; i ++ )
		if( ar[off + i] )
			retv += count_hops_r( ar, sz, off + ar[off + i] );

	return retv;
}


