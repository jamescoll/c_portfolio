/* line20 - a program that reads from an input file
* 20 lines at a time and waits for the user to input c or C
* to continue
* last modified 28/Nov/2012 James Coll
*/


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char filename[40];
	int iLinenumber;
	char cContinue, c;
	int iLength;
	
	cContinue = 'a'; //initialize cContinue to a non-c value 
	
	printf("Enter file name:");
	scanf("%s", &filename);
	printf("%s\n", filename);
	
	fp = fopen(filename, "r");
	//check that file has opened
	if( fp == NULL)
	{
		printf("Cannot open %s for reading\n", filename);
		exit(1);
	}
	
	iLinenumber = 0;
	
	
	while( c != EOF )
	{
		//count up the number of lines in the file
		if(c == '\n')
		{
			iLinenumber = iLinenumber + 1;
			printf(" - line %d:", iLinenumber);
		}
		
		printf("%c", c);
		c=getc(fp);
		//print lines out twenty lines at a time
		//waiting for 'c' return to be entered to continue
		if(iLinenumber%20 == 0 && cContinue != 'c' && iLinenumber != 0)
		{
			printf("Press c to Continue\n");
			do{
				cContinue=getchar();
			} while (cContinue != 'c');
		}
		
	}
	fclose(fp);
	return 0;
}