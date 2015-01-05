/*
   Given a digit string, return all possible letter combinations that the number could represent.

   A mapping of digit to letters (just like on the telephone buttons) is given below.
https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

typedef struct
{
	int l_num;
	char l_str[4];
} lut_t;

lut_t table[] =
{
	{ 1, "" },
	{ 2, "abc" },
	{ 3, "def" },
	{ 4, "ghi" },
	{ 5, "jlk" },
	{ 6, "mno" },
	{ 7, "pqr" },
	{ 8, "stu" },
	{ 9, "vwx" },
	{ 0, "yz" }
};


void show_letter_combinations( int num );
void show_letter_combinations_r(
		int num,
		string current,
		vector<string>* results );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int num = atoi( argv[1] );
	show_letter_combinations( num );

	return 0;
}



/******************************************************************************
 *****************************************************************************/
void show_letter_combinations( int num )
{
	int i = 0;
	int reversed = 0;
	vector<string> results;

	/*we have to reverse the number if not using a character array*/
	while( num )
	{
		reversed *= 10;
		reversed += num % 10;
		num /= 10;
	}

	show_letter_combinations_r( reversed, "", &results );

	printf( "results:\n" );
	for( i = 0; i < results.size(); i++ )
		printf( "%s\n", results[i].c_str() );

	printf( "\n" );
	return;
}


/******************************************************************************
 *****************************************************************************/
void show_letter_combinations_r(
		int num,
		string current,
		vector<string>* results )
{
	int i = 0;
	int tmp_val = 0;

	/*base case, num doesn't exist anymore*/
	if( !num )
	{
		results->push_back( current );
		return;
	}

	/*otherwise do dfs for every character in the table*/
	tmp_val = num % 10;
	num /= 10;

	/*tmp val is currently off by one in the lut, need to search instead of
	 * using a direct offset*/

	for( i = 0; i < strlen( table[tmp_val].l_str ); i++ )
		show_letter_combinations_r(
				num, current + table[tmp_val].l_str[i], results );

	return;
}



/*
class Solution
{
	public:
		void dfs( string digits, string r, map<char,vector<char> > &mp, vector<string> &res )
		{
			vector<char> vec = mp[digits[0]];

			if (digits.empty())
				res.push_back(r);
			else
			{
				for( i = 0; i < vec.size(); i++ )
					dfs( digits.substr(1), r+vec[i], mp, res );

			}
		}
		vector<string> letterCombinations(string digits)
		{
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			map<char,vector<char> > mp;
			vector<char> v;
			int n=2;
			for (char i='a';i<='z';i++)
			{
				v.push_back(i);
				if (i=='c' || i=='f'|| i=='i'|| i=='l'|| i=='o'|| i=='s'|| i=='v'|| i=='z')
				{
					mp[char(n+'0')]=v;
					n++;
					v.clear();
				}
			}

			vector<string> res;
			dfs(digits,"",mp,res);
			return res;
		}
};*/
