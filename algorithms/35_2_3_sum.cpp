#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <algorithm>

#define SZ 8
#define MAX 8

using std::vector;
using std::sort;

void find_2sum( vector<int> ar, int sum );
void find_3sum( vector<int> ar, int sum );


/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	vector<int> list;
	srand(time(NULL));

	for( i = 0; i < MAX; i ++ )
		list.push_back( rand() % MAX );

	sort( list.begin(), list.end() );

	printf( "list: " );
	for( i = 0; i != list.size(); i++ )
		printf( "%2i ", list[i] );
	printf( "\n" );

	find_2sum( list, rand() % MAX );
	find_3sum( list, rand() % MAX );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void find_2sum( vector<int> list, int sum )
{
	int l = 0;
	int r = list.size() - 1;

	printf( "2sum %i:\n", sum );

	while( l < r )
	{
		if( list[l] + list[r] == sum )
			printf( "%i+%i=%i\n", list[l++], list[r--], sum );

		else if( list[l] + list[r] < sum )
			l++;
		else
			r--;
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void find_3sum( vector<int> list, int sum )
{
	int i = 0;
	int l = 0;
	int r = list.size() - 1;

	printf( "3sum %i:\n", sum );

	for( i = 0; i < list.size() - 2; i++ )
	{
		l = i + 1;
		r = list.size() - 1;
		while( l < r )
		{
			if( list[i] + list[l] + list[r] == sum )
				printf( "%i+%i+%i=%i\n", list[i], list[l++], list[r--], sum );

			else if( list[i] + list[l] + list[r] < sum )
				l++;
			else
				r--;
		}
	}

	return;
}
