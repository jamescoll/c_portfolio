#include <stdio.h>

int main(void)
{
	/*this stores the operation the user requests*/
	char cOperator;
	/*doubles will allow for more than basic division operations*/
	int iNumA;
	int iNumB;
	int iResult;
	/*we will also need to check for division by zero*/
	int iError;
	/*initialize iError to zero then set to one if a problem*/
	iError = 0;

	
	printf("Select which operation you want to perform from:\n");
	printf("+ Add, - Subtract, * Multiply, / Divide:");
	
	do{
		cOperator = getchar();
	} while (cOperator == '\n');
	
	printf("Enter your first number:");
	scanf("%d", &iNumA);
	printf("Enter your second number:");
	scanf("%9d", &iNumB);
	

	
	if(cOperator == '+')
	{
		iResult = iNumA + iNumB;
	}
	else if(cOperator == '-')
	{
		iResult = iNumA - iNumB;
	}
	else if(cOperator == '*')
	{
		iResult = iNumA * iNumB;
	}
	else if(cOperator == '/')
	{
		if(iNumB != '0')
		{
			iResult = iNumA / iNumB;
		}
		else
		{
			//set an error to flag and don't perform division
			iError=1;
		}
	}
	else
	{
		iError = 2;
	}
	
	if(iError == 0)
	{
		printf("The result is %d\n", iResult);
	}
	if(iError == 1)
	{
		printf("Error - attempt to divide by zero.\n");
	}
	if(iError == 2)
	{
		printf("Error - operator not recognized.\n");
	}	

	return 0;
	
	
}