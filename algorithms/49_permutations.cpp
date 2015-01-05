/*
this is just review mostly to cover the different ways of doing permutations,
combintaions, and subsets.
 */

#include <stdio.h>
#include <stdlib.h>

void perms_dfs_recursive( int* ar, int sz );
void perms_dfs_recursive_r( int* ar, int sz, int off );
void perms_prev_recursive( int* ar, int sz );
void perms_prev_recursive_r( int* ar, int sz, int off );

void swap( int* a, int* b );
void print_ar( int* ar, int sz );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int ar[] = { 1, 2, 3, 4 };

	perms_dfs_recursive( ar, 3 );
	perms_prev_recursive( ar, 3 );

	printf( "\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void perms_dfs_recursive( int* ar, int sz )
{
	/*recusive dfs implementation.  time complexity is o(n!), this uses the
	 * general backtracking algorithm outlined in skiena*/

	printf( "permutations, recursive dfs:\n" );
	perms_dfs_recursive_r( ar, sz, 0 );
	printf( "\n\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void perms_dfs_recursive_r( int* ar, int sz, int off )
{
	int i = 0;

	/*base case*/
	if( off >= sz )
	{
		print_ar( ar, sz );
		return;
	}

	/*otherwise swap*/
	for( i = off; i < sz; i++ )
	{
		swap( ar+off, ar+i );
		perms_dfs_recursive_r( ar, sz, off+1 );
		swap( ar+off, ar+i );
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void perms_prev_recursive( int* ar, int sz )
{
	/*recusive dfs implementation.  time complexity is o(n!), this uses the
	 * general backtracking algorithm outlined in skiena*/

	printf( "permutations, recursive from n-1:\n" );
	perms_prev_recursive_r( ar, sz, 0 );
	printf( "\n\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void perms_prev_recursive_r( int* ar, int sz, int off )
{

	/*TODO - figure this out*/
	/*http://rangerway.com/way/algorithm-permutation-combination-subset*/


	return;
}



/******************************************************************************
 *****************************************************************************/
void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}


/******************************************************************************
 *****************************************************************************/
void print_ar( int* ar, int sz )
{
	int i = 0;

	for( i = 0; i < sz; i++ )
		printf( "%i ", ar[i] );

	printf( "\n" );

	return;
}
