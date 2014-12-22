#pragma once
#include <vector>

using std::vector;

struct w_node_t;

/*connenecting edge*/
struct w_edge_t
{
	w_edge_t( w_node_t* a, w_node_t* b, float w );
	~w_edge_t( void );
	
	void print( void );
	short is_hanging( void );
	w_node_t* other( w_node_t* node );
	void remove_node( w_node_t* node );

	w_node_t* e_a;
	w_node_t* e_b;
	float e_w;
};


/*graph node*/
struct w_node_t
{
	w_node_t( int num );
	~w_node_t( void );
	
	void print( void );
	int remove_edge( w_edge_t* edge );

	int n_num;
	vector<w_edge_t*> n_edges;
};


/*graph itself*/
class w_graph_t
{
	public:
		w_graph_t( void );
		~w_graph_t( void );

		void print( void );
		void create_random( int num_nodes, int num_edges, float min_w, float
				max_w );
		void insert_node( void );
		int delete_node( int num );
		void connect( w_node_t* a, w_node_t* b, float w );
		
	private:
		int g_num_v;
		int g_num_e;
		vector<w_node_t*> g_nodes;

};
