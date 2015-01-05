/*
   review to cover some of the different methods of generating subsets
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using std::vector;

void subsets_bit_vector( int* ar, int sz );
void subsets_recursive_dfs( int* ar, int sz );
void subsets_recursive_dfs_r(
		int* ar,
		int sz,
		int off,
		vector< vector<int> >* results );
void swap( int* a, int* b );
void print_ar( int* ar, int sz );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	int ar[] = { 1, 2, 3, 4 };

	subsets_bit_vector( ar, 4 );
	printf( "\n" );
	subsets_recursive_dfs( ar, 4 );
	printf( "\n" );

	return 0;
}


/******************************************************************************
 *****************************************************************************/
void subsets_bit_vector( int* ar, int sz )
{
	int i = 0;
	int j = 0;
	int set_size = pow( 2, sz );

	printf( "subsets, bit vector approach:\n" );

	for( i = 0; i < set_size; i++ )
	{
		printf( "%i: ", i );
		for( j = 0; j < sz; j++ )
			if( i & ( 1 << j ) )
				printf( "%i ", ar[j] );

		printf( "\n" );
	}

	return;
}


/******************************************************************************
 *****************************************************************************/
void subsets_recursive_dfs( int* ar, int sz )
{
	printf( "subsets, dfs recursive:\n" );

	return;
}


/******************************************************************************
 *****************************************************************************/
void subsets_recursive_dfs_r(
		int* ar,
		int sz,
		int off,
		vector< vector<int> >* results )
{
	vector<int> new_set;

	/*base case*/
	if( off == sz )
	{
		/*push the empty set to the back*/
		results->push_back( new_set );
		return;
	}

	return;
}

	
/******************************************************************************
 *****************************************************************************/
void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}


/******************************************************************************
 *****************************************************************************/
void print_ar( int* ar, int sz )
{
	int i = 0;

	for( i = 0; i < sz; i++ )
		printf( "%i ", ar[i] );

	printf( "\n" );

	return;
}



/*
vector< vector<int> > getsubsets( vector<int> set, int index )
{
	int item = 0;
	vector<int> empty;
	vector<int> newsubset;
	vector<int>::iterator j
	vector< vector<int> > allsubsets;
	vector< vector<int> > moresubsets;
	vector<vector<int> >::iterator itr;

	if( index!=set.size() )
	{
		allsubsets = getsubsets( set, index+1 );   //get subsets for set[index+1:n]
		item = set[index];
		itr = allsubsets.begin();

		while( i < allsubsets.end() )
		{
			for( j = (*i).begin(); j < (*i).end(); j++ )
				newsubset.push_back( *j );         //make a copy of each of the subsets obtained for set[index+1:n]

			newsubset.push_back( item );       //add set[index] to each one of them
			moresubsets.push_back( newsubset );

			i++;
		}

		for( i = moresubsets.begin(); i < moresubsets.end(); i++ )
			allsubsets.push_back( *i );        //now this is the new set of subsets!!

		return allsubsets;
	}

	allsubsets.push_back(empty);         //empty value acts as NULL for subsets
	return allsubsets;

}



main()

{
	int n,a;
	vector <int> set;
	vector< vector <int> > k;
	cin>>n;
	for(int i=0;i<n;i++)
	{

		cin>>a;

		set.push_back(a);

	}

	k=getsubsets(set,0);
	for(vector<vector<int> >::iterator i=k.begin();i<k.end();i++)
	{  
		for(vector<int>::iterator j=(*i).begin();j<(*i).end();j++)
		{
			cout<<*j<<" ";
		}

		cout<<endl;
	}
	getch();
}
*/
