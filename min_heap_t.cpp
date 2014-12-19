
#include "min_heap_t.h"		//
#include <stdlib.h>			//calloc
#include <stdio.h>			//printf
#include <assert.h>			//assert
#include <math.h>			//power

/******************************************************************************
 *****************************************************************************/
min_heap_t::min_heap_t( int sz )
{
	int i = 0;
	assert( sz > 0 );

	h_ar = (int*)calloc( 1, sizeof(int) * sz );	
	h_ar_sz = sz;
	h_num_elements = 0;
	for( i = 0; i < sz; i ++ )
		h_ar[i] = -1;
}


/******************************************************************************
 *****************************************************************************/
min_heap_t::~min_heap_t( void )
{
	if( h_ar ) free( h_ar );
}


/******************************************************************************
 *****************************************************************************/
void min_heap_t::print_ext( void )
{
	printf( "heap %p is:\n", this );
	printf( "h_ar: %p\n", h_ar );
	printf( "h_ar_sz: %i\n", h_ar_sz );
	printf( "h_num_elements: %i\n", h_num_elements );
	printf( "array: " );
	print_ar();
	printf( "\n\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void min_heap_t::print_ar( void )
{
	int i = 0;

	for( i = 0; i < h_num_elements; i ++ )
		printf( "%i ", h_ar[i] );

	return;
}


/******************************************************************************
 *****************************************************************************/
void min_heap_t::print_levels( void )
{
	int i = 0;
	int j = pow( 2, i );
	int k = 0;

	printf( "levels:\n" );
	for( i = 0; i < h_num_elements; i ++ )
	{
		if( !j )
		{
			k++;
			j = pow( 2, k );
			printf( "\n" );
		}
		printf( "%i ", h_ar[i] );
		j--;
	}

	printf( "\n\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void min_heap_t::insert( int val )
{
	assert( h_num_elements < h_ar_sz );

	h_ar[h_num_elements++] = val;
	bubble_up( h_num_elements - 1 );
	return;
}


/******************************************************************************
 *****************************************************************************/
int min_heap_t::delmin( void )
{
	int tmp = min();
	if( !size() )
		return -1;

	h_ar[0] = -1;
	swap( h_ar, h_ar + (h_num_elements - 1) );
	h_num_elements--;
	bubble_down( 0 );

	return tmp;
}


/******************************************************************************
 *****************************************************************************/
short min_heap_t::exists( int val )
{
	int i = 0;

	/*this isn't a part of a heap but its useful for debugging*/
	for( i = 0; i < h_num_elements; i ++ )
		if( h_ar[i] == val )
			return 1;

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void min_heap_t::bubble_up( int off )
{
	int parent_off = ( off - 1 ) / 2;
	int child_off = off;

	/*float the node towards the top of the tree - use child_off to cover last
	 * parent = 0*/
	while( child_off && h_ar[parent_off] > h_ar[child_off] )
	{
		swap( h_ar + parent_off, h_ar + child_off );
		child_off = parent_off;
		parent_off /= 2;
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void min_heap_t::bubble_down( int off )
{
	int parent_off = off;
	int child_off = parent_off * 2;

	if( !child_off )
		child_off++;

	while( child_off < h_num_elements )
	{
		/*chose the smaller of the two children*/
		if( child_off < h_num_elements - 1 && h_ar[child_off] > h_ar[child_off+1] )
			child_off++;

		/*swap the parent with the child if necessary*/
		if( h_ar[parent_off] >= h_ar[child_off] )
			swap( h_ar + parent_off, h_ar + child_off );
		else
			break;

		parent_off = child_off;
		child_off *= 2;
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void min_heap_t::swap( int* a, int* b )
{
	int tmp = *a;
	if( *a == *b )
		return;

	*a = *b;
	*b = tmp;

	return;
}




