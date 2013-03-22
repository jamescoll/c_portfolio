/* filecompare.c A program which compares two text files
* to see whether they are equal or not
* Last Modified 29/Nov/2012
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[])
{
	
	FILE *fpfirst, *fpsecond;
	char firstfilename[20];
	char secondfilename[20];
	int c, d;
	
	
	
	if(argv[1] != NULL)
	{
		sscanf(argv[1], "%s", &firstfilename);
	}
	else
	{
		printf("First argument incorrect or not specified\n");
		exit(1);
	}
	if(argv[2] != NULL)
	{
		sscanf(argv[2], "%s", &secondfilename);
	}
	else
	{
		printf("Second argument incorrect or not specified\n");
		exit(1);
	}
	
	fpfirst = fopen(firstfilename, "r");
	fpsecond = fopen(secondfilename, "r");
	
	//check that both files are actually open
	if( fpfirst == NULL)
	{
		printf("Cannot open first file.\n");
		exit(1);
	}
	if( fpsecond == NULL)
	{
		printf("Cannot open second file.\n");
		exit(1);
	}
	
	c= getc(fpfirst);
	d= getc(fpsecond);
	
	while( c!=EOF && d!=EOF && c == d)
	{
			c = getc(fpfirst);
			d = getc(fpsecond);
	}
	if( c == d)
		printf("%s and %s contain identical text\n", argv[1], argv[2]);
	else if (c != d)
		printf("%s and %s contain different text\n", argv[1], argv[2]);
	
	
	
	
	fclose(fpfirst);
	fclose(fpsecond);
	return 0;
}
	