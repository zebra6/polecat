/*
   generate all valid parentheses pairs up to n
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 128

void do_paren_r( char* str, int num, int open, int closed, int off );

int main( int argc, char** argv )
{
	int num = atoi( argv[1] );
	char str[MAX] = { '\0' };

	printf( "parentheses pairs up to %i:\n", num );
	do_paren_r( str, num, 0, 0, 0 );
	printf( "\n\n" );

	return 0;
}


void do_paren_r( char* str, int num, int open, int closed, int off )
{
	if( open == closed && open == num )
	{
		str[off] = '\0';
		printf( "%s\n", str );
		return;
	}
	if( open < closed )
		return;

	if( open < num )
	{
		str[off] = '(';
		do_paren_r( str, num, open+1, closed, off+1 );
	}
	if( closed < open )
	{
		str[off] = ')';
		do_paren_r( str, num, open, closed+1, off+1 );
	}

	return;
}







