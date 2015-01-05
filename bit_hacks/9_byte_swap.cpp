/*
	c program to swap bytes in an int
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define TIMES 8

void print_bytes_bin( void* start, int num_bytes );
void swap_bytes_1( int in );
void swap_bytes_2( int in );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int tmp = 0;
	for( i = 0; i < TIMES; i++ )
	{
		tmp = rand() % INT_MAX;
		swap_bytes_1( tmp );
		swap_bytes_2( tmp );
		printf( "\n" );
	}

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void swap_bytes_1( int in )
{
	/*only for 32-bit ints*/
	int retv = 0;

	retv = ( in >> 24 & 0xff ) |
		( in >> 8 & 0xff00 ) |
		( in << 8 & 0xff0000 ) |
		( in << 24 & 0xff000000 );

	printf( "original:\t%x\nswapped:\t%x", in, retv );
	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void swap_bytes_2( int in )
{
	int i = 0;
	int j = sizeof(in) - 1;
	int retv = in;
	char tmp = '\0';
	char* inp = (char*)&retv;

	/*more general bytes reversal method*/
	for( ; i < j; i++, j-- )
	{
		tmp = *inp+i;
		*(inp+i) = *(inp+j);
		*(inp+j) = tmp;
	}

	printf( "original:\t%x\nswapped:\t%x", in, retv );
	printf( "\n" );

	return;
}
