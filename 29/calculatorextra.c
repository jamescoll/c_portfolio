/* calculatorcommand.c A calculator program which takes values from
* the command line and performs calculations on them
* Last Modified 26/Nov/2012 James Coll
***/

#include <stdio.h>


int main(int argc, char *argv[])
{
	
	
	

	/*we'll use unsigned integers to allow for negative numbers*/
	unsigned int iNumA;
	unsigned int iNumB;
	/*this stores the operation the user requests*/
	char cOperator;
	/*this stores the result*/
	int iResult;
	/*this handles trivial and basic errors like unrecognized operand and di
		division by zero*/
	int iError;
	/*initialize iError to zero then set to one if a problem*/
	iError = 0;


	
	sscanf(argv[1], "%d", &iNumA);
	sscanf(argv[2], "%c", &cOperator);
	sscanf(argv[3], "%d", &iNumB);
	

		
		if(cOperator == '+')
		{
			
			iResult = iNumA + iNumB;
		}
		else if(cOperator == '-')
		{
			iResult = iNumA - iNumB;
		}
		else if(cOperator == 'x')
		{
			iResult = iNumA * iNumB;
		}
		else if(cOperator == '/')
		{
			if(iNumB == 0)
			{
			//set an error to flag and don't perform division
			//checks for divide by zero
				iError = 1;
			}
			else
			{
				
				iResult = iNumA / iNumB;
			}
		}
		else
		{
			iError = 2;
		}
		
	
			if(iError == 0)
			{
			printf("%d %c %d is %d\n", iNumA, cOperator, iNumB, iResult);
			}
			if(iError == 1)
			{
				printf("Error - attempt to divide by zero.\n");
			}
			if(iError == 2)
			{
				printf("Error - \"%c\" operator not recognized.\n", cOperator);
			}
	
	
	return 0;
	
	
}