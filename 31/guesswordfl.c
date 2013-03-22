/* guesswordfl.c A program which asks the user to guess
* a word which it then compares to a word read in
* from a file guess.txt - the user has three chances
* Last Modified 28/Nov/2012 James Coll
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	char SECRET[20];
	char guess[20];
	int iCheck = 0;
	int iTurn = 2;
	
	fp = fopen("guess.txt", "r"); 
	if(fp == NULL)
	{
		printf("Problem opening input file\n");
		exit(1);
	}
	
	while(fgets(SECRET, sizeof(SECRET), fp)!= NULL)
	{
		int x = strlen(SECRET);
		//remove the newline symbol so strcmp works
		if(SECRET[x-1]=='\n')
		{
				SECRET[x-1]='\0';
		}
		
	}
	while(iCheck != 1 && iTurn != -1)
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
			printf("Sorry %s is not the secret word. %d guesses remaining.\n", guess, iTurn);
			iTurn--;
		}
	}
	
	printf("Game Over\n");
	
	
	return 0;
}
	