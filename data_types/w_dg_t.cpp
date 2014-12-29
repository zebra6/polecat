#include "w_dg_t.h"		//
#include <stdio.h>		//
#include <stdlib.h>		//printf
#include <assert.h>		//assert
#include <float.h>		//FLX_MAX
#include <vector>		//priority queue
#include <queue>		//prority queue

using std::vector;
using std::priority_queue;
using std::greater;
using std::pair;


/******************************************************************************
 *****************************************************************************/
short floats_equal( float a, float b )
{
	return fabs( a - b ) < EPSILON;
}


/******************************************************************************
 *****************************************************************************/
w_de_t::w_de_t( w_dnode_t* from, w_dnode_t* to, float weight )
{
	e_from = from;
	e_to = to;
	e_weight = weight;
}


/******************************************************************************
 *****************************************************************************/
w_de_t::~w_de_t( void )
{
}


/******************************************************************************
 *****************************************************************************/
void w_de_t::print( void )
{
	if( e_from && e_to )
		printf( "%i-%i-%.2lf; ", e_from->n_num, e_to->n_num, e_weight );
	if( !e_from && e_to )
		printf( "null-%i, w: %.2lf ", e_to->n_num, e_weight );
	if( e_from && !e_to )
		printf( "%i-null, w: %.2lf ", e_from->n_num, e_weight );
	if( !e_from && !e_to )
		printf( "null-null, w: %.2lf ", e_weight );

	return;
}


/******************************************************************************
 *****************************************************************************/
void w_de_t::print_marked( void )
{
	if( e_marked )
	{
		if( e_from && e_to )
			printf( "%i-%i-%.2lf; ", e_from->n_num, e_to->n_num, e_weight );
		if( !e_from && e_to )
			printf( "null-%i, w: %.2lf ", e_to->n_num, e_weight );
		if( e_from && !e_to )
			printf( "%i-null, w: %.2lf ", e_from->n_num, e_weight );
		if( !e_from && !e_to )
			printf( "null-null, w: %.2lf ", e_weight );
	}

	return;
}


/*directed vertex**************************************************************
 *****************************************************************************/


/******************************************************************************
 *****************************************************************************/
w_dnode_t::w_dnode_t( int num )
{
	n_num = num;
}


/******************************************************************************
 *****************************************************************************/
w_dnode_t::~w_dnode_t( void )
{
	int i = 0;

	for( i = 0; i < n_edges.size(); i++ )
		n_edges[i]->e_from = NULL;
}


/******************************************************************************
 *****************************************************************************/
void w_dnode_t::print( void )
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
void w_dnode_t::print_marked( void )
{
	int i = 0;

	if( n_marked )
	{
		printf( "%i: ", n_num );
		for( i = 0; i < n_edges.size(); i++ )
			n_edges[i]->print_marked();

		printf( "\n" );
	}

	return;
}


/*weighted digraph*************************************************************
 *****************************************************************************/


/******************************************************************************
 *****************************************************************************/
w_dg_t::w_dg_t( void )
{
	g_num_n = 0;
	g_num_e = 0;	
}


/******************************************************************************
 *****************************************************************************/
w_dg_t::~w_dg_t( void )
{
	int i = 0;

	for( i = 0; i < g_nodes.size(); i++ )
		delete g_nodes[i];
	for( i = 0; i < g_edges.size(); i++ )
		delete g_edges[i];

	g_nodes.clear();
	g_edges.clear();
}


/******************************************************************************
 *****************************************************************************/
void w_dg_t::print( void )
{
	int i = 0;
	float weight = 0;

	for( i = 0; i < g_edges.size(); i++ )
		weight += g_edges[i]->e_weight;

	printf( "graph %p\n", this );
	printf( "edges: %i\nverts: %i\n", g_num_e, g_num_n );
	printf( "weight: %lf\n", weight );

	for( i = 0; i < g_nodes.size(); i++ )
		g_nodes[i]->print();

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void w_dg_t::print_marked( void )
{
	int i = 0;
	int marked_edges = 0;
	int marked_nodes = 0;
	float weight = 0;

	for( i = 0; i < g_edges.size(); i++ )
		if( g_edges[i]->e_marked )
		{
			weight += g_edges[i]->e_weight;
			marked_edges++;
		}

	for( i = 0; i < g_nodes.size(); i++ )
		if( g_nodes[i]->n_marked )
			marked_nodes++;

	printf( "graph %p\n", this );
	printf( "edges: %i\nnodes: %i\n", marked_edges, marked_nodes );
	printf( "weight: %lf\n", weight );

	for( i = 0; i < g_nodes.size(); i++ )
		g_nodes[i]->print_marked();

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void w_dg_t::create_random( int nodes, int edges, float min_w, float max_w )
{
	int i = 0;
	float w = 0.0f;
	w_dnode_t* node_1;
	w_dnode_t* node_2;

	/*create the nodes*/
	for( i = 0; i < nodes; i++ )
		insert_node();

	for( i = 0; i < edges; i++ )
	{
		node_1 = g_nodes[rand() % nodes];
		while( ( node_2 = g_nodes[rand() % nodes] ) == node_1 ) {};
		w = min_w + rand() / ( RAND_MAX / ( max_w - min_w ) );
		connect( node_1, node_2, w );
	}

	//remove_islands();
	return;
}


/******************************************************************************
 *****************************************************************************/
void w_dg_t::insert_node( void )
{
	w_dnode_t* new_node = new w_dnode_t( g_num_n++ );
	assert( new_node );
	g_nodes.push_back( new_node );

	return;
}


/******************************************************************************
 *****************************************************************************/
int w_dg_t::delete_node( int num )
{
	int retv = 0;
	int i = 0;
	int j = 0;

	for( i = 0; i < g_nodes.size(); i++ )
		if( g_nodes[i]->n_num == num )
		{
			/*delete the outbound edges*/
			g_num_n -= g_nodes[i]->n_edges.size();
			for( j = 0; j < g_nodes[i]->n_edges.size(); j++ )
				delete g_nodes[i]->n_edges[j];

			/*delete the node*/
			delete g_nodes[i];
			g_nodes.erase( g_nodes.begin() + i );
			g_num_n--;
			retv = 1;
			break;
		}

	return retv;
}


/******************************************************************************
 *****************************************************************************/
void w_dg_t::connect( w_dnode_t* from, w_dnode_t* to, float weight )
{
	w_de_t* new_edge = new w_de_t( from, to, weight );
	assert( new_edge );

	from->n_edges.push_back( new_edge );
	g_edges.push_back( new_edge );
	g_num_e++;
	return;
}


/******************************************************************************
 *****************************************************************************/
void w_dg_t::remove_islands( void )
{
	int i = 0;
	int j = 0;
	vector<int> stack;

	for( i = 0; i < g_nodes.size(); i++ )
		if( !g_nodes[i]->n_edges.size() )
		{
			for( j = 0; j < g_edges.size(); j++ )
				if( g_edges[j]->e_to == g_nodes[i] )
					break;
			stack.push_back( g_nodes[i]->n_num );
		}

	for( i = 0; i < stack.size(); i++ )
		delete_node( stack[i] );

	return;
}


/******************************************************************************
 *****************************************************************************/
void w_dg_t::clear_marks( void )
{
	int i = 0;

	for( i = 0; i < g_nodes.size(); i++ )
		g_nodes[i]->n_marked = 0;
	for( i = 0; i < g_edges.size(); i++ )
		g_edges[i]->e_marked = 0;

	return;
}


/******************************************************************************
 *****************************************************************************/
w_dnode_t* w_dg_t::get_node_from_num( int vtx_num )
{
	int i = 0;

	for( i = 0; i < g_nodes.size(); i++ )
		if( g_nodes[i]->n_num == vtx_num )
			break;

	if( i >= g_nodes.size() )
		return NULL;
	
	return g_nodes[i];
}


/******************************************************************************
 *****************************************************************************/
void w_dg_t::dij_shortest_paths( int src_num )
{
	int i = 0;
	int tmp_vnum = 0;
	float tmp_dist = 0.0f;
	w_dnode_t* tmp_node = NULL;
	priority_queue< float, vector<float>, greater<float> > pq;
	float* dist_ar = (float*)calloc( 1, sizeof(float) * g_num_n );
	w_de_t** edge_ar = (w_de_t**)calloc( 1, sizeof(w_de_t*) * g_num_n );

	/*initialize the distance array to the maximum value*/
	for( i = 0; i < g_num_n; i++ )
		dist_ar[i] = FLT_MAX;

	/*set the distance to the source array to 0*/
	dist_ar[src_num] = 0.0f;

	/*start iterating*/
	pq.push( dist_ar[src_num] );

	while( !pq.empty() )
	{
		tmp_dist = pq.top();
		pq.pop();

		/*in real life we would use a pair on the priority queue but this is
		 * simpler for here*/
		for( i = 0; i < g_num_n; i++ )
			if( floats_equal( tmp_dist, dist_ar[i] ) )
				break;

		if( i >= g_num_n )
		{
			printf( "error in distance array\n" );
			goto out;
		}

		tmp_vnum = i;

		tmp_node = get_node_from_num( i );
		assert( tmp_node );


		for( i = 0; i < tmp_node->n_edges.size(); i++ )
		{
			/*TODO finish this - some error accumulating due to representation
			 * differences*/
		}
	}

out:
	if( edge_ar ) free( edge_ar );
	if( dist_ar ) free( dist_ar );
	return;
}
