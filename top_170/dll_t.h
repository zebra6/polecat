#pragma once


struct dll_t
{
	dll_t* l_next;
	dll_t* l_prev;
	int l_item;
};

void dll_t_print( dll_t* head );
short dll_t_exists( dll_t* head, int val );
void dll_t_insert( dll_t** head, int val );
void dll_t_insert_back( dll_t** head, int val );
int dll_t_remove( dll_t** head, int val );
void dll_t_remove_all( dll_t** head );
void dll_t_reverse( dll_t** head );



