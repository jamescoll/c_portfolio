#include <stdio.h>

int main(void)
{
	/*this stores the operation the user requests*/
	char cOperator;
	
	int iNumA;
	int iNumB;
	int iResult;
	/*we will also need to check for division by zero*/
	int iError;
	/*initialize iError to zero then set to one if a problem*/
	iError = 0;
	/*add an exit variable to leave the loop on 'q'*/
	int iExit;
	/*initialize*/
	iExit = 0;

	do{
	
		printf("Select which operation you want to perform from:\n");
		printf("+ Add, - Subtract, * Multiply, / Divide, q quit:");
		
		do{
			cOperator = getchar();
		} while (cOperator == '\n');
		
		if(cOperator == 'q')
		{
			iExit=1;
		}
		
		if(cOperator != 'q')
		{
			printf("Enter your first number:");
			scanf("%9d", &iNumA);
			printf("Enter your second number:");
			scanf("%9d", &iNumB);
		}
		

		
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
			if(iNumB == 0)
			{
			//set an error to flag and don't perform division
				iError = 1;
			}
			else
			{
				
				iResult = iNumA / iNumB;
			}
		}
		//if we didn't quit then something unknown happened
		else if(cOperator != 'q')
		{
			iError = 2;
		}
		
		if(cOperator != 'q')
		{
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
		}			
		
	} while (iExit != 1);
	
	return 0;
	
	
}