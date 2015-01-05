/*
   count number of trailing
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

int num_trailing_zeros_32( uint32_t in );
void print_bytes_bin( void* start, int num_bytes );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int tmp = 0;
	srand(time(NULL));

	for( i = 0; i < 10; i++ )
	{
		tmp = rand() % INT_MAX;
		print_bytes_bin( &tmp, sizeof(tmp) );
		printf( "\n" );
		printf( "ntz 32: %i\n", num_trailing_zeros_32( tmp ) );
	}

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int num_trailing_zeros_32( uint32_t in )
{
	int retv = 1;
	
	if( !in )
		return 32;

	if( ( in & 0x0000ffff ) == 0 )
	{
		retv += 16;
		in >>= 16;
	}
	if( ( in & 0x000000ff ) == 0 )
	{
		retv += 8;
		in >>= 8;
	}
	if( ( in & 0x0000000f ) == 0 )
	{
		retv += 4;
		in >>= 4;
	}
	if( ( in & 0x00000003 ) == 0 )
	{
		retv += 2;
		in >>= 2;
	}

	retv -= ( in & 1 );

	return retv;
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

