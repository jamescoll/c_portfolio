/* reversewordfunction.c A program which receives a sentence
* and then reverses it in place using a function
* vSwapCharactersInWords to swap each word in sequence
* Last Modified 18/Nov/2012 James Coll
***/

#include <stdio.h>
#include <string.h>

const int SENTENCE_LENGTH=200; 

void vSwapCharactersInWord(char *cpPointer, int iStartOfWord); 

int main(void)
{
	char caSentence[SENTENCE_LENGTH]; 
	int  iIndex, iEnd, iLength;

	printf("Enter a Sentence:\n"); /*Ask user to enter a caSentence*/
	fgets(caSentence, SENTENCE_LENGTH, stdin); /*Use fgets to retrieve data and place in caSentence array.*/
	printf("You input:%s\n", caSentence); /*Print contents of array*/

	iLength=strlen(caSentence);

	if(caSentence[iLength-1]=='\n')
		caSentence[iLength-1]='\0';
	iEnd= iLength - 1; /*this makes our loop easier to use as it will avoid looking for the space at the end of the string*/
	for(iIndex=0;iIndex<iEnd;iIndex++)
	{
		
		
		if((caSentence[iIndex-1]==' ')||(iIndex == 0))
		{
			/*this gets us our start of word index*/

			vSwapCharactersInWord(caSentence, iIndex);	
		}
		
	}
	printf("The reverse is:%s\n", caSentence);
	return 0;
}

void vSwapCharactersInWord(char *cpPointer, int iStartOfWord)
{
				
				int iWordLength, iCurrentElement;
				iWordLength = 0;
				iCurrentElement = iStartOfWord;
				
				/*Get the current word length*/
				do{
					iWordLength++;
					iCurrentElement++;	
				} while ((cpPointer[iCurrentElement]!=' ')&&(cpPointer[iCurrentElement]!='\0'));
				
				/*Flip the order of characters in the word using pointers*/
				char* cpFirst = &cpPointer[iStartOfWord];
				char* cpLast = &cpPointer[ iStartOfWord + iWordLength - 1 ];
				 while( cpFirst < cpLast ) 
					{
					   char cpTmp = *cpFirst;
					   *cpFirst = *cpLast;
					   *cpLast = cpTmp;
					  ++cpFirst;
					  --cpLast;
					}
				return;
}