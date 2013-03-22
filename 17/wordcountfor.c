/* wordcountfor.c A program which computes the size of
* a string using a for loop
* Last Modified 09/Nov/2012 James Coll
***/

#include <stdio.h>

int main(void)
{
	char cWord[20];
	int iWordLength = 0;
	int i;
	
	printf("Please enter a word of less than twenty characters:");
	scanf("%20s", cWord);
	
	
	
	for(i = 0; cWord[i] != '\0'; i++)
	{
		iWordLength++;
	} 
	
	
	
	printf("The word %s has %d letters.\n", cWord, iWordLength);
	
	return 0;
}
	