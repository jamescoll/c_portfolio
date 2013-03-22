/* filecopy.c A program which takes an input file
* and copies it to an output file
* Last Modified 09/Nov/2012
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[])
{
	
	FILE *fpinput, *fpoutput;
	char inputfilename[20];
	char outputfilename[20];
	char c;
	
	if(argv[1] != NULL)
	{
		sscanf(argv[1], "%s", &inputfilename);
	}
	else
	{
		printf("First argument incorrect or not specified\n");
		exit(1);
	}
	if(argv[2] != NULL)
	{
		sscanf(argv[2], "%s", &outputfilename);
	}
	else
	{
		printf("Second argument incorrect or not specified\n");
		exit(1);
	}
	
	
	fpinput = fopen(inputfilename, "r");
	fpoutput = fopen(outputfilename, "w+");
	
	//check that both files are actually open
	if( fpinput == NULL)
	{
		printf("Cannot open input file.\n");
		exit(1);
	}
	if( fpoutput == NULL)
	{
		printf("Cannot open output file.\n");
		exit(1);
	}
	
	//get each line out of the inputfile and copy it to the
	//output file until EOF is reached
	c = getc(fpinput);
	
	do
	{
		putc(c, fpoutput);
		c = getc(fpinput);
	} while (c != EOF);

	fclose(fpinput);
	fclose(fpoutput);
	return 0;
}
	