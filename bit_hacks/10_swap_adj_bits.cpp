/*
	c program to swap bytes in an int
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define TIMES 2

void print_bytes_bin( void* start, int num_bytes );
void swap_adj_bits_1( int in );
void swap_adj_bits_2( char* in, int num_bytes );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	short tmp = 0;
	for( i = 0; i < TIMES; i++ )
	{
		tmp = rand() % INT_MAX;
		swap_adj_bits_1( tmp );
		swap_adj_bits_2( (char*)&tmp, sizeof(int) );
		printf( "\n" );
	}

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void swap_adj_bits_1( int in )
{
	int retv = 0;
	int evens = in & 0xaaaaaaaa;
	int odds = in & 0x55555555;

	/*only for 32 bit ints*/
	retv = ( evens >> 1 | odds << 1 );

	printf( "original:\n" );
	print_bytes_bin( (void*)&in, sizeof(in) );
	printf( "\nswapped:\n" );
	print_bytes_bin( (void*)&retv, sizeof(retv) );
	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void swap_adj_bits_2( char* in, int num_bytes )
{
	int i = 0;
	char* retv = (char*)calloc( 1, num_bytes );
	char even = 0xaa;
	char odd = 0x55;

	for( i = 0; i < num_bytes; i ++ )
	{
		*retv = ( ( *in & odd ) << 1 ) |
			( ( *in & even ) >> 1 );
		retv++;
		in++;
	}

	retv -= num_bytes;
	in -= num_bytes;

	printf( "original:\n" );
	print_bytes_bin( (void*)in, num_bytes );
	printf( "\nswapped:\n" );
	print_bytes_bin( (void*)retv, num_bytes );
	printf( "\n" );

	free( retv );
	return;
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

