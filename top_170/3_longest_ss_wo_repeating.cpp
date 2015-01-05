/*
   Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unordered_map>

using std::unordered_map;
using std::pair;

void longest_ss_naive( char* in );
int min( int a, int b ) { return ( a < b ) ? a : b; }
int max( int a, int b ) { return ( a > b ) ? a : b; }

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	char* in = argv[1];

	printf( "input: %s\n", in );
	longest_ss_naive( in );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void longest_ss_opt( char* in )
{
	/*int i = 0;
	int len = strlen( in );
	int cur_len = 1;
	int max_len = 1;
	int prev_index = 0;
	int* visited_ar = (int*)calloc( 1, sizeof(int) * len );

	for( i = 0; i < len; i++ )
		visited_ar[i] = -1;


	if( visited_ar ) free( visited_ar );*/
	return;
}


/******************************************************************************
 *****************************************************************************/
void longest_ss_naive( char* in )
{
	int i = 0;
	int len = strlen( in );
	int prefix = 0;
	int start = 0;
	unordered_map< char, int > table;
	unordered_map< char, int >::iterator itr;
	pair< char, int > tmp_pair;

	/*this runs in o^3 time*/
	for( i = 0; i < len; i++ )
	{
		if( table.find( in[i] ) == table.end() )
		{
			/*the character doesn't exist in the table*/
			tmp_pair.first = in[i];
			tmp_pair.second = i;
			table.insert( tmp_pair );
		}
		else
		{
			/*the character does exist, so find the max of the prefix or the
			 * current table size*/
			prefix = max( prefix, table.size() );

			/*now we get the last location where this character was found*/
			itr = table.find( in[i] );
			i = itr->second;

			/*keep track of this start index - need to add one because we don't
			 * get the iterator (doesn't work)*/
			//start = i+1;

			/*clear the table to start over*/
			table.clear();
		}
	}

	printf( "max: %i\n", max( prefix, table.size() ) );
	printf( "string: %s\n", in+start );

	return;
}
