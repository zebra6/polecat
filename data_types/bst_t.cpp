
#include "bst_t.h"
#include <stdlib.h>		//rand etc
#include <stdio.h>		//printf
#include <time.h>		//rand seed
#include <assert.h>		//assert
#include <vector>		//level traversal lists
#include <queue>		//queue version of level traversal
#include <deque>		//queue for zero sink
#include <limits.h>		//INT_MAX

using std::vector;
using std::queue;
using std::max;
using std::deque;

/******************************************************************************
 *****************************************************************************/
bst_node_t::bst_node_t( void )
{
	n_parent = NULL;
	n_left = NULL;
	n_right = NULL;
	n_item = -1;
}


/******************************************************************************
 *****************************************************************************/
bst_node_t::~bst_node_t( void )
{
	delete n_left;
	delete n_right;
}


/******************************************************************************
 *****************************************************************************/
bst_t::bst_t( void )
{
	t_root = NULL;
}


/******************************************************************************
 *****************************************************************************/
bst_t::~bst_t( void )
{
	if( t_root )
		delete t_root;
}


/******************************************************************************
 *****************************************************************************/
void bst_t::populate_random( int num, int min, int max )
{
	int i = 0;
	int failed = 0;
	srand(time(NULL));

	for( i = 0; i < num; )
	{
		if( !insert( rand() % ( max - min ) + min ) )
			i++;
		else failed++;
	}

	printf( "sucessful inserts: %i, failed inserts: %i\n", i, failed );

	return;
}


/******************************************************************************
 *****************************************************************************/
int bst_t::insert( int val )
{
	if( exists( val ) )
		return -1;

	t_root = insert_r( val, t_root );
	return 0;
}


/******************************************************************************
 *****************************************************************************/
bst_node_t* bst_t::insert_r( int val, bst_node_t* node )
{
	bst_node_t* new_node = NULL;

	/*base case*/
	if( !node )
	{
		new_node = new bst_node_t;
		new_node->n_item = val;
		return new_node;
	}

	else if( val > node->n_item )
		node->n_right = insert_r( val, node->n_right );
	else if( val < node->n_item )
		node->n_left = insert_r( val, node->n_left );
	else
		assert( false );

	return node;
}


/******************************************************************************
 *****************************************************************************/
