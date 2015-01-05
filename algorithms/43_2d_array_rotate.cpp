/*
rotate a 2d square array 90 degrees
http://stackoverflow.com/questions/42519/how-do-you-rotate-a-two-dimensional-array
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RSZ 6
#define CSZ 6
#define MAX 10

void print_ar( int ar[CSZ][RSZ], int csz, int rsz ); 
void rotate_90r( int ar[CSZ][RSZ], int csz, int rsz );
void rotate_90l( int ar[CSZ][RSZ], int csz, int rsz );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int j = 0;
	int ar[CSZ][RSZ] = { { 0 } };

	srand(time(NULL));

	for( i = 0; i < CSZ; i++ )
		for( j = 0; j < RSZ; j++ )
			ar[i][j] = rand() % MAX;
	
	printf( "input array:\n" );
	print_ar( ar, CSZ, RSZ );
	printf( "\n" );
	rotate_90r( ar, CSZ, RSZ );
	rotate_90l( ar, CSZ, RSZ );
	printf( "rotated array:\n" );
	print_ar( ar, CSZ, RSZ );
	printf( "\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void print_ar( int ar[CSZ][RSZ], int csz, int rsz )
{
	int i = 0;
	int j = 0;

	for( i = 0; i < csz; i++ )
	{
		for( j = 0; j < rsz; j++ )
			printf( "%2i", ar[i][j] );
		printf( "\n" );
	}

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void rotate_90r( int ar[CSZ][RSZ], int csz, int rsz )
{
	int i = 0;
	int j = 0;
	int k = 0;
	int tmp = 0;
	/*general approach is to transpose and then reverse each row*/

	/*transpose*/
	for( i = 0; i < csz; i++ )
		/*j = i here to only transpose the upper triangle of the matrix*/
		for( j = i; j < rsz; j++ )
		{
			tmp = ar[i][j];
			ar[i][j] = ar[j][i];
			ar[j][i] = tmp;
		}

	/*reverse all the rows*/
	for( i = 0; i < csz; i++ )
	{
		for( j = 0, k = rsz-1; j < k; j++, k-- )
		{
			tmp = ar[i][j];
			ar[i][j] = ar[i][k];
			ar[i][k] = tmp;
		}
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void rotate_90l( int ar[CSZ][RSZ], int csz, int rsz )
{
	int i = 0;
	int j = 0;
	int k = 0;
	int tmp = 0;

	/*general approach is the same as above but we reverse the columns instead
	 * of the rows*/

	/*transpose*/
	for( i = 0; i < csz; i++ )
		for( j = i; j < rsz; j++ )
		{
			tmp = ar[i][j];
			ar[i][j] = ar[j][i];
			ar[j][i] = tmp;
		}

	/*reverse the columns*/
	for( i = 0; i < rsz; i++ )
		for( j = 0, k = csz-1; j < k; j++, k-- )
		{
			tmp = ar[j][i];
			ar[j][i] = ar[k][i];
			ar[k][i] = tmp;
		}

	return;
}

