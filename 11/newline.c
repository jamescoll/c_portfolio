#include <stdio.h>

int main(void)
{
	char word[10];
	char c;
	
	printf("Enter a word: ");
	scanf("%9s", word);
	printf("Enter any character: ");
	
	do{
	c = getchar();
	} while (c == '\n');
	
	if (c == '\n') printf("warning: char c contains a newline\n" );
	printf("you entered: word: %s, char: %c\n", word, c);
	
	return 0;
}