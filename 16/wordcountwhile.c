/* wordcountwhile.c A program which computes the size of
* a string using a while loop
* Last Modified 09/Nov/2012
***/

#include <stdio.h>

int main(void)
{
	char cWord[20];
	int iCounter;
	int iWordLength;
	char cRef;
	
	printf("Please enter a word of less than twenty characters:");
	scanf("%20s", cWord);
	
	
	
	//we initialize the reference to some non null value
	cRef='a';
	iCounter = 0;
	
	while (cRef != '\0')
	{
		cRef = cWord[iCounter];
		iCounter++;
	} 
	
	//the wordlength will be one less than the counter variable
	iWordLength = iCounter - 1;
	
	printf("The word %s has %d letters.\n", cWord, iWordLength);
	
	return 0;
}
	