#pragma once
#include <math.h>		//fabs
#include <vector>

#define EPSILON 0.00001

using std::vector;

struct w_dnode_t;


/*float comparison, global*****************************************************
 *****************************************************************************/
short floats_equal( float a, float b );


/*directed weighted edge*******************************************************
 *****************************************************************************/
struct w_de_t
{
	w_de_t( w_dnode_t* from, w_dnode_t* to, float weight );
	~w_de_t( void );
	void print( void );
	void print_marked( void );

	w_dnode_t* e_from;
	w_dnode_t* e_to;
	float e_weight;
	int e_marked;
};


/*directed vertex**************************************************************
 *****************************************************************************/
struct w_dnode_t
{
	w_dnode_t( int num );
	~w_dnode_t( void );
	void print( void );
	void print_marked( void );

	int n_num;
	int n_marked;
	vector<w_de_t*> n_edges;
};


/*weighted digraph*************************************************************
 *****************************************************************************/
class w_dg_t
{
	public:
		w_dg_t( void );
		~w_dg_t( void );
		void print( void );
		void print_marked( void );

		void create_random( int nodes, int edges, float min_w, float max_w );
		void insert_node( void );
		int delete_node( int num );
		void connect( w_dnode_t* a, w_dnode_t* b, float w );
		void order_edges( void );
		void remove_islands( void );
		void clear_marks( void );
		w_dnode_t* get_node_from_num( int vtx_num );

		void dij_shortest_paths( int vtx_num );

	private:
		int g_num_e;
		int g_num_n;
		vector<w_de_t*> g_edges;
		vector<w_dnode_t*> g_nodes;
};

