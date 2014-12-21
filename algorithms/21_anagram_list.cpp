/*
   Given a list of strings, return a list of lists of strings that groups all
   anagrams. 

   Ex. given {trees, bike, cars, steer, arcs} return { {cars, arcs}, {bike},
   {trees, steer} } 

   m = # of words n = length of longest word 

   I solved this in O(m * n * log n) time.


 */

#include <stdio.h> #include <stdlib.h> #include <vector> #include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::pair;
using std::sort;

vector< vector<string> > group_anagrams( vector<string> dic );

int main( int argc, char** argv )
{
	int i = 0;
	int j = 0;

	vector<string> dic;
	vector< vector<string> > lists;

	dic.push_back("cars");
	dic.push_back("arcs");
	dic.push_back("trees");
	dic.push_back("steer");
	dic.push_back("scar");
	dic.push_back("torn");
	dic.push_back("link");
	dic.push_back("kiln");

	lists = group_anagrams( dic );

	for( i = 0; i < lists.size(); i ++ )
	{
		for( j = 0; j < lists[i].size(); j ++ )
			printf( "%s, ", lists[i][j].c_str() );
		printf( "\n" );
	}

	printf( "\n" );
	return 0;
}


vector< vector<string> > group_anagrams( vector<string> dic )
{
	int i = 0;

	string tmp_str = "";
	pair< string, vector<string> > tmp_pair;
	vector<string> tmp_vec;

	vector< vector<string> > list;
	unordered_map< string, vector<string> > table;
	unordered_map< string, vector<string> >::iterator itr;

	for( i = 0; i < dic.size(); i ++ )
	{
		/*sort the work lexographically*/
		tmp_str = dic[i];
		sort( tmp_str.begin(), tmp_str.end() );

		/*see if it exists in the table already*/
		if( ( itr = table.find( tmp_str ) ) == table.end() )
		{
			/*add the original string to the vector*/
			tmp_vec.push_back( dic[i] );

			/*create a pair to add to the hash table*/
			tmp_pair.first = tmp_str;
			tmp_pair.second = tmp_vec;

			/*insert the pair into the hash table*/
			table.insert( tmp_pair );

			/*we are using real objects here, so clear the vector*/
			tmp_vec.clear();
		}
		else
		{
			/*otherwise add it to the existing vector*/
			itr->second.push_back( dic[i] );
		}
	}

	/*move them all over to the list*/
	for( itr = table.begin(); itr != table.end(); itr ++ )
		list.push_back( itr->second );

	return list;
}



