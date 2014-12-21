
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

short rotate( short val, short amt, short dir );
void print_bytes_bin( void* start, int num_bytes );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	short amt = 5;
	short a = SHRT_MAX - ( SHRT_MAX / 2 );

	printf( "original: %i\n", a );
	print_bytes_bin( &a, sizeof(a) );
	printf( "\n\n" );

	printf( "shift left %i:\n", amt );
	a = rotate( a, amt, 0 );
	print_bytes_bin( &a, sizeof(a) );
	printf( " (%i)\n\n", a );

	printf( "shift right %i:\n", amt );
	a = rotate( a, amt, 1 );
	print_bytes_bin( &a, sizeof(a) );
	printf( " (%i)\n\n", a );

	printf( "shift right %i:\n", amt );
	a = rotate( a, amt, 1 );
	print_bytes_bin( &a, sizeof(a) );
	printf( " (%i)\n\n", a );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
short rotate( short val, short amt, short dir )
{
	switch( dir )
	{
		case 0:		//left
			return(  ( val << amt ) |
					( val >> ( ( sizeof(short) * 8 ) - amt ) ) );
			break;

		case 1:		//right
			return(  ( val >> amt ) |
					( val << ( ( sizeof(short) * 8 ) - amt ) ) );
			break;

		default:
			assert( 0 );
			break;
	}

	return -1;		
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

