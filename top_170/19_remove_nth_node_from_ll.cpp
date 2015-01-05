/*
   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sll_t.h"

void remove_nth_from_list( sll_t** list, int n );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	sll_t* list = NULL;
	srand(time(NULL));

	for( i = 0; i < 8; i++ )
		sll_t_insert_back( &list, i );

	sll_t_print( list );
	printf( "\n" );

	remove_nth_from_list( &list, rand() % 12 );

	sll_t_remove_all( &list );
	return 0;
}



/******************************************************************************
 *****************************************************************************/
void remove_nth_from_list( sll_t** list, int n )
{
	sll_t* head = *list;
	sll_t* follower = *list;
	sll_t* tmp = NULL;

	printf( "node %i removal: ", n );

	/*add one to n so follower is pointing to the node behind the one we want to
	 * delete*/
	n++;
	while( n && head )
	{
		head = head->l_next;
		n--;
	}

	/*asked for a deletion past the end of the list*/
	if( !head )
	{
		printf( "node past end of list\n" );
		return;
	}

	/*walk to end of list*/
	while( head )
	{
		follower = follower->l_next;
		head = head->l_next;
	}

	tmp = follower->l_next;

	if( follower->l_next )
		follower->l_next = follower->l_next->l_next;
	else
		follower->l_next = NULL;

	free( tmp );

	sll_t_print( *list );
	printf( "\n" );
	return;
}


