/* fgets.c A program which looks at the behaviour of fgets
* Last Modified 09/Nov/2012 James Coll
***/

#include <stdio.h>

//we are declaring a constant integer variable to represent
//the (maximum) length of the sentence
const int SENTENCE_LENGTH=100;


int main(void)
{
	//we are using the above variable to set the array size
	char sentence[SENTENCE_LENGTH];
	//we use printf to output text requesting user input
	printf("Enter a sentence: ");
	//fgets is reading in to the sentence array, until sentence length //bytes are read in and reading in from standard input
	fgets(sentence, SENTENCE_LENGTH, stdin);
	//we use printf to output text and the stored character array
	printf("You input: %s\n", sentence);
	
	return 0;

}
	