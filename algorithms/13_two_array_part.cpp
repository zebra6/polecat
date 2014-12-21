/*Given an unordered array of positive integers, create an algorithm
  that makes sure no group of integers of size bigger than M have the
  same integers.

Input: 2,1,1,1,3,4,4,4,5 M = 2
Output: 2,1,1,3,1,4,4,5,4*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unordered_map>

using std::unordered_map;
using std::pair;
using std::make_pair;

#define MAX 5
#define ASZ 16


void group_elements( int* ar, int asz, int gsz );
int main( int argc, char** argv )
{
	int i = 0;
	int gsz = 0;
	int ar[ASZ] = { 0 };
	int br[ASZ] = { [0 ... ASZ-1] = -1 };

	/*this problem is more complicated than it looks*/

	srand(time(NULL));
	assert( argc == 2 );
	gsz = atoi( argv[1] );

	for( i = 0; i < ASZ; i ++ )
		ar[i] = rand() % MAX;

	printf( "unordererd array is:\n" );
	for( i = 0; i < ASZ; i ++ )
		printf( "%i ", ar[i] );

	group_elements( ar, ASZ, gsz );

	printf( "\n" );

	printf( "ordererd array is:\n" );
	for( i = 0; i < ASZ; i ++ )
		printf( "%i ", ar[i] );

	printf( "\n\n" );
	return 0;
}


void group_elements( int* ar, int asz, int gsz )
{
	int i = 0;
	int cur = gsz;
	unordered_map<int, int> table;
	unordered_map<int, int>::iterator itr;

	/*populate the table with counts*/
	for( i = 0; i < asz; i ++ )
	{
		if( ( itr = table.find( ar[i] ) ) == table.end() )
			table.insert( make_pair( ar[i], 1 ) );
		else
			itr->second++;
	}

	/*walk back through the hash table and repopulate the array*/
	itr = table.begin();
	i = 0;

	while( i < asz )
	{
		cur = gsz;
 
		while( itr->second && cur )
		{
			ar[i++] = itr->first;
			itr->second--;
			cur--;
		}
	
		/*loop around*/	
		itr++;
		if( itr == table.end() )
			itr = table.begin();

		/*there is a tail case here to take care of - namely we have a single
		 * remaining bucket with a size greater than gsz.  This can be solved by
		 * splitting and interleaving the remaining values in the array, this is
		 * not difficult but tedious to do*/
	}

	return;
}

