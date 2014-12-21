
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <vector>

using std::vector;

void find_missing( int* ar, int num, int missing );
void find_missing_r( int* ar, vector<int>* list, int start, int end );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int ar[] = { 1, 3, 4, 5, 6, 8, 9, 10, 11, 13 };

	find_missing( ar, 10, 3 );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void find_missing( int* ar, int num, int missing )
{
	vector<int>* list = new vector<int>;
	vector<int>::iterator itr;

	assert( list );
	find_missing_r( ar, list, 0, num-1 );

	for( itr = list->begin(); itr != list->end(); itr++ )
		printf( "%i ", *itr );
	printf( "\n" );

	if( list ) delete list;
	return;
}


/******************************************************************************
 *****************************************************************************/
void find_missing_r( int* ar, vector<int>* list, int start, int end )
{
	int mid = ( start + end ) / 2; 

	if( start == end )
		return;
	if( ar[end] - ar[start] == end - start )
		return;

	if( start + 1 == end )
	{
		list->push_back( ar[start] + 1 );
		return;
	}

	find_missing_r( ar, list, start, mid );
	find_missing_r( ar, list, mid, end );

	return;
}


