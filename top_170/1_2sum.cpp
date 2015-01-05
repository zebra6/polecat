/*
   Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>

#define MAX 16
#define NUM 10

using std::vector;
using std::sort;

void two_sum( vector<int> ar, int target );


/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	vector<int> ar;
	srand(time(NULL));

	printf( "input array: " );

	for( i = 0; i < MAX; i++ )
		ar.push_back( rand() % NUM );
	
	sort( ar.begin(), ar.end() );

	for( i = 0; i < MAX; i++ )
		printf( "%i ", ar[i] );


	printf( "\n" );
	two_sum( ar, rand() % MAX );
	printf( "\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void two_sum( vector<int> ar, int target )
{
	int l = 0;
	int r = ar.size() - 1;

	printf( "2sum %i:\n", target );

	/*this will not return all possible solutions, the algorithm for that is
	 * much more complicated*/

	while( l < r )
	{
		if( ar[l] + ar[r] == target )
		{
			printf( "%i + %i = %i\n", ar[l], ar[r], target );
			l++;
			r--;
		}
		else if( ar[l] + ar[r] < target )
			l++;
		else
			r--;
	}

	return;
}
