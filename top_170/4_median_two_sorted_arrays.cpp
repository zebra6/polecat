/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 
 http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <vector>
#include <algorithm>

#define MAX 32
#define SZ 16

using std::vector;
using std::sort;

void print_vec_ar( vector<int> vec );
void find_median_naive( vector<int> a, vector<int> b );
void find_median_opt( vector<int> a, vector<int> b );
int find_median_opt_r( vector<int> a, vector<int> b, int l, int r );
int median( int* ar, int sz );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	vector<int> a;
	vector<int> b;
	srand(time(NULL));

	for( i = 0; i < SZ; i++ )
	{
		a.push_back( rand() % MAX );
		b.push_back( rand() % MAX );
	}

	sort( a.begin(), a.end() );
	sort( b.begin(), b.end() );

	printf( "vector a: " );
	print_vec_ar( a );
	printf( "\n" );
	printf( "vector b: " );
	print_vec_ar( b );
	printf( "\n" );
	find_median_naive( a, b );
	find_median_opt( a, b );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void print_vec_ar( vector<int> vec )
{
	int i = 0;

	for( i = 0; i < vec.size(); i++ )
		printf( "%4i", vec[i] );

	return;
}


/******************************************************************************
 *****************************************************************************/
void find_median_naive( vector<int> a, vector<int> b )
{
	int i = 0;
	int j = 0;
	int count = 0;
	int len = a.size();
	int med_1 = 0;
	int med_2 = 0;

	assert( a.size() == b.size() );

	/*this runs in o(n)*/

	/*it is possible the median can be the first element in the second array, so
	 * we use <= n*/
	for( count = 0; count <= len; count++ )
	{
		/*this is the case when all the elements in a are less than those in b*/
		if( i == len )
		{
			med_1 = med_2;
			med_2 = b[0];
			break;
		}

		/*opposite of above, all elements of b are less than a*/
		if( j == len )
		{
			med_1 = med_2;
			med_2 = a[0];
			break;
		}

		/*otherwise simple merge operation*/
		if( a[i] < b[j] )
		{
			/*store the previous median*/
			med_1 = med_2;
			med_2 = a[i++];
		}
		else
		{
			med_1 = med_2;
			med_2 = b[j++];
		}
	}
	
	printf( "median naive: %i\n", ( med_1 + med_2 ) / 2 );

	return;
}


/******************************************************************************
 *****************************************************************************/
void find_median_opt( vector<int> a, vector<int> b )
{
	printf( "median optimal: %i\n",
			find_median_opt_r( a, b, 0, a.size() - 1 ) );

	return;
}


/******************************************************************************
 *****************************************************************************/
int find_median_opt_r( vector<int> a, vector<int> b, int l, int r )
{
	int mid = ( l + r ) / 2;
	int b_off = a.size() - mid - 1;

	/*this will not work for repeated elements*/

	/*base case, the indexes are off - switch to the second array*/
	if( l > r )
		return find_median_opt_r( b, a, 0, a.size()-1 );

	/*base case, we have found the median*/
	if( a[mid] > b[b_off] && ( b_off == b.size()-1 || a[mid] <= b[b_off-1] ) )
	{
		/*a[mid] is the first median, now to find the second one*/
		if( mid == 0 || b[b_off] > a[mid-1] )
			return ( ( a[mid] + b[b_off] ) / 2 );
		else
			return ( ( a[mid] + a[mid-1] ) / 2 );
	}

	/*otherwise recurse - mid is in the left half*/
	if( a[mid] > b[b_off] && b_off != b.size()-1 && a[mid] > b[b_off+1] )
		return find_median_opt_r( a, b, l, mid-1 );
	else
		return find_median_opt_r( a, b, mid+1, r );
}


/******************************************************************************
 *****************************************************************************/
int median( int* ar, int sz )
{
	/*even number of elements, return the average*/
	if( !sz % 2 )
		return( ar[sz/2] + ar[(sz/2)-1] ) / 2;
	else
		return( ar[sz/2] );
}
