#pragma once
#include <vector>

using std::vector;

/*union find data structure****************************************************
 *****************************************************************************/
class uf_t
{
	public:
		uf_t( int sz );
		~uf_t( void );
		void print( void );

		int find( int p );
		void un( int p, int q );
		int connected( int p, int q );

		int get_count( void ) { return u_count; };

	private:
		int u_count;
		vector<int> u_data;
};
