
#include "bit_ops.h"
#include <stdio.h>		//printf
#include <stdlib.h>		//calloc
#include <string.h>		//memset
#include <time.h>		//seeding rand()
#include <limits.h>		//INT_MAX


/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int j = INT_MAX;
	int k = 0;

	srand( time( NULL ) );

	i = set_bit( i, 0 );
	i = set_bit( i, 2 );
	print_bytes_bin( &i, 1 );
	printf( "\n" );
	printf( "bit 0: %i\n", test_bit( i, 0 ) );
	printf( "bit 1: %i\n", test_bit( i, 1 ) );
	printf( "bit 2: %i\n", test_bit( i, 2 ) );
	i = clear_bit( i, 0 );
	i = clear_bit( i, 2 );
	print_bytes_bin( &i, 1 );
	printf( "\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int set_bit( int var, int bit_num )
{
	return var |= ( 1 << bit_num );
}


/******************************************************************************
 *****************************************************************************/
int clear_bit( int var, int bit_num )
{
	return var &= ~( 1 << bit_num );
}


/******************************************************************************
 *****************************************************************************/
int test_bit( int var, int bit_num )
{
	if( var & ( 1 << bit_num ) )
		return true;
	else
		return false;
}


/******************************************************************************
 *****************************************************************************/
int set_rightmost_one_zero( int val )
{
	return( val & ( val - 1 ) );
}


/******************************************************************************
 *****************************************************************************/
int set_rightmost_zero_one( int val )
{
	return( val | ( val + 1 ) );
}


/******************************************************************************
 *****************************************************************************/
int bitwise_abs( int val )
{
	int mask = val >> ( ( sizeof(int) * 8 - 1 ) ); //sign extension
	val ^= mask;
	return val - mask;
}


/******************************************************************************
func: this function works swapping nibbles.  effetively

a = 1111 0000
b = 0000 1111

a = a xor b; a = 1111 1111, b = 0000 1111
b = a xor b; a = 1111 1111, b = 1111 0000
a = a xor b; a = 0000 1111, b = 1111 0000
 *****************************************************************************/
void swap_no_temp_var( int* a, int* b )
{
	printf( "in: %i, %i\n", *a, *b );

	if( a != b && *a != *b )
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}

	printf( "out: %i, %i\n", *a, *b );

	return;
}


/******************************************************************************
func: round down to the nearest multiple of eight.  this works because in two's
compliment the low bits will be zero and the high bits will be one for negatibe
numbers
 *****************************************************************************/
int round_down_mul_eight( int val )
{
	return ( val & -8 );
}


/******************************************************************************
func: round up to the nearest mulitple of eight.  similar to above; seven is
used because rounding up on a boundary should yeild the number in question
 *****************************************************************************/
int round_up_mul_eight( int val )
{
	return ( ( val + 7 ) & -8 );
}


/******************************************************************************
func: this function works by setting the highest bit to zero (0x800...) and
shifting right until this value is immediatley below the input value
 *****************************************************************************/
int round_down_power_two( int val )
{
	int x = INT_MAX + 1;

	while( (unsigned)x > val )
		x = (unsigned)x >> 1;

	return x;
}


/******************************************************************************
func: this function works similar to above but we just shift until we are
greater than
 *****************************************************************************/
int round_up_power_two( int val )
{
	int x = 1;

	if( val < 0 )
		val -= 2*val;

	while( (unsigned)x < val )
		x *= 2;

	return x;
}


/******************************************************************************
func: acessory function for printing an arbitrary amount of bytes as their
binary representation
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


