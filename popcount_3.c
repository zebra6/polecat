
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

int pcount_2( int val );
void print_bytes_bin( void* start, int num_bytes );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int a = 5;

	printf( "population count " );

	for( i = 0; i < 10; i ++ )
	{
		a = i * 2;
		print_bytes_bin( &a, sizeof(a) );
		printf( " (%i): %i\n", a, pcount_2( a ) );
	}

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int pcount_2( int val )
{
	int count = 0;

	while( val )
	{
		if( val & 1 ) count++;
		val >>= 1;
	}

	return count;
}


/******************************************************************************
 *****************************************************************************/
void print_bytes_bin( void* start, int num_bytes )
{
	int i = 0;
	int j = 0;
	char* to_print = NULL;
	char* off = (char*)start;
	int size = ( num_bytes * 8 ) + num_bytes; //no +1, discard leading space
	to_print = (char*)calloc( 1, size );

	if( !start || num_bytes < 1 )
		goto out;

	if( !to_print )
	{
		printf( "memory error" );
		goto out;
	}

	for( i = 0; i < num_bytes; i ++ )
	{
		for( j = 0; j < 8; j ++ )
			/*+2 here because we want an offset and not a size*/
			to_print[size - ( ( i * 8 + i ) + j + 2 )] =
				(*off) & ( 1 << j ) ? '1' : '0';

		/*advance the pointer*/
		off++;

		/*put a space between bytes execpt for leading*/
		if( i != num_bytes - 1 )
			to_print[size - ( ( i * 8 + i ) + j + 2 )] = ' ';
	}

	printf( "%s", to_print );

out:
	if( to_print ) free ( to_print );
	return;
}

