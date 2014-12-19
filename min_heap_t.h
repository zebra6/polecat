#pragma once

class min_heap_t
{
	public:
		min_heap_t( int sz );
		~min_heap_t( void );

		void print_ext();
		void print_ar();
		void print_levels();

		void insert( int val );
		int min( void ) { return h_ar[0]; };
		int delmin( void );
		short exists( int val );
		int size( void ) { return h_num_elements; };

	private:
		void bubble_up( int off );
		void bubble_down( int off );
		void swap( int* a, int* b );

		int* h_ar;
		int h_ar_sz;
		int h_num_elements;
};
