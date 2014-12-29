#pragma once

#include <vector>
#include <queue>			//for minimum spanning tree

using std::vector;
using std::priority_queue;

struct w_node_t;

/*connenecting edge************************************************************
 *****************************************************************************/
struct w_edge_t
{
	w_edge_t( w_node_t* a, w_node_t* b, float w );
	~w_edge_t( void );
	void print( void );
	void print_marked( void );

	short is_hanging( void );
	w_node_t* other( w_node_t* node );
	void remove_node( w_node_t* node );
	void order( void );

	int e_marked;
	w_node_t* e_a;
	w_node_t* e_b;
	float e_w;
};


/*comparator for the priority queue********************************************
 *****************************************************************************/
class compare_edge
{
	public:
		bool operator()( w_edge_t* a, w_edge_t* b )
		{
			if( a->e_w < b->e_w ) return false;
			else return true;
		}
};


/*graph node*******************************************************************
 *****************************************************************************/
struct w_node_t
{
	w_node_t( int num );
	~w_node_t( void );
	void print( void );
	void print_marked( void );

	int remove_edge( w_edge_t* edge );
	void remove_hanging( w_edge_t* edge );
	void order_edges( void );

	int n_num;
	int n_marked;
	vector<w_edge_t*> n_edges;
};


/*graph itself*****************************************************************
 *****************************************************************************/
class w_graph_t
{
	public:
		w_graph_t( void );
		~w_graph_t( void );
		void print( void );
		void print_marked( void );

		void create_random( int nodes, int edges, float min_w, float max_w );
		void insert_node( void );
		int delete_node( int num );
		void connect( w_node_t* a, w_node_t* b, float w );
		void order_edges( void );
		void remove_islands( void );
		void clear_marks( void );

		void mst_prim_lazy( void );
		void mst_kruskal( void );
		void visit(
				w_node_t* node,
				priority_queue< w_edge_t*, vector<w_edge_t*>, compare_edge >* pq );

	private:
		int g_num_n;
		int g_num_e;
		vector<w_node_t*> g_nodes;
		vector<w_edge_t*> g_edges;

};
