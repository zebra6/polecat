/*
   function to mirror the bits in a value
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

int mirror_bits( int in );
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
		tmp = mirror_bits( tmp );
		print_bytes_bin( &tmp, sizeof(tmp) );
		printf( "\n\n" );
	}

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int mirror_bits( int in )
{
	/*this uses the same approach as the sideways summation of the population
	 * count algorithm*/

	in = ( in & 0x55555555 ) << 1 | ( in & 0xaaaaaaaa ) >> 1;
	in = ( in & 0x33333333 ) << 2 | ( in & 0xcccccccc ) >> 2;
	in = ( in & 0x0f0f0f0f ) << 4 | ( in & 0xf0f0f0f0 ) >> 4;
	in = ( in & 0x00ff00ff ) << 8 | ( in & 0xff00ff00 ) >> 8;
	in = ( in & 0x0000ffff ) << 16 | ( in & 0xffff0000 ) >> 16;

	return in;
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

