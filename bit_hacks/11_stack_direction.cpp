/*
	c program to swap bytes in an int
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define TIMES 2

int stack_grows_down( void );
int stack_grows_down_1( int* ref );

/******************************************************************************
 *****************************************************************************/
int main( int argc, char** argv )
{
	printf( "stack grows down: %i\n", stack_grows_down() );
	return 0;
}


/******************************************************************************
 *****************************************************************************/
int stack_grows_down( void )
{
	int ref = 1234;
	return( stack_grows_down_1( &ref ) );
}


/******************************************************************************
 *****************************************************************************/
int stack_grows_down_1( int* ref )
{
	int local = 5678;

	/*test the local variable's address and see if it is less than that of the
	 * calling function*/
	if( &local < ref )
		return true;
	else
		return false;
}

