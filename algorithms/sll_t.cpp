#include <stdio.h>
#include <stdlib.h>
#include "sll_t.h"

/*
   void sll_t_print( sll_t* head );
   short sll_t_exists( sll_t* head, int val );
   void sll_t_insert( sll_t** head, int val );
   int sll_t_remove( sll_t** head, int val );
   void sll_t_remove_all( sll_t** head );
 */

void sll_t_print( sll_t* head )
{
	sll_t* tmp = head;
	while( tmp )
	{
		printf( "%2i ", tmp->l_item );
		tmp = tmp->l_next;
	}
/*	printf( "\n" );
	tmp = head;

	while( tmp )
	{
		printf( " | " );
		tmp = tmp->l_next;
	}
	printf( "\n" );
	tmp = head;

	while( tmp )
	{
		printf( "%2i ", tmp->l_random->l_item );
		tmp = tmp->l_next;
	}

	printf( "\n\n" );*/
	return;
}


short sll_t_exists( sll_t* head, int val )
{
	while( head )
	{
		if( head->l_item == val )
			return 1;
		else
			head = head->l_next;
	}

	return 0;
}


void sll_t_insert( sll_t** head, int val )
{
	sll_t* new_node = (sll_t*)calloc( 1, sizeof(*new_node) );
	new_node->l_item = val;

	if( !*head )
	{
		new_node->l_next = NULL;
		*head = new_node;
		return;
	}

	new_node->l_next = *head;
	*head = new_node;
	return;
}


void sll_t_insert_back( sll_t** head, int val )
{
	sll_t* new_node = (sll_t*)calloc( 1, sizeof(*new_node) );
	new_node->l_item = val;
	new_node->l_next = NULL;
	new_node->l_random = NULL;
	sll_t* tmp = *head;

	if( !*head )
	{
		*head = new_node;
		return;
	}

	while( tmp->l_next )
		tmp = tmp->l_next;

	tmp->l_next = new_node;
	return;
}


int sll_t_remove( sll_t** head, int val )
{
	int retv = -1;
	sll_t* tmp = *head;
	sll_t* tmp_2 = NULL;

	while( tmp && tmp->l_item != val )
	{
		tmp_2 = tmp;
		tmp = tmp->l_next;
	}

	if( !tmp )
		return retv;

	retv = tmp->l_item;

	if( tmp_2 )
		tmp_2->l_next = tmp->l_next;
	else
		*head = tmp->l_next;

	free( tmp );
	return retv;
}


void sll_t_remove_all( sll_t** head )
{
	sll_t* tmp = *head;
	sll_t* tmp_2 = NULL;

	while( tmp )
	{
		tmp_2 = tmp->l_next;
		free( tmp );
		tmp = tmp_2;
	}

	*head = tmp;
}

sll_t* sll_t_get_random( sll_t* head, int sz )
{
	int i = rand() % sz;
	sll_t* tmp = head;

	while( i-- )
	{
		head = head->l_next;
		
		if( !head )
			head = tmp;
	}

	return head;
}


void sll_t_set_all_randoms( sll_t* head, int sz )
{
	sll_t* tmp = head;

	while( head )
	{
		head->l_random = sll_t_get_random( tmp, sz );
		head = head->l_next;
	}

	return;
}


void sll_t_reverse( sll_t** head )
{
	sll_t* prev = NULL;
	sll_t* current = *head;
	sll_t* next = NULL;

	while( current )
	{
		next = current->l_next;		//NULL a->b
		current->l_next = prev;		//NULL<-a b
		prev = current;				//a is now prev
		current = next;				//b is now current
	}

	*head = prev;

	return;
}


void sll_t_deep_copy( sll_t* head )
{
	sll_t* copy = NULL;
	sll_t* tmp = NULL;
	sll_t* tmp2 = head;

	/*http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer*/

	while( head )
	{
		/*insert the value from the original list in the new one*/
		sll_t_insert( &copy, head->l_item );

		/*set the new node to point back to the original*/
		copy->l_random = head;

		/*set head's next pointer to point to the copy*/
		tmp = head->l_next;
		head->l_next = copy;
		head = tmp;
	}

	/*the list was created in reverse order*/
	sll_t_reverse( &copy );

	tmp = copy;

	/*now assign the real random pointers*/
	while( tmp )
	{
		/*use the link to set the random pointer*/
		tmp->l_random = tmp->l_random->l_random->l_next;

		/*continue*/
		tmp = tmp->l_next;
	}

	/*now reset all the links in the original linked list*/
	while( tmp2 )
	{
		/*doesn't work with duplicate random pointers
		tmp2->l_next = tmp2->l_random->l_next->l_random;
		tmp2 = tmp2->l_next;*/
	}

	sll_t_print( copy );

	sll_t_remove_all( &copy );

	return;
}


/******************************************************************************
 *****************************************************************************/
int sll_t_find_intersection( sll_t* a, sll_t* b )
{
	int i = 0;
	int retv = -1;
	sll_t* tmp1 = a;
	sll_t* tmp2 = b;

	while( tmp1 && retv == -1 )
	{
		/*reset tmp2 to the head of b*/
		tmp2 = b;
		i = 0;

		/*walk through b*/
		while( tmp2 && retv == -1 )
		{
			/*check for match*/
			if( tmp1 == tmp2 )
			{
				retv = i;
				break;
			}

			/*advance and update the count*/
			tmp2 = tmp2->l_next;
			i++;
		}

		/*advance and update the count*/
		tmp1 = tmp1->l_next;
	}

	return retv;
}


/******************************************************************************
 *****************************************************************************/
int sll_t_find_cycle( sll_t* a )
{
	int retv = -1;
	int loc = -1;
	int num_nodes = 0;
	sll_t* fast = a;
	sll_t* slow = a;
	sll_t* tmp1 = a;
	sll_t* tmp2 = a;

	/*first find the loop*/
	while( fast && slow && fast->l_next )
	{
		fast = fast->l_next->l_next;
		slow = slow->l_next;

		if( fast == slow )
		{
			retv = 1;
			break;
		}
	}

	/*no loop was found*/
	if( retv <= 0 )
		return retv;

	/*now count how many nodes are in the loop*/
	tmp1 = fast;
	while( tmp1->l_next != fast )
	{
		tmp1 = tmp1->l_next;
		num_nodes++;
	}

	retv = num_nodes;

	/*now have another pointer point at the head of the list, and advance it the
	 * same number of nodes that are in the loop*/
	while( num_nodes-- )
		tmp2 = tmp2->l_next;

	/*now advance both pointers until they meet, this will be the starting
	 * node*/
	while( tmp1 != tmp2 )
	{
		tmp1 = tmp1->l_next;
		tmp2 = tmp2->l_next;
	}

	/*go around one more time to get the tail node (could be removed with
	 * another pointer in the above loop*/
	tmp2 = tmp2->l_next;
	while( tmp2->l_next != tmp1 )
		tmp2 = tmp2->l_next;

	tmp2->l_next = NULL;

	return retv;
}
