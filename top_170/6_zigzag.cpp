/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

string convert( string in, int num_rows );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	char* cstr_in = argv[1];
	string in( cstr_in );

	printf( "input: %s\n", in.c_str() );
	printf( "\n" );

	convert( in, 3 );
	return 0;
}


/******************************************************************************
 *****************************************************************************/
string convert( string in, int num_rows )
{
	int i = 0;
	int j = 0;
	vector<string> vec2d;
	string tmp_string = "";

	/*this should work... c++ is throwing a fit and the debugging symbols are
	 * broken atm so i can't figure out what is wrong with it*/

	/*initialize the vector of strings*/
	for( i = 0; i < num_rows; i++ )
		vec2d.push_back( tmp_string );

	/*iterate through the string*/
	for( i = 0; i < in.size(); i ++ )
	{
		vec2d[i % num_rows].push_back( in[i] );

		if( i != 0 && i % num_rows == 0 )
		{
			/*remove the character we just added*/
			vec2d[0].erase( vec2d[0].end() );

			/*add it to num_rows/2 row*/
			vec2d[i/2].push_back( in[i] );
		}
	}

	/*print it out in zig-zag form*/
	for( i = 0; i < vec2d.size(); i++ )
	{
		if( i != num_rows / 2 )
			for( j = 0; j < vec2d[i].size(); j++ )
				printf( "%c ", vec2d[i][j] );
		else
			for( j = 0; j < vec2d[i].size(); j++ )
				printf( "%c", vec2d[i][j] );

		printf( "\n" );
	}

	
}




