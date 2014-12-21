
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

void find_ps( int val );
int find_ps_r( int val, int a, int b );
short is_ps( int val );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	find_ps( 1215306625 );
	return 0;
}


/******************************************************************************
 *****************************************************************************/
void find_ps( int val )
{
	int i = 0;
	int j = sqrt( val );
	int sum = 0;
	int count = 0;

	while( i <= j )
	{
		sum = ( i * i ) + ( j * j );
		if( sum == val )
		{
			count++;
			i++;
			j--;
		}
		else if( sum > val )
		{
			j--;
		}
		else
		{
			i++;
		}
	}

	printf( "count: %i\n", count );

	return;
}
