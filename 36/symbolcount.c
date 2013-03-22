/* symbolcount.c A program which allows a user to 
* specify a line name on the command line
* from a source file and counts the occurences of brackets within
* that line - printing the output to the user and letting them
* know if there are differences in the count
* Last Modified 28/Nov/2012 James Coll
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char filename[40];
	int iCurlyBracketOpen, iCurlyBracketClosed;
	int iSquareBracketOpen, iSquareBracketClosed;
	int iRoundBracketOpen, iRoundBracketClosed;
	int c;
	
	iCurlyBracketOpen = 0;
	iCurlyBracketClosed = 0;
	iSquareBracketOpen = 0;
	iSquareBracketClosed = 0;
	iRoundBracketOpen = 0;
	iRoundBracketClosed = 0;
	
	
	if(argv[1] != NULL)
	{
		sscanf(argv[1], "%s", &filename);
	}
	else
	{
		printf("No input file\n");
		exit(1);
	}
	
	fp = fopen(filename, "r");
	
	if(fp == NULL)
	{
		printf("Problem opening file\n");
		exit(1);
	}
	
	c = getc(fp);
	
	while ( c != EOF)
	{
		if(c == '{')
		{
			iCurlyBracketOpen++;
		}
		if(c == '}')
		{
			iCurlyBracketClosed++;
		}
		if(c == '[')
		{
			iSquareBracketOpen++;
		}
		if(c == ']')
		{
			iSquareBracketClosed++;
		}
		if(c == '(')
		{
			iRoundBracketOpen++;
		}
		if(c == ')')
		{
			iRoundBracketClosed++;
		}
		c = getc(fp);
	}
	
	printf("\n\t***Brackets Count***\n\n");
	printf("\t{ - %d\n", iCurlyBracketOpen);
	printf("\t} - %d\n", iCurlyBracketClosed);
	if(iCurlyBracketOpen != iCurlyBracketClosed)
	{
		printf("\tCheck your { and } brackets\n");
	}
	else
	{
		printf("\tCount Equal\n");
	}
	printf("\t[ - %d\n", iSquareBracketOpen);
	printf("\t] - %d\n", iSquareBracketClosed);
	if(iSquareBracketOpen != iSquareBracketClosed)
	{
		printf("\tCheck your [ and ] brackets\n");
	}
	else
	{
		printf("\tCount Equal\n");
	}
	printf("\t( - %d\n", iRoundBracketOpen);
	printf("\t) - %d\n", iRoundBracketClosed);
	if(iRoundBracketOpen != iRoundBracketClosed)
	{
		printf("\tCheck your ( and ) brackets\n");
	}
	else
	{
		printf("\tCount Equal\n");
	}
	fclose(fp);
	return 0;
}
	