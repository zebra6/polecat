#pragma once

#include <vector>		//level traversal prototype

using std::vector;

struct bst_node_t
{
	bst_node_t( void );
	~bst_node_t( void );

	/*parent is optional*/
	bst_node_t* n_parent;
	bst_node_t* n_left;
	bst_node_t* n_right;
	int n_item;
};

class bst_t
{
	public:
		/*basic methods*/
		bst_t( void );
		~bst_t( void );
		void populate_random( int num, int min, int max );

		int insert( int val );
		bst_node_t* insert_r( int val, bst_node_t* node );
		int remove( int val );
		int exists( int val );
		int exists_r( int val, bst_node_t* node );
		int height( void );
		int height_r( bst_node_t* n );
		int locmax( int a, int b ) { return ( a > b ) ? a : b; };

		/*traversal methods*/
		void preorder( void );
		void preorder_r( bst_node_t* node );
		void inorder( void );
		void inorder_r( bst_node_t* node );
		void postorder( void );
		void postorder_r( bst_node_t* node );
		void level_traverse( void );
		void level_traverse_r( vector< vector<int> >*, bst_node_t*, int );
		void level_traverse_queue( void );

		/*advanced methods*/
		void zero_sink( void );
		int check_valid_traversal( void );
		void check_valid_traversal_r( vector<int>* list, bst_node_t* root );
		int check_valid_from_root( void );
		int check_valid_from_root_r( bst_node_t* node, int min, int max	);

	private:
		/*attribs*/
		bst_node_t* t_root;
};
