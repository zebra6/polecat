/*
   maximum submatrix sum in a 2d array
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RSZ 2
#define CSZ 2
#define MAX 10

void print_ar( int ar[RSZ][CSZ], int rsz, int csz ); 
void find_largest_r( int ar[RSZ][CSZ], int rsz, int csz );
void find_largest_r2( int ar[RSZ][CSZ], int rsz, int csz, int rstart, int rend,
		int cstart, int cend, int* max );
void find_largest_i( int ar[RSZ][CSZ], int rsz, int csz );
int kadane_sum( int* ar, int* start, int* end, int sz );


/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int j = 0;
	int m1[RSZ][CSZ] = { { 0 } };

	srand(time(NULL));

	for( i = 0; i < RSZ; i++ )
		for( j = 0; j < CSZ; j++ )
		{
			m1[i][j] = rand() % MAX;
			if( rand() % 2 )
				m1[i][j] *= -1;
		}

	printf( "input array:\n" );
	print_ar( m1, RSZ, CSZ );
	find_largest_r( m1, RSZ, CSZ );
	printf( "\n" );
	find_largest_i( m1, RSZ, CSZ );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void print_ar( int ar[RSZ][CSZ], int rsz, int csz )
{
	int i = 0;
	int j = 0;

	for( i = 0; i < csz; i++ )
	{
		for( j = 0; j < rsz; j++ )
			printf( "%5i", ar[i][j] );
		printf( "\n" );
	}

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void find_largest_r( int ar[RSZ][CSZ], int rsz, int csz )
{
	int max = 0;

	find_largest_r2( ar, rsz, csz, 0, 0, 0, 0, &max );

	printf( "largest submatrix: %i\n", max );
	return;
}


/******************************************************************************
 *****************************************************************************/
void find_largest_r2( int ar[RSZ][CSZ], int rsz, int csz, int rstart, int rend,
		int cstart, int cend, int* max )
{
	int i = 0;
	int j = 0;
	int local_max = 0;

	if( rend >= rsz || cend >= csz )
		return;
	if( rstart > rend || cstart > cend )
		return;

	for( i = rstart; i <= rend; i++ )
		for( j = cstart; j <= cend; j++ )
			local_max += ar[i][j];

	if( local_max > *max )
	{
		printf( "new max at (%i,%i), (%i,%i) - %i\n",
				cstart, rstart, cend, rend, local_max );
		*max = local_max;
	}

	find_largest_r2( ar, rsz, csz, rstart+1, rend, cstart, cend, max );
	find_largest_r2( ar, rsz, csz, rstart, rend+1, cstart, cend, max );
	find_largest_r2( ar, rsz, csz, rstart, rend, cstart+1, cend, max );
	find_largest_r2( ar, rsz, csz, rstart, rend, cstart, cend+1, max );

	return;
}


/******************************************************************************
  implement using kadane's alrogithm, o(n^3)
 *****************************************************************************/
void find_largest_i( int ar[RSZ][CSZ], int rsz, int csz )
{
	int i = 0;
	int sum = 0;
	int max_sum = 0;
	int f_top = 0;
	int f_bottom = 0;
	int f_left = 0;
	int f_right = 0;
	int left = 0;
	int right = 0;
	int start = 0;
	int finish = 0;
	int tmp_ar[RSZ] = { 0 };

	/*this essentially creates a column vector to scan through, not currently
	 * working properly*/

	/*start scanning through columns*/
	for( left = 0; left < csz; left++ )
	{
		/*reset temporary array to zero*/
		memset( tmp_ar, 0, sizeof(int) * RSZ );

		/*select the right column to sweep through*/
		for( right = left; right < csz; right++ )
		{
			/*copy the current row into the tmp array*/
			tmp_ar[i] += ar[i][right];

			/*find the sum for this column vector*/
			sum = kadane_sum( tmp_ar, &start, &finish, rsz );

			/*compare and update offsets*/
			if( sum > max_sum )
			{
				max_sum = sum;
				f_left = left;
				f_right = right;
				f_top = start;
				f_bottom = finish;
			}
		}
	}

	printf( "largest submatrix (iterative): %i\n",sum );
	printf( "locations: (%i,%i), (%i,%i)\n",
			f_left, f_top, f_right, f_bottom );

	return;
}


/******************************************************************************
 *****************************************************************************/
int kadane_sum( int* ar, int* start, int* end, int sz )
{
	int i = 0;
	int max_sum = 0;
	int local_sum = 0;
	int local_start = 0;

	/*initialize end to an invalid value*/
	*end = -1;

	/*find the values*/
	for( i = 0; i < sz; i++ )
	{
		local_sum += ar[i];

		if( local_sum > max_sum )
		{
			max_sum = local_sum;
			*start = local_start;
			*end = i;
		}
		else if( local_sum < 0 )
		{
			max_sum = 0;
			*start = i+1;
		}
	}

	/*check if all array elements are zero*/
	if( *end == -1 )
	{
		*start = 0;
		*end = 0;
		max_sum = ar[0];

		/*just find the most-positive negative number*/
		for( i = 0; i < sz; i ++ )
			if( ar[i] > max_sum )
			{
				*start = i;
				*end = i;
				max_sum = ar[i];
			}
	}

	return max_sum;
}
