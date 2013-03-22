/* mainarguments.c A program which demonstrates
* how a main function with arguments works
* Last Modified 09/Nov/2012 James Coll
***/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	//argc counts the number of arguments
	printf("You supplied %d arguments\n", argc);
	
	for (i=0; i <argc; i++)
	{	
		//argv stores the argument itself
		printf("argument %d = %s\n", i, argv[i]);
	}
	
	return 0;
}