#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <limits.h>
/*
   There are N objects kept in a row. The ith object is at position x_i.
   You want to partition them into K groups. You want to move all objects
   belonging to the same group to the same position. Objects in two
   different groups may be placed at the same position. What is the
   minimum total amount by which you need to move the objects to
   accomplish this?

Input:
The first line contains the number of test cases T. T test cases
follow. The first line contains N and K. The next line contains N
space seperated integers, denoting the original positions x_i of the
objects.

Output:
Output T lines, containing the total minimum amount by which the
objects should be moved.

Constraints:
1 <= T <= 1000
1 <= K <= N <= 200
0 <= x_i <= 1000

Sample Input:
3
3 3
1 1 3
3 2
1 2 4
4 2
1 2 5 7

Sample Output:
0
1
3

Explanation:

For the first case, there is no need to move any object.
For the second case, group objects 1 and 2 together by moving the
first object to position 2.
For the third case, group objects 1 and 2 together by moving the first
object to position 2 and group objects 3 and 4 together by moving
object 3 to position 7. Thus the answer is 1 + 2 = 3.


 */

#define MNUM 16

int calc_dist( int* ar, int sz, int groups );
int dist_func( int* ar, int sz, int j );
int min( int a, int b );

/*this is a confusing question, it appears to be fisher's natural
 * breaks algorithm*/

int main( int argc, char** argv )
{
	int* ar = NULL;
	int i = 0;
	int n = 5;
	int k = 2;

	/*TODO fix this, the recurrence rlations is broken*/
	srand(time(NULL));
	ar = (int*)malloc( sizeof(int) * n );

	for( i = 0; i < n; i ++ )
		ar[i] = ( rand() % MNUM ) + 1;

	printf( "n: %i\nk: %i\n", n, k );
	for( i = 0; i < n; i ++ )
		printf( "%i ", ar[i] );
	printf( "\n" );

	printf( "min moves: %i\n\n", calc_dist( ar, n, k ) );


	if( ar ) free( ar );
	return 0;
}


int dist_func( int* ar, int sz, int j )
{
	double mean = 0;
	int near = INT_MAX;
	int near_loc = 0;
	int i = 0;
	int sum = 0;

	/*calculate the mean*/
	for( i = 0; i < j; i ++ )
		mean += ar[sz-i-1];

	mean /= j;

	/*here we find the closest value to the mean*/
	for( i = 0; i < j; i ++ )
		if( abs( ar[sz-i-1] - (int)mean ) < near )
		{
			near = abs( ar[sz-i-1] - (int)mean );
			near_loc = i;
		}

	for( i = 0; i < j; i ++ )
		sum += abs( ar[sz-i-1] - ar[sz-near_loc-1] );

	return sum;			
}


int calc_dist( int* ar, int sz, int groups )
{
	int min_1 = INT_MAX;
	int i = 1;

	/*base cases*/
	if( groups < 1 ) return min_1;
	if( sz < 0 ) return 0;
	if( sz <= groups ) return 0;

	if( groups > 1 )
		min_1 = calc_dist( ar, sz-1, groups-1 );
	else
		min_1 = calc_dist( ar, sz, sz );

	if( groups > 1 )
		for( i = 1; i <= sz-groups; i ++ )
			min_1 = min(
					min_1,
					calc_dist( ar, sz-i, groups-1) + dist_func( ar, sz, i )
					);

	return min_1;
}


int min( int a, int b )
{
	return ( a < b ) ? a : b;
}
