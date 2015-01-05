#include <stdio.h>
#include <stdlib.h>
#include "dll_t.h"


/******************************************************************************
 *****************************************************************************/
void dll_t_print( dll_t* head )
{
	dll_t* tmp = head;
	while( tmp )
	{
		printf( "%2i ", tmp->l_item );
		tmp = tmp->l_next;
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
short dll_t_exists( dll_t* head, int val )
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


/******************************************************************************
 *****************************************************************************/
void dll_t_insert( dll_t** head, int val )
{
	dll_t* new_node = (dll_t*)calloc( 1, sizeof(*new_node) );
	new_node->l_item = val;
	new_node->l_prev = NULL;

	/*no head, so don't need to update l_prev pointer*/
	if( !*head )
	{
		new_node->l_next = NULL;
		*head = new_node;
		return;
	}

	/*otherwise insert at the front of the list and update head's prev pointer*/
	(*head)->l_prev = new_node;
	new_node->l_next = *head;
	*head = new_node;
	return;
}


/******************************************************************************
 *****************************************************************************/
void dll_t_insert_back( dll_t** head, int val )
{
	dll_t* new_node = (dll_t*)calloc( 1, sizeof(*new_node) );
	new_node->l_item = val;
	new_node->l_next = NULL;
	new_node->l_prev = NULL;
	dll_t* tmp = *head;

	/*no head so create it and return*/
	if( !*head )
	{
		*head = new_node;
		return;
	}

	/*otherwise iterate*/
	while( tmp->l_next )
		tmp = tmp->l_next;

	/*found the end of the list, so insert and update prev pointer*/
	tmp->l_next = new_node;
	new_node->l_prev = tmp;
	return;
}


/******************************************************************************
 *****************************************************************************/
int dll_t_remove( dll_t** head, int val )
{
	int retv = -1;
	dll_t* tmp = *head;
	dll_t* tmp_2 = NULL;

	/*find the item we are looking for*/
	while( tmp && tmp->l_item != val )
	{
		tmp_2 = tmp;
		tmp = tmp->l_next;
	}

	/*didn't exist*/
	if( !tmp )
		return retv;

	retv = tmp->l_item;

	/*delete it and update pointers*/
	if( tmp_2 )
	{
		/*we were not the head of the list*/
		tmp_2->l_next = tmp->l_next;

		/*we may have been at the tail though, so check before dereferencing*/
		if( tmp->l_next )
			tmp->l_next->l_prev = tmp_2;
	}
	else
	{
		/*we were the head so update accordingnly*/
		*head = tmp->l_next;

		/*we may have just deleted the last element so check*/
		if( *head )
			(*head)->l_prev = NULL;
	}

	free( tmp );
	return retv;
}



/******************************************************************************
 *****************************************************************************/
void dll_t_remove_all( dll_t** head )
{
	dll_t* tmp = *head;
	dll_t* tmp_2 = NULL;

	while( tmp )
	{
		tmp_2 = tmp->l_next;
		free( tmp );
		tmp = tmp_2;
	}

	*head = tmp;
}


/******************************************************************************
 *****************************************************************************/
void dll_t_reverse( dll_t** head )
{
	dll_t* current = *head;
	dll_t* tmp = NULL;

	while( current )
	{
		tmp = current->l_prev;				//tmp points to the previous node
		current->l_prev = current->l_next;	//change previous to next;
		current->l_next = tmp;				//now use the tmp pointer to restore
		current = current->l_prev;			//walk forward (backwards)
	}

	/*make sure we had a valid list before reassigning the head pointer*/
	if( tmp )
		*head = tmp->l_prev;

	return;
}

