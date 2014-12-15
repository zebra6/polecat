/*
   Sink Zero in Binary Tree. Swap zero value of a node with non-zero
value of one of its descendants
so that no node with value zero could be parent of node with non-zero.
*/

#include "bst_t.h"
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char** argv )
{
	bst_t* tree = new bst_t;

	/*i had to write a bst class for this, some test stuffs*/
	tree->populate_random( 16, 0, 16 );
	//tree->preorder();
	tree->inorder();
	//tree->postorder();
	//tree->level_traverse_queue();
	//tree->height();

	//tree->level_traverse();
	//tree->zero_sink();
	//tree->level_traverse();

	if( tree ) delete tree;
	return 0;
}

