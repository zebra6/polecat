#pragma once


struct sll_t
{
	sll_t* l_next;
	sll_t* l_random;
	int l_item;
};

void sll_t_print( sll_t* head );
short sll_t_exists( sll_t* head, int val );
void sll_t_insert( sll_t** head, int val );
void sll_t_insert_back( sll_t** head, int val );
int sll_t_remove( sll_t** head, int val );
void sll_t_remove_all( sll_t** head );
sll_t* sll_t_get_random( sll_t* head, int sz );
void sll_t_set_all_randoms( sll_t* head, int sz );
void sll_t_reverse( sll_t** head );
void sll_t_deep_copy( sll_t* head );
int sll_t_find_intersection( sll_t* a, sll_t* b );
int sll_t_find_cycle( sll_t* a );
