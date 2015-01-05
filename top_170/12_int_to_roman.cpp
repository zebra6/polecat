/*
   Given an integer, convert it to a roman numeral.

   Input is guaranteed to be within the range from 1 to 3999.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string>

using std::string;

void convert_to_roman( int val );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int val = atoi( argv[1] );
	convert_to_roman( val );

	return 0;
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
	string result = "";
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
			result += numeral->r_numeral;
			val -= numeral->r_value;
		}	
	}

	printf( "roman numeral val2: %s\n\n", result.c_str() );

	return;
}
