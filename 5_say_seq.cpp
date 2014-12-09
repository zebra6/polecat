
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void seek_say( int val );
int seek_say_r( int val, int cur, int* ar, int sz );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{

	return 0;
}


void seek_say( int val )
{
	int i = 0;
	int j = 0;
	int k = 0;
	int cnt = 0;
	char c = '0';
	char ar[256][256] = { { '\0' } };

	strcpy( ar[0], "1" );

	while( i < val )
	{
		j = 0;
		k = 0;
		while( j < strlen( ar[i] ) )
		{
			c = ar[i][j];
			cnt = 1;
			while( c == ar[i][++j] )
				cnt++;

			ar[i-1][k++] = cnt + 48;
			ar[i-1][k++] = c;
		}
		ar[i-1][k] = '\0';
		i++;

	}

	printf( "%i: %s\n", val, ar[val] );
	return;
}
/*
int i=1,k;
int j=0;
while(i<=(n-1))
{

	j=0;
	k=0;        //for building the new string array 
	while(j<strlen(str[i-1]) )
	{
		char c=str[i-1][j];
		int cnt=1;

		while(c==str[i-1][++j])
			cnt++;

		str[i][k++]=cnt+48;
		str[i][k++]=c;

	}
	str[i][k]='\0';
	i++;

}
printf("%s",str[n-1]);  
}


return;
}

*/
