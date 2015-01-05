/*
Write a function to find the longest common prefix string amongst an array of strings..
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using std::string;
using std::vector;


void find_longest_common( vector<string> ar );
int min3( string a, string b, string c );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int i = 0;
	vector<string> ar;
	find_longest_common( ar );
	return 0;
}


/******************************************************************************
 *****************************************************************************/
void find_longest_common( vector<string> ar )
{
	int i = 0;
	int j = 0;
	int len = 0;
	char cval = '\0';
	string prefix = "";
	
	ar.push_back( "asdfqwerty" );
	ar.push_back( "asdfjvksjkjhgle" );
	ar.push_back( "asdvjsjdr" );

	len = min3( ar[0], ar[1], ar[2] );

	for( i = 0; i < len; i++ )
	{
		cval = ar[0][i];
		
		for( j = 0; j < ar.size(); j++ )
		{
			if( ar[j][i] != cval )
				goto out;
		}

		prefix += cval;
	}

out:
	printf( "prefix: %s\n", prefix.c_str() );
	return;
}


/******************************************************************************
 *****************************************************************************/
int min3( string a, string b, string c )
{
	if( a.size() < b.size() )
		return ( a.size() < c.size() ) ? a.size() : c.size();
	else
		return ( b.size() < c.size() ) ? b.size() : c.size();
}

