#include <stdio.h>

int main(void)
{
	int iNumbers[2];
	int iResults[2];
	
	
	printf("Enter the first number:");
	scanf("%9d", &iNumbers[0]);
	printf("Enter the second number:");
	scanf("%9d", &iNumbers[1]);
	
	iResults[0] = iNumbers[0] + iNumbers[1];
	iResults[1] = iNumbers[0] - iNumbers[1];
	
	printf("The two numbers added give %d\n", iResults[0]);
	printf("The two numbers subtracted give %d\n", iResults[1]);	
	
	return 0;
	
	
}