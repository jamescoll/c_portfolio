/* ptrword.c A program which allocates a small amount of memory
* using malloc, puts a string into that location and then uses
* a pointer to modify what is in that location
* Last Modified 26/Nov/2012 James Coll
***/

#include <stdio.h>
#include <stdlib.h>


const int STR_LENGTH = 50;

int main(void)
{
	char *word;
	char *ptr;
	word = (char*)malloc(STR_LENGTH);
	printf("Enter some text:");
	fgets(word, 50, stdin);
	printf("The character array starting from word location %u, contains %s\n", word, word);
	
	ptr = &word[1];/*Go the the second element*/
	*ptr = '_';/*Modify it*/
	ptr += 2; /*Go to the fourth element*/
	*ptr = '$';/*Modify it to be a dollar*/
	printf("The character array starting from word location %u, now contains %s\n", word, word);	/*Output the final print with alterations*/
	free(word);
	
	return 0;
}