#include <stdio.h>

int main(void)
{
	int iNumA;
	int iNumB;
	int iNumC;
	int iLargest;
	int iTmp;
	
	printf("Enter the first number:");
	scanf("%9d", &iNumA);
	printf("Enter the second number:");
	scanf("%9d", &iNumB);
	printf("Enter the second number:");
	scanf("%9d", &iNumC);
	
	//find the largest between A and B
	if(iNumA>iNumB)
	{
		iTmp = iNumA;
	}
	else
	{
		iTmp = iNumB;
	}
	
	//find the largest between iTmp and C
	if(iTmp>iNumC)
	{
		iLargest=iTmp;
	}
	else
	{
		iLargest=iNumC;
	}
	
	
	
	
	printf("The largest number is %d\n", iLargest);
	
	
	return 0;
	
	
}