#include <stdio.h>

int main(void)
{
	int iNumA;
	int iNumB;
	int iAdded;
	int iSubtracted;
	
	printf("Enter the first number:");
	scanf("%9d", &iNumA);
	printf("Enter the second number:");
	scanf("%9d", &iNumB);
	
	iAdded = iNumA + iNumB;
	iSubtracted = iNumA - iNumB;
	
	printf("The two numbers added give %d\n", iAdded);
	printf("The two numbers subtracted give %d\n", iSubtracted);	
	
	return 0;
	
	
}