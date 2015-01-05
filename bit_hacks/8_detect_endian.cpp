/*
   The “memset_16aligned” function requires a 16byte aligned pointer passed to it, or it will crash.

   a) How would you allocate 1024 bytes of memory, and align it to a 16 byte boundary?
   b) Free the memory after the memset_16aligned has executed.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>	//htonl

void print_bytes_bin( void* start, int num_bytes );
void big_end_test_1( void );
void big_end_test_2( void );
void big_end_test_3( void );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	big_end_test_1();
	big_end_test_2();
	big_end_test_3();
	return 0;
}


/******************************************************************************
 *****************************************************************************/
void big_end_test_1( void )
{
	union
	{
		uint32_t num;
		char c[4];
	} test = { 0x01020304 };

	if( test.c[0] == 1 )
		printf( "test 1: is big endian\n" );
	else
		printf( "test 1: is not big endian\n" );

	return;
}


/******************************************************************************
 *****************************************************************************/
void big_end_test_2( void )
{
	/*this works because network order is always big endian*/

	if( htonl( 1 ) == 1 )
		printf( "test 2: is big endian\n" );
	else
		printf( "test 2: is not big endian\n" );

	return;
}


/******************************************************************************
 *****************************************************************************/
void big_end_test_3( void )
{
	int num = 1;

	/*this relies on char and ints being different sizes*/

	if( *(char*)&num == 1 )
		printf( "test 3: is not big endian\n" );
	else
		printf( "test 3: is big endian\n" );

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

