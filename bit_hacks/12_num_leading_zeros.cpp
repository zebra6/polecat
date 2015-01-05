/*
   count number of leading zeros
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

int num_leading_zeros_32( uint32_t in );
int num_leading_zeros_64( uint64_t in );
void print_bytes_bin( void* start, int num_bytes );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int tmp = 0;

	for( i = 0; i < 10; i++ )
	{
		tmp = rand() % INT_MAX;
		print_bytes_bin( &tmp, sizeof(tmp) );
		printf( "\n" );
		printf( "nlz 32: %i\n", num_leading_zeros_32( tmp ) );
		printf( "nlz 64: %i\n", num_leading_zeros_64( (uint64_t)tmp ) );
	}

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int num_leading_zeros_32( uint32_t in )
{
	int retv = 1;
	
	if( !in )
		return 32;

	/*this is essentially binary search on the input variable*/
	if( in >> 16 == 0 )
	{
		retv += 16;
		in <<= 16;
	}
	if( in >> 24== 0 )
	{
		retv += 8;
		in <<= 8;
	}
	if( in >> 28 == 0 )
	{
		retv += 4;
		in <<= 4;
	}
	if( in >> 30 == 0 )
	{
		retv += 2;
		in <<= 2;
	}

	retv -= ( in >> 31 );

	return retv;
}


/******************************************************************************
 *****************************************************************************/
int num_leading_zeros_64( uint64_t in )
{
	int retv = 1;
	
	if( !in )
		return 64;

	if( in >> 32 == 0 )
	{
		retv += 32;
		in <<= 32;
	}
	if( in >> 48 == 0 )
	{
		retv += 16;
		in <<= 16;
	}
	if( in >> 56 == 0 )
	{
		retv += 8;
		in <<= 8;
	}
	if( in >> 60 == 0 )
	{
		retv += 4;
		in <<= 4;
	}
		if( in >> 62 == 0 )
	{
		retv += 2;
		in <<= 2;
	}

	retv -= ( in >> 63 );

	return retv;	return 0;
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

