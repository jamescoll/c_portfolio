/* array.c A program which allocates a small amount of memory
* using a character array and then prints the location (and contents) out.
* Last Modified 26/Nov/2012 James Coll
***/
#include <stdio.h>


const int STR_LENGTH = 50;

int main(void)
{
	char caArray[STR_LENGTH];
	printf("Enter some text:");
	fgets(caArray, 50, stdin);
	printf("The character array starting from memory location %u, contains %s\n", caArray, caArray); /*It doesn't print the array twice because the unsigned int %u refers to the location in memory in which the array is stored whereas the %s refers to the string of characters stored beginning at that location*/
	
	
	return 0;
}