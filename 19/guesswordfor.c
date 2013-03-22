/* guessword.c A program which asks the user to guess
* a word and gives them three chances using a for loop
* Last Modified 09/Nov/2012 James Coll
***/

#include <stdio.h>

int main(void)
{
	const char SECRET[] = "labyrinth";
	char caGuess[20];
	int iTurn;
	int iSucceeded = 0;
	
	printf("******WORD GUESS******\n");
	printf("YOU HAVE THREE CHANCES\n");
	
	for(iTurn = 0; iTurn<3 && iSucceeded != 1; iTurn++)
	{
		printf("Please guess a word(less than twenty characters):");
		scanf("%s", caGuess);
		
		if (strcmp(SECRET, caGuess) == 0)
		{
			printf("Correct guess - well done\n");
			iSucceeded = 1;
		}
		else
		{
			printf("Sorry %s is not the secret word\n", caGuess);
			
		}
	}
	if (iSucceeded != 1)
	{
		printf(" Game over - better luck next time!\n");
	}
	
	return 0;
}
	