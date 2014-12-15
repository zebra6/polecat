#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;
using std::pair;

/*
Prints all unique subsets of the string.
Given a string write a function which prints all the subsets of the string. Now
make the function to return only unique solutions.
 */

void gen_subsets( char* str );
void print_unique( vector<string>* list );

int main( int argc, char** argv )
{
	char* str = argv[1];

	assert( argc == 2 );

	printf( "input string: %s\n", str );
	gen_subsets( str );

	return 0;
}

void gen_subsets( char* str )
{
	int len = strlen( str );
	double set_size = pow( 2, len );
	int i = 0;
	int j = 0;
	vector<string> list;
	string to_add = "";

	for( i = 0; i < set_size; i ++ )
	{
		for( j = 0; j < len; j ++ )
			if( i & 1 << j )
				to_add += str[j];

		list.push_back( to_add );
		to_add = "";
	}

	print_unique( &list );
	return;
}


void print_unique( vector<string>* list )
{
	unordered_map<string, int> table;
	unordered_map<string, int>::iterator tbl_itr;
	vector<string>::iterator vec_itr = list->begin();
	pair<string, int> p; 

	for( ; vec_itr != list->end(); vec_itr++ )
	{
		tbl_itr = table.find( *vec_itr );
		if( tbl_itr == table.end() )
		{
			p.first = *vec_itr;
			p.second = 0;
			table.insert( p );
		}
	}

	for( tbl_itr = table.begin(); tbl_itr != table.end(); tbl_itr ++ )
		printf( "%s\n", tbl_itr->first.c_str() );

	return;
}
