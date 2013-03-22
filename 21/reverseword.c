/* reverseword.c A program which prints a sentence out
* with each word reversed
* Last Modified 09/Nov/2012 James Coll
***/



#include <stdio.h>
#include <string.h>


const int SENTENCE_LENGTH=200; 


int main(void)
{



char sentence[SENTENCE_LENGTH]; 

int  i, j, d;


printf("Enter a sentence:\n"); /*Ask user to enter a sentence*/
fgets(sentence, SENTENCE_LENGTH, stdin); /*Use fgets to retrieve data and place in sentence array.*/
printf("You input: %s\n", sentence); /*Print contents of array*/
d = strlen(sentence);

sentence[d-1] = ' ';

printf("The word in reverse is the following:\n");
 
			for (i=0; i<= d; i++) /*For each letter of the sentence*/
			{
					
					if(sentence[i] == ' ')
					{
						   
							for (j=(i-1);(sentence[j]!=' ')&&(j>=0); j--) /*Print the letters until you meet another break*/
							{
										
									printf("%c", sentence[j]);
							}
							
							printf(" "); /*Put a break between the words*/
					}
				
				

			}

printf("\n");


 
return 0;
}