
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void move_nz_left( int* ar, int sz );


/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	int ar[] = { 1, 2, 6, 4, 1, 1, 0, 9, 4, 2, 0, 0, 1 };

	for( i = 0; i < sizeof(ar)/sizeof(ar[0]); i ++ )
		printf( "%i ", ar[i] );
	printf( "\n" );

	move_nz_left( ar, sizeof(ar)/sizeof(ar[0]) );

	for( i = 0; i < sizeof(ar)/sizeof(ar[0]); i ++ )
		printf( "%i ", ar[i] );
	printf( "\n" );


	return 0;
}


/******************************************************************************
 *****************************************************************************/
void move_nz_left( int* ar, int sz )
{
	int i = 0;
	int j = 0;

	for( i = 0; i < sz; i ++ )
		if( ar[i] )
			ar[j++] = ar[i];

	for( ; j < sz; j ++ )
		ar[j] = 0;

	return;
}

