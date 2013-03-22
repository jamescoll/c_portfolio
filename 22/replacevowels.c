/* replacevowels.c A program which replaces the vowels in a sentence using a series
* of if and else statements.
* Last Modified 09/Nov/2012 James Coll
***/

#include <stdio.h>
#include <string.h>

const int SENTENCE_LENGTH=100;


int main(void)
{

	//we are using the above variable to set the array size
	char sentence[SENTENCE_LENGTH];
	//this will contain the string flipped around
	char newsentence[SENTENCE_LENGTH];
	int iCounter;
	int iWordLength;
	
	printf("Enter a sentence: ");	
	fgets(sentence, SENTENCE_LENGTH, stdin);
	//we use printf to output text and the stored character array
	printf("You input: %s\n", sentence);
	//use strlen to get the length of the sentence
	iWordLength = strlen(sentence);
	
	for (iCounter=0; iCounter <= iWordLength; iCounter++)
	{
	
			if(sentence[iCounter]=='a')
	
				newsentence[iCounter]='$';
		
			else if(sentence[iCounter]=='e')
			
				newsentence[iCounter]='$';
			
			else if(sentence[iCounter]=='i')
			
				newsentence[iCounter]='$';
			
			else if(sentence[iCounter]=='o')
			
				newsentence[iCounter]='$';
			
			else if(sentence[iCounter]=='u')
			
				newsentence[iCounter]='$';
			
			else
				newsentence[iCounter]=sentence[iCounter];
			
			
	}
	
	
	
	printf("Without the vowels: %s\n", newsentence);
	return 0;

}
	