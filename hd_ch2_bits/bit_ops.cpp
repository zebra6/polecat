
#include "bit_ops.h"
#include <stdio.h>		//printf
#include <stdlib.h>		//calloc
#include <string.h>		//memset
#include <iostream>

using std::cout;
using std::endl;

/******************************************************************************
func:
 *****************************************************************************/
void run_tests( void )
{
	int i = 0;
	int j = 0;

	/*run some bit tests*/
	cout << "set rightmost 0->1:" << endl;
	for( i = 0; i < 16; i++ )
	{
		cout << i << ":" << endl;
		j = i;
		print_bytes_bin( &j, sizeof(j) );
		cout << endl;
		j = set_rightmost_zero_one( i );
		print_bytes_bin( &j, sizeof(j) );
		cout << endl;
		cout << endl;
	}

	cout << endl;
	cout << "set rightmost 1->0:" << endl;
	for( i = 0; i < 16; i++ )
	{
		cout << i << ":" << endl;
		j = i;
		print_bytes_bin( &j, sizeof(j) );
		cout << endl;
		j = set_rightmost_one_zero( i );
		print_bytes_bin( &j, sizeof(j) );
		cout << endl;
		cout << endl;
	}

	cout << endl;

	return;
}


/******************************************************************************
func:
 *****************************************************************************/
int set_rightmost_one_zero( int val )
{
	return( val & ( val - 1 ) );
}


/******************************************************************************
func:
 *****************************************************************************/
int set_rightmost_zero_one( int val )
{
	return( val | ( val + 1 ) );
}


/******************************************************************************
func:
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
		{
			/*+2 here because we want an offset and not a size*/
			to_print[size - ( ( i * 8 + i ) + j + 2 )] =
				(*off) & ( 1 << j ) ? '1' : '0';

		}

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


