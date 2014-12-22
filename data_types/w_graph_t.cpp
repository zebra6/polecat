#include "w_graph_t.h"
#include <stdlib.h>			//
#include <stdio.h>			//printf
#include <assert.h>			//assert

/*connenecting edge
  struct w_edge_t
  {
  w_edge_t( w_node_t* a, w_node_t* b, float w );
  ~w_edge_t( void );
  short is_hanging( void );
  w_node_t* other( w_node_t* node );

  w_node_t* e_a;
  w_node_t* e_b;
  float e_w;
  }
 */

/******************************************************************************
 *****************************************************************************/
w_edge_t::w_edge_t( w_node_t* a, w_node_t* b, float w )
{
	assert( a && b );
	e_a = a;
	e_b = b;
	e_w = w;
}


/******************************************************************************
 *****************************************************************************/
w_edge_t::~w_edge_t( void )
{
	int i = 0;

	if( e_a )
		for( i = 0; i < e_a->n_edges.size(); i ++ )
			if( e_a->n_edges[i] == this )
				e_a->n_edges.erase( e_a->n_edges.begin() + i );

	if( e_b )
		for( i = 0; i < e_b->n_edges.size(); i ++ )
			if( e_b->n_edges[i] == this )
				e_b->n_edges.erase( e_b->n_edges.begin() + i );
}


/******************************************************************************
 *****************************************************************************/
void w_edge_t::print( void )
{
	if( e_a && e_b )
		printf( "a: %i, b: %i, w: %.1lf ", e_a->n_num, e_b->n_num, e_w );
	if( !e_a && e_b )
		printf( "a: null, b: %i, w: %.1lf ", e_b->n_num, e_w );
	if( e_a && !e_b )
		printf( "a: %i, b: null, w: %.1lf ", e_a->n_num, e_w );
	if( !e_a && !e_b )
		printf( "a: null, b: null, w: %.1lf ", e_w );

	return;
}


/******************************************************************************
 *****************************************************************************/
short w_edge_t::is_hanging( void )
{
	return ( !e_a || !e_b ) || ( !( e_a && e_b ) );
}


/******************************************************************************
 *****************************************************************************/
w_node_t* w_edge_t::other( w_node_t* node )
{
	if( node == e_a ) return e_b;
	if( node == e_b ) return e_a;
	return NULL;
}


/******************************************************************************
 *****************************************************************************/
void w_edge_t::remove_node( w_node_t* node )
{
	if( node == e_a ) e_a = NULL;
	else if( node == e_b ) e_b = NULL;

	return;
}


/*graph node
  struct w_node_t
  {
  w_node_t( void );
  ~w_node_t( void );

  void print( void );
  void remove_edge( w_edge_t* edge );

  int n_num;
  vector<w_edge_t*> n_edges;
  };
 */

/******************************************************************************
 *****************************************************************************/
w_node_t::w_node_t( int num )
{
	n_num = num;
}


/******************************************************************************
 *****************************************************************************/
w_node_t::~w_node_t( void )
{
	int i = 0;

	for( i = 0; i < n_edges.size(); i ++ )
	{
		//n_edges[i]->other( this )->remove_edge( n_edges[i] );
		delete n_edges[i];
	}
}


/******************************************************************************
 *****************************************************************************/
void w_node_t::print( void )
{
	int i = 0;
	printf( "%i: ", n_num );

	for( i = 0; i < n_edges.size(); i++ )
		n_edges[i]->print();

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
int w_node_t::remove_edge( w_edge_t* edge )
{
	int retv = 0;
	int i = 0;

	for( i = 0; i < n_edges.size(); i ++ )
		if( n_edges[i] == edge )
		{
			delete n_edges[i];
			n_edges.erase( n_edges.begin() + i );
			retv = 1;
			goto out;
		}

out:
	return retv;
}


/******************************************************************************
 *****************************************************************************/
w_graph_t::w_graph_t( void )
{
	g_num_v = 0;
	g_num_e = 0;
}


/******************************************************************************
 *****************************************************************************/
w_graph_t::~w_graph_t( void )
{
	int i = 0;

	for( i = 0; i < g_nodes.size(); i ++ )
		delete g_nodes[i];
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::print( void )
{
	int i = 0;
	printf( "graph %p\n", this );
	printf( "edges: %i\nverts: %i\n", g_num_e, g_num_v );

	for( i = 0; i < g_nodes.size(); i++ )
		g_nodes[i]->print();

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::create_random( int num_nodes, int num_edges, float min_w, float
		max_w )
{
	int i = 0;
	float w = 0.0f;
	w_node_t* node_1;
	w_node_t* node_2;

	/*create the nodes*/
	for( i = 0; i < num_nodes; i++ )
		insert_node();

	for( i = 0; i < num_edges; i++ )
	{
		node_1 = g_nodes[rand() % num_nodes];
		while( ( node_2 = g_nodes[rand() % num_nodes] ) == node_1 ) {};
		w = min_w + rand() / ( RAND_MAX / ( max_w - min_w ) );
		connect( node_1, node_2, w );
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::insert_node( void )
{
	w_node_t* tmp_node = new w_node_t( g_num_e++ );
	assert( tmp_node );

	g_nodes.push_back( tmp_node );

	return;
}


/******************************************************************************
 *****************************************************************************/
int w_graph_t::delete_node( int num )
{
	int i = 0;
	int retv = 0;

	for( i = 0; i < g_nodes.size(); i ++ )
		if( g_nodes[i]->n_num == num )
		{
			/*delete the node - will delete the edge*/
			delete g_nodes[i];
			g_nodes.erase( g_nodes.begin() + i );
			g_num_e--;
			retv = 1;
			goto out;
		}

out:
	return retv;
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::connect( w_node_t* a, w_node_t* b, float w )
{
	w_edge_t* new_edge = new w_edge_t( a, b, w );
	assert( new_edge );
	
	a->n_edges.push_back( new_edge );
	b->n_edges.push_back( new_edge );

	return;
}
