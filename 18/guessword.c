/* guessword.c A program which asks the user to guess
* a word
* Last Modified 09/Nov/2012 James Coll
***/

#include <stdio.h>

int main(void)
{
	const char SECRET[] = "labyrinth";
	char guess[20];
	int iCheck = 0;
	
	while(iCheck != 1)
	{
		printf("Please guess a word(less than twenty characters):");
		scanf("%s", guess);
		
		if (strcmp(SECRET, guess) == 0)
		{
			printf("Correct guess - well done\n");
			iCheck = 1;
		}
		else
		{
			printf("Sorry %s is not the secret word\n", guess);

		}
	}
	
	return 0;
}
	