#include "w_graph_t.h"
#include "uf_t.h"		//union find for kruskal
#include <stdlib.h>		//
#include <stdio.h>		//printf
#include <assert.h>		//assert
#include <float.h>		//FLT_MAX
#include <vector>		//node lists, etc
#include <queue>		//for minimum spanning tree

using std::vector;
using std::priority_queue;


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
}


/******************************************************************************
 *****************************************************************************/
void w_edge_t::print( void )
{
	if( e_a && e_b )
		printf( "%i-%i-%.2lf; ", e_a->n_num, e_b->n_num, e_w );
	if( !e_a && e_b )
		printf( "null-%i, w: %.2lf ", e_b->n_num, e_w );
	if( e_a && !e_b )
		printf( "%i-null, w: %.2lf ", e_a->n_num, e_w );
	if( !e_a && !e_b )
		printf( "null-null, w: %.2lf ", e_w );

	return;
}


/******************************************************************************
 *****************************************************************************/
void w_edge_t::print_marked( void )
{
	if( e_marked )
	{
		if( e_a && e_b )
			printf( "%i-%i-%.2lf; ", e_a->n_num, e_b->n_num, e_w );
		if( !e_a && e_b )
			printf( "null-%i, w: %.2lf ", e_b->n_num, e_w );
		if( e_a && !e_b )
			printf( "%i-null, w: %.2lf ", e_a->n_num, e_w );
		if( !e_a && !e_b )
			printf( "null-null, w: %.2lf ", e_w );
	}

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


/******************************************************************************
 *****************************************************************************/
void w_edge_t::order( void )
{
	w_node_t* tmp = e_a;

	if( e_a->n_num > e_b->n_num )
	{
		e_a = e_b;
		e_b = tmp;
	}

	return;
}


/******************************************************************************
  ==========================================================================
 *****************************************************************************/


/******************************************************************************
 *****************************************************************************/
w_node_t::w_node_t( int num )
{
	n_num = num;
	n_marked = 0;
}


/******************************************************************************
 *****************************************************************************/
w_node_t::~w_node_t( void )
{
	while( n_edges.size() )
		remove_edge( n_edges[0] );
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
void w_node_t::print_marked( void )
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


/******************************************************************************
 *****************************************************************************/
int w_node_t::remove_edge( w_edge_t* edge )
{
	int retv = 0;
	int i = 0;

	for( i = 0; i < n_edges.size(); i ++ )
		if( n_edges[i] == edge )
		{
			/*this takes care of erasing the pointer in the other node*/
			n_edges[i]->other( this )->remove_hanging( edge );
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
void w_node_t::remove_hanging( w_edge_t* edge )
{
	int i = 0;
	assert( edge );

	for( i = 0; i < n_edges.size(); i ++ )
		if( n_edges[i] == edge )
		{
			n_edges.erase( n_edges.begin() + i );
			break;
		}

	return;
}


/******************************************************************************
 *****************************************************************************/
void w_node_t::order_edges( void )
{
	int i = 0;
	for( i = 0; i < n_edges.size(); i++ )
		n_edges[i]->order();

	return;
}


/******************************************************************************
  ==========================================================================
 *****************************************************************************/


/******************************************************************************
 *****************************************************************************/
w_graph_t::w_graph_t( void )
{
	g_num_n = 0;
	g_num_e = 0;
}


/******************************************************************************
 *****************************************************************************/
w_graph_t::~w_graph_t( void )
{
	while( g_nodes.size() )
	{
		delete g_nodes[0];
		g_nodes.erase( g_nodes.begin() );
	}
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::print( void )
{
	int i = 0;
	float weight = 0;

	for( i = 0; i < g_edges.size(); i++ )
		weight += g_edges[i]->e_w;

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
void w_graph_t::print_marked( void )
{
	int i = 0;
	int marked_edges = 0;
	int marked_nodes = 0;
	float weight = 0;

	for( i = 0; i < g_edges.size(); i++ )
		if( g_edges[i]->e_marked )
		{
			weight += g_edges[i]->e_w ;
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

	order_edges();
	remove_islands();

	return;
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::insert_node( void )
{
	w_node_t* tmp_node = new w_node_t( g_num_n++ );
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
			g_num_e -= g_nodes[i]->n_edges.size();
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
void w_graph_t::connect( w_node_t* a, w_node_t* b, float w )
{
	w_edge_t* new_edge = new w_edge_t( a, b, w );
	assert( new_edge );

	a->n_edges.push_back( new_edge );
	b->n_edges.push_back( new_edge );
	g_edges.push_back( new_edge );

	g_num_e++;

	return;
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::order_edges( void )
{
	int i = 0;
	for( i = 0; i < g_nodes.size(); i++ )
		g_nodes[i]->order_edges();
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::remove_islands( void )
{
	int i = 0;
	vector<int> stack;

	for( i = 0; i < g_nodes.size(); i++ )
		if( !g_nodes[i]->n_edges.size() )
			stack.push_back( g_nodes[i]->n_num );

	for( i = 0; i < stack.size(); i ++ )
		delete_node( stack[i] );

	return;
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::clear_marks( void )
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
void w_graph_t::mst_prim_lazy( void )
{
	w_node_t* tmp_n1 = NULL;
	w_node_t* tmp_n2 = NULL;
	w_edge_t* tmp_edge = NULL;
	priority_queue< w_edge_t*, vector<w_edge_t*>, compare_edge > pq;

	/*make sure we have nodes in the list*/
	if( !g_nodes.size() )
		return;

	/*clear out*/
	clear_marks();

	/*add the initial node to the pq*/
	visit( g_nodes[0], &pq );

	while( !pq.empty() )
	{
		/*get the minimum edge*/
		tmp_edge = pq.top();
		pq.pop();

		/*get the nodes from the edge*/
		tmp_n1 = tmp_edge->e_a;
		tmp_n2 = tmp_edge->e_b;

		/*only continue if one of the edges in unmarked*/
		if( !tmp_n1->n_marked || !tmp_n2->n_marked )
		{
			/*we found a valid edge, so mark it*/
			tmp_edge->e_marked = 1;

			/*now check the connected nodes*/
			if( !tmp_n1->n_marked )
				visit( tmp_n1, &pq );
			if( !tmp_n2->n_marked )
				visit( tmp_n2, &pq );
		}
	}

	printf( "lazy prim mst:\n" );
	print_marked();

	return;
}


/******************************************************************************
 *****************************************************************************/
void w_graph_t::mst_kruskal( void )
{
	int i = 0;
	int marked = 0;
	w_node_t* tmp_node1 = NULL;
	w_node_t* tmp_node2 = NULL;
	w_edge_t* tmp_edge = NULL;
	uf_t uf( g_num_n );
	priority_queue< w_edge_t*, vector<w_edge_t*>, compare_edge > pq;

	/*make sure we have nodes in the list*/
	if( !g_nodes.size() )
		return;

	/*clear out*/
	clear_marks();

	/*add all the edges to the priority queue*/
	for( i = 0; i < g_edges.size(); i++ )
		pq.push( g_edges[i] );

	while( !pq.empty() && marked < g_nodes.size() - 1 )
	{
		tmp_edge = pq.top();
		pq.pop();

		tmp_node1 = tmp_edge->e_a;
		tmp_node2 = tmp_edge->e_b;

		/*only continue with unconnected edges*/
		if( !uf.connected( tmp_node1->n_num, tmp_node2->n_num ) )
		{
			uf.un( tmp_node1->n_num, tmp_node2->n_num );
			tmp_node1->n_marked = 1;
			tmp_node2->n_marked = 1;
			tmp_edge->e_marked = 1;
			marked++;
		}
	}

	printf( "kruskal mst:\n" );
	uf.print();
	print_marked();

	return;
}

/******************************************************************************
 *****************************************************************************/
void w_graph_t::visit(
		w_node_t* node,
		priority_queue< w_edge_t*, vector<w_edge_t*>, compare_edge >* pq )
{
	int i = 0;

	/*mark the node*/
	node->n_marked = 1;

	/*add its edges to the pq*/
	for( i = 0; i < node->n_edges.size(); i++ )
		if( !node->n_edges[i]->other( node )->n_marked )
			pq->push( node->n_edges[i] );

	return;
}