int bst_t::remove( int val )
{

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int bst_t::exists( int val )
{
	return exists_r( val, t_root );
}


/******************************************************************************
 *****************************************************************************/
int bst_t::exists_r( int val, bst_node_t* node )
{
	if( !node )	return 0;
	else if( node->n_item == val ) return 1;
	else if( node->n_item < val ) return exists_r( val, node->n_right );
	else if( node->n_item > val ) return exists_r( val, node->n_left );
	else return -1;
}


/******************************************************************************
 *****************************************************************************/
int bst_t::height( void )
{
	printf( "height: %i\n", height_r( t_root ) );
	return height_r( t_root );
}


/******************************************************************************
 *****************************************************************************/
int bst_t::height_r( bst_node_t* n )
{
	if( !n )
		return 0;

	return( max( height_r( n->n_left ), height_r( n->n_right ) ) + 1 );
}



/******************************************************************************
 *****************************************************************************/
void bst_t::preorder( void )
{
	printf( "preorder traversal: " );
	preorder_r( t_root );
	printf( "\n" );
}


/******************************************************************************
 *****************************************************************************/
void bst_t::preorder_r( bst_node_t* n )
{
	if( !n ) return;

	printf( "%i ", n->n_item );
	preorder_r( n->n_left );
	preorder_r( n->n_right );
	return;
}


/******************************************************************************
 *****************************************************************************/
void bst_t::inorder( void )
{
	printf( "inorder traversal: " );
	inorder_r( t_root );
	printf( "\n" );
}


/******************************************************************************
 *****************************************************************************/
void bst_t::inorder_r( bst_node_t* n )
{
	if( !n ) return;

	inorder_r( n->n_left );
	printf( "%i ", n->n_item );
	inorder_r( n->n_right );
	return;
}


/******************************************************************************
 *****************************************************************************/
void bst_t::postorder( void )
{
	printf( "postorder traversal: " );
	postorder_r( t_root );
	printf( "\n" );
}


/******************************************************************************
 *****************************************************************************/
void bst_t::postorder_r( bst_node_t* n )
{
	if( !n ) return;

	postorder_r( n->n_left );
	postorder_r( n->n_right );
	printf( "%i ", n->n_item );
	return;
}


/******************************************************************************
 *****************************************************************************/
void bst_t::level_traverse( void )
{
	int i = 0;
	int j = 0;
	vector< vector<int> > lists;

	printf( "level traversal, recursive:\n" );

	level_traverse_r( &lists, t_root, 1 );

	for( i = 0; i < lists.size(); i ++ )
	{
		printf( "%i: ", i );

		for( j = 0; j < lists[i].size(); j ++ )
			printf( "%i ", lists[i][j] );

		printf( "\n" );
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void bst_t::level_traverse_r(
		vector< vector<int> >* lists,
		bst_node_t* node,
		int level )
{
	vector<int> to_add;

	if( !node )
		return;

	if( lists->size() < level )
	{
		to_add.push_back( node->n_item );
		lists->push_back( to_add );
	}
	else
	{
		(*lists)[level-1].push_back( node->n_item );
	}

	level_traverse_r( lists, node->n_left, level+1 );
	level_traverse_r( lists, node->n_right, level+1 );

	return;
}


/******************************************************************************
 *****************************************************************************/
void bst_t::level_traverse_queue( void )
{
	queue<bst_node_t*> q;

	printf( "level traversal, queue:\n" );

	q.push( t_root );

	while( !q.empty() )
	{
		/*print the value*/
		printf( "%i ", q.front()->n_item );

		/*add the children*/
		if( q.front()->n_left )
			q.push( q.front()->n_left );
		if( q.front()->n_right )
			q.push( q.front()->n_right );

		/*remove the front node*/
		q.pop();
	}

	printf( "\n" );

	return;
}


/******************************************************************************
 *****************************************************************************/
void bst_t::zero_sink( void )
{
	int i = 0;
	int j = 0;
	deque<bst_node_t*> q;
	vector<bst_node_t*> list;
	printf( "zero sink:\n" );

	q.push_back( t_root );

	/*construct a list of nodes using bfs*/
	while( !q.empty() )
	{
		list.push_back( q.front() );
		if( q.front()->n_left )
			q.push_back( q.front()->n_left );
		if( q.front()->n_right )
			q.push_back( q.front()->n_right );

		q.pop_front();
	}

	/*use this list to move zeros to the end*/
	for( i = 0; i < list.size(); i ++ )
	{
		/*i moves every time, j moves with existing values*/
		if( list[i]->n_item )
			list[j++]->n_item = list[i]->n_item;
	}

	/*fill the remaining with zeros*/
	for( ; j < list.size(); j ++ )
		list[j]->n_item = 0;

	for( i = 0; i < list.size(); i ++ )
		printf( "%i ", list[i]->n_item );

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
int bst_t::check_valid_traversal( void )
{
	int i = 0;
	vector<int> list;

	check_valid_traversal_r( &list, t_root );

	for( i = 0; i < list.size() - 1; i ++ )
		if( list[i] > list[i+1] )
			return 0;

	return 1;
}


/******************************************************************************
 *****************************************************************************/
void bst_t::check_valid_traversal_r( vector<int>* list, bst_node_t* root )
{
	if( !root )
		return;

	check_valid_traversal_r( list, root->n_left );
	list->push_back( root->n_item );
	check_valid_traversal_r( list, root->n_right );

	return;
}


/******************************************************************************
 *****************************************************************************/
int bst_t::check_valid_from_root( void )
{
	return check_valid_from_root_r( t_root, 0, INT_MAX );
}


/******************************************************************************
 *****************************************************************************/
int bst_t::check_valid_from_root_r( bst_node_t* node, int min, int max )
{
	if( !node )
		return 1;

	if( node->n_item > min && node->n_item < max )
		return( 
				check_valid_from_root_r( node->n_left, min, node->n_item ) &&
				check_valid_from_root_r( node->n_right, node->n_item, max ) );

	return 0;
}
