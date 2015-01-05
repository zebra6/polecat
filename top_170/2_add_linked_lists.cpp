/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sll_t.h"

#define SZ 4

void add_two( sll_t* num_a, sll_t* num_b );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	sll_t* num_a = NULL;
	sll_t* num_b = NULL;

	srand(time(NULL));

	for( i = 0; i < SZ; i++ )
	{
		sll_t_insert( &num_a, rand() % 10 );
		sll_t_insert( &num_b, rand() % 10 );
	}

	printf( "num_a: " );
	sll_t_print( num_a );
	printf( "\n" );
	printf( "num_b: " );
	sll_t_print( num_b );
	printf( "\n" );

	add_two( num_a, num_b );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void add_two( sll_t* num_a, sll_t* num_b )
{
	int tmp = 0;
	int carry = 0;
	sll_t* sum = NULL;

	/*both lists have numbers*/
	while( num_a && num_b )
	{
		tmp = num_a->l_item + num_b->l_item + carry;
		carry = tmp / 10;
		tmp %= 10;
		sll_t_insert( &sum, tmp );

		num_a = num_a->l_next;
		num_b = num_b->l_next;
	}

	/*only a*/
	while( num_a && !num_b )
	{
		tmp = num_a->l_item + carry;
		sll_t_insert( &sum, tmp );
		num_a = num_a->l_next;
	}

	/*only b*/
	while( !num_a && num_b )
	{
		tmp = num_b->l_item + carry;
		sll_t_insert( &sum, tmp );
		num_b = num_b->l_next;
	}

	/*take care of left over carry*/
	if( carry )
		sll_t_insert( &sum, carry );

	/*reverse the linked list*/
	sll_t_reverse( &sum );	

	printf( "sum: " );
	sll_t_print( sum );
	printf( "\n\n" );

	return;
}
