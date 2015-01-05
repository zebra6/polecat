/*
   Given a roman numeral, convert it to an integer.

   Input is guaranteed to be within the range from 1 to 3999.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>

using std::string;

int convert_to_int( char* in );
void convert_to_roman( int val );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	char* str = argv[1];
	int tmp = convert_to_int( str );
	convert_to_roman( tmp );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
int convert_to_int( char* in )
{
	int i = 0;
	int retv = 0;
	char pre = ' ';

	/*the same approach as above does not work so we have to iterate through and
	 * keep track of the previous character
	 http://yucoding.blogspot.com/2013/05/leetcode-question-87-roman-to-interger.html */

	for( i = 0; i < strlen( in ); i++ )
	{
		if( in[i]=='M' && pre!='C' ) retv+=1000;
		if( in[i]=='C' && pre!='X' ) retv+=100;
		if( in[i]=='X' && pre!='I' ) retv+=10;

		if( in[i]=='M' && pre=='C' ) retv+=800;
		if( in[i]=='C' && pre=='X' ) retv+=80;
		if( in[i]=='X' && pre=='I' ) retv+=8;

		if( in[i]=='I' ) retv+=1;

		if( in[i]=='V' && pre!='I' ) retv+=5;
		if( in[i]=='L' && pre!='X' ) retv+=50;
		if( in[i]=='D' && pre!='C' ) retv+=500;

		if( in[i]=='V' && pre=='I' ) retv+=3;
		if( in[i]=='L' && pre=='X' ) retv+=30;
		if( in[i]=='D' && pre=='C' ) retv+=300;

		pre = in[i];
	}

	printf( "%s to int: %i\n", in, retv );

	return retv;
}


/******************************************************************************
 *****************************************************************************/
void convert_to_roman( int val )
{
	typedef struct
	{
		unsigned r_value;
		const char* r_numeral;
	} romandata_t;

	int val2 = val;
	string retvult = "";
	romandata_t* numeral = NULL; 

	/*this one was a bit confusing since I don't really know the rules for roman
	 * numerals, but using a lookup table works well*/

	/*array of values*/
	romandata_t table[] =
	{
		{ 1000, "M" },
		{ 900, "CM" },
		{ 500, "D" },
		{ 400, "CD" },
		{ 100, "C" },
		{ 90, "XC" },
		{ 50, "L" },
		{ 40, "XL" },
		{ 10, "X" },
		{ 9, "IX" },
		{ 5, "V" },
		{ 4, "IV" },
		{ 1, "I"},
		{ 0, NULL} // end marker
	};

	numeral = table;

	/*the outside loop starts at the beginning of the table and works towards
	 * the end*/
	for( numeral = table; numeral->r_value > 0; numeral++ )
	{
		/*the inside loop works by continuously adding the approriate string to
		 * the output string*/
		while( val >= numeral->r_value )
		{
			retvult += numeral->r_numeral;
			val -= numeral->r_value;
		}	
	}

	printf( "roman numeral val2: %s\n\n", retvult.c_str() );

	return;
}
