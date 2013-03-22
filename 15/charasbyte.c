/* charasbyte.c A program which looks at the
* behaviour of the char variable addressed as a byte in C
* Last Modified 09/Nov/2012 James Coll
***/

#include <stdio.h>

int main(void)
{
	char cReference;
	//initialize cReference to zero rather than a character
	cReference = 0;
	//the loop goes through the values from -128 to 127 because
	//a character can only contain 255 decimal values
	int iCounter = 0;
	do
	{
		cReference++;
		iCounter++;
		printf("%d\n", cReference); 
		
	} while (iCounter < 10000);

	
	return 0;
}
	