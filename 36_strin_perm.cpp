#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_perm( char* string, int off, int len );
void swap( char* a, char* b );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	char* string = argv[1];
	string_perm( string, 0, strlen(string) );
	printf( "\n" );
	return 0;
}


/******************************************************************************
 *****************************************************************************/
void string_perm( char* string, int off, int len )
{
	int i = 0;

	if( off == len )
	{
		printf( "%s\n", string );
		return;
	}

	for( i = 0; i < len - 1; i ++ )
	{
		swap( string+i, string+i+1 );
		string_perm( string, off+1, len );
		swap( string+i, string+i+1 );
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void swap( char* a, char* b )
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
