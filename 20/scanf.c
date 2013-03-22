/* scanf.c A program which looks at the behaviour of scanf
* Last Modified 09/Nov/2012 James Coll
***/

#include <stdio.h>

//we are declaring a constant integer variable to represent
//the (maximum) length of the word
const int WORD_LENGTH=100;


int main(void)
{
	//we are using the above variable to set the array size
	char word[WORD_LENGTH];
	//we use printf to output text requesting user input
	printf("Enter a word: ");
	//scanf will read in the user input into the string and
	//is only passed two variables, the input format and the destination //array
	scanf("%s", word);
	//we use printf to output text and the stored character array
	printf("You input: %s\n", word);
	
	return 0;

}
	