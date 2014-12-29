/*
determin centroid of 2d matrix
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RSZ 32
#define CSZ 32
#define MAX 10

void print_ar( int ar[RSZ][CSZ], int rsz, int csz ); 
void find_center( int ar[RSZ][CSZ], int rsz, int csz );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int j = 0;
	int ar[RSZ][CSZ] = { { 0 } };
	int prob[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

	srand(time(NULL));

	for( i = 0; i < RSZ; i++ )
		for( j = 0; j < CSZ; j++ )
			ar[i][j] = prob[rand() % MAX];
	
	printf( "input array:\n" );
	print_ar( ar, RSZ, CSZ );
	find_center( ar, RSZ, CSZ );

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
			printf( "%1i", ar[i][j] );
		printf( "\n" );
	}

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void find_center( int ar[RSZ][CSZ], int rsz, int csz )
{
	int i = 0;
	int j = 0;
	int total_x = 0;
	int total_y = 0;
	int points = 0;

	for( i = 0; i < rsz; i++ )
		for( j = 0; j < csz; j++ )
			if( ar[i][j] )
			{
				total_x += j;
				total_y += i;
				points++;
			}

	printf( "mass x:%i\n", total_x );
	printf( "mass y:%i\n", total_y );
	printf( "center of mass: (%i,%i)\n", total_x/points, total_y/points );
	printf( "center of mass (float): (%.2lf,%.2lf)\n",
			(float)total_x/points,
			(float)total_y/points );
	printf( "\n" );

	return;
}
