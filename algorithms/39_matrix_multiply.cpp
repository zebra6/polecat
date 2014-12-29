/*
	multiplcation of 2d arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RSZ 2
#define CSZ 2
#define MAX 10

void print_ar( int ar[][CSZ], int rsz, int csz ); 
void mult_ar_square( int m1[][CSZ], int m2[][CSZ], int ans[][CSZ], int rsz, int
		csz );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int j = 0;

	int m1[RSZ][CSZ] = { { 0 } };
	int m2[RSZ][CSZ] = { { 0 } };
	int ans[RSZ][CSZ] = { { 0 } };

	srand(time(NULL));

	for( i = 0; i < RSZ; i++ )
		for( j = 0; j < CSZ; j++ )
		{
			m1[i][j] = rand() % MAX;
			m2[i][j] = rand() % MAX;
		}

	printf( "input arrays:\n" );
	print_ar( m1, RSZ, CSZ );
	print_ar( m2, RSZ, CSZ );

	mult_ar_square( m1, m2, ans, RSZ, CSZ );
	printf( "square answer\n" );
	print_ar( ans, RSZ, CSZ );	

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void print_ar( int ar[][CSZ], int rsz, int csz )
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
void mult_ar_square( int m1[][CSZ], int m2[][CSZ], int ans[][CSZ], int rsz, int
		csz )
{
	int i = 0;
	int j = 0;
	int k = 0;

	/*rsz and csz here are equal, if not they would need to be passed as
	 * individual paramemeter for m1 and m2*/
	if( rsz != csz )
	{
		printf( "not square matrix\n" );
		return;
	}

	/*first loop is based on m1 col size - same as below*/
	for( i = 0; i < rsz; i ++ )
	{
		/*second loop is based on m2 row size - same as above*/
		for( j = 0; j < csz; j++ )
		{
			/*multiplcation is based on the remaining attribute*/
			for( k = 0; k < csz; k++ )
				ans[i][j] += m1[i][k] * m2[k][j]; 
		}
	}

	return;
}



/******************************************************************************
 *****************************************************************************/
void mult_ar_gen( int m1[][CSZ], int m2[][CSZ], int ans[][CSZ], int rsz, int
		csz )
{

}

