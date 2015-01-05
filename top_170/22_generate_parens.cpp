/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
 */

#include <stdlib.h>
#include <stdio.h>

void generate( int num_pairs );
void generate_r( char* str, int num_pairs, int num_l, int num_r, int off );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int num_pairs = atoi( argv[1] );

	printf( "pairs %i:\n", num_pairs );
	generate( num_pairs );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void generate( int num_pairs )
{
	char* str = (char*)calloc( 1, ( num_pairs * 2 ) + 1 );

	/*wrapper function, we are generating the catlan number*/
	generate_r( str, num_pairs, 0, 0, 0 );

	if( str ) free( str );
	return;
}


/******************************************************************************
 *****************************************************************************/
void generate_r( char* str, int num_pairs, int num_l, int num_r, int off )
{
	/*base cases*/
	if( num_l == num_r && num_l + num_r == ( num_pairs * 2 ) )
	{
		printf( "%s\n", str );
		return;
	}
	if( num_r > num_l || off >= ( num_pairs * 2 ) )
		return;

	/*recurse*/
	str[off] = '(';
	generate_r( str, num_pairs, num_l+1, num_r, off+1 );
	str[off] = ')';
	generate_r( str, num_pairs, num_l, num_r+1, off+1 );

	return;
}
