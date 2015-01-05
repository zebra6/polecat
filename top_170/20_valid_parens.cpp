/*
   iven a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

   The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <queue>
#include <string.h>

using std::deque;

void check_is_valid( char* str );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	char* str = argv[1];

	check_is_valid( str );
	return 0;
}



/******************************************************************************
 *****************************************************************************/
void check_is_valid( char* str )
{
	int i = 0;
	int len = strlen( str );
	deque<char> stack;

	for( i = 0; i < len; i++ )
	{
		/*opening brace*/
		if( str[i] == '(' ||
				str[i] == '{' ||
				str[i] == '[' )
		{
			stack.push_back( str[i] );
		}
		else if( str[i] == ')' && stack.back() != '(' )
		{
			printf( "invalid string\n" );
			break;
		}
		else if( str[i] == '}' && stack.back() != '{' )
		{
			printf( "invalid string\n" );
			break;
		}
		else if( str[i] == ']' && stack.back() != '[' )
		{
			printf( "invalid string\n" );
			break;
		}
		else
		{
			stack.pop_back();
		}

	}

	if( stack.empty() )
		printf( "valid string\n" );
	else
		printf( "invalid string\n" );

	return;
}
