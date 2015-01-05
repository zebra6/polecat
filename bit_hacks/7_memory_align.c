/*
   The “memset_16aligned” function requires a 16byte aligned pointer passed to it, or it will crash.

a) How would you allocate 1024 bytes of memory, and align it to a 16 byte boundary?
b) Free the memory after the memset_16aligned has executed.
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

void print_bytes_bin( void* start, int num_bytes );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	/*first - request memory from the kernel for the desired size plus the
	 * bounardy alignment condition*/
	int* pointer = (int*)malloc( 1024 + 16 );
	int* pointer2 = pointer;
	printf( "original address: %p\n", pointer );

	/*somewhere in the first 16 bytes we now have a guaranteed address that is a
	 * multiple of 16 for alignment*/

	/*add one here for demonstration*/
	pointer = (uintptr_t)pointer + 1;
	printf( "plus one: %p\n", pointer );

	/*now we add 16 to the start address (15 will work as well) as the correct
	 * start offset will be in this space*/
	pointer = (uintptr_t)pointer + 16;
	printf( "plus 16: %p\n", pointer );

	/*next mask off the last four bits to round down to an appropriatley aligned
	 * space*/
	pointer = (uintptr_t)pointer & ~(uintptr_t)0x0f;
	printf( "masked 0x0f: %p\n", pointer );

	free( pointer2 );
	return 0;
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

