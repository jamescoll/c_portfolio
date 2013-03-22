#include <math.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define SWAP(a, b)  a ^= b; b ^= a; a ^= b; 

void vBubbleSort (int iArray[], int iArraySize)
{
	int iElement1, iElement2, iTemp;
	
	for (iElement1 = (iArraySize - 1); iElement1 > 0; iElement1--)
	{
		for (iElement2 = 1; iElement2 <= iElement1; iElement2++)
		{
			if (iArray[iElement2-1]>iArray[iElement2])
			{
				iTemp = iArray[iElement2- 1];
				iArray[iElement2- 1] = iArray[iElement2];
				iArray[iElement2] = iTemp;
			}	
		}
	}
	
	return;
}



void vQuickSort (int iArray[], int iArrayMinVal, int iArrayMaxVal)
{
	//choose a random initial pivot
	//THIS DOESNT WORK YET!!!!!!!!!!!!!!!!
	int iPivotIndex = rand()%iArrayMaxVal;
	int iPivot = iArray[iPivotIndex];
	
	int iIndex = 0, jIndex = iArrayMaxVal - 1;
	
	int iBegin = iArray[0];
	int iEnd = iArray[iArrayMaxVal - 1];
	
	while( iBegin < iEnd)
	{
		while( iBegin < iPivot)
		{
			iBegin++;
		}
		while ( iEnd > iPivot)
		{
			iEnd--;
		}
		SWAP (iBegin, iEnd);
	}
	vQuickSort(iArray, 0, iPivotIndex - 1);
	vQuickSort(iArray, iPivotIndex + 1, iArrayMaxVal);
	
}

float fSquareRoot (int iNumber)
{
	//this will use the divide and average method 
	//for a limited number of runs (100) starting with
	//half the value of the number
	if(iNumber > 0)
	{
		float fGuess = iNumber;
		int iIndex;
		for(iIndex = 0; iIndex < 20; iIndex ++)
		{
			fGuess =  (((fGuess * fGuess) + iNumber) / (2 * fGuess));
		}
		return fGuess;
	}
	
}


void vSelectionSort(int iArray[], int iArraySize)
{
	//this needs to be implemented
	/* a[0] to a[n-1] is the array to sort */
	int iIndex, jIndex;
	int iMin;
	 
	/* advance the position through the entire array */
	/*   (could do j < n-1 because single element is also min element) */
	for (jIndex = 0; jIndex < iArraySize-1; jIndex++) {
		/* find the min element in the unsorted a[j .. n-1] */
	 
		/* assume the min is the first element */
		iMin = jIndex;
		/* test against elements after j to find the smallest */
		for ( iIndex = jIndex+1; iIndex < iArraySize; iIndex++) {
			/* if this element is less, then it is the new minimum */  
			if (iArray[iIndex] < iArray[iMin]) {
				/* found new minimum; remember its index */
				iMin = iIndex;
			}
		}
	 
		/* iMin is the index of the minimum element. Swap it with the current position */
		if ( iMin != jIndex ) {
			SWAP(iArray[jIndex], iArray[iMin]);
		}
	}
}
int iIsPrime (int iFirst)
{
	int i;
	
	if (iFirst < 2) return FALSE;
	
	for (i =2; i*i <= iFirst; i++)
	{
		if (iFirst%i == 0) return FALSE;
	}
	return TRUE;
}


int iGreatestCommonDivisor (int iFirst, int iSecond)
{
	if (iSecond == 0)
	{
		return iFirst;
	}
	int iRemainder = iFirst%iSecond;
	return iGreatestCommonDivisor (iSecond, iRemainder); 
}



int main(void)
{
	int iTemp1;
	int iTemp2;
	int iIndex;
	int iError = 0;
	int iArray[50];
	
	printf("Enter the first integer->");
	scanf("%d", &iTemp1);
	printf("Enter the second integer->");
	scanf("%d", &iTemp2);	
	printf("The greatest common divisor is %d\n", iGreatestCommonDivisor (iTemp1, iTemp2));
	printf("Enter an integer->");
	scanf("%d", &iTemp1);
	if (iIsPrime(iTemp1))
	{
		printf("%d is Prime\n", iTemp1);
	}	
	if (!iIsPrime(iTemp1))
	{
		printf("%d is not Prime\n", iTemp1);
	}		
	printf("Populating Array.\n");
	for (iIndex = 0; iIndex<50; iIndex++)
	{
		iTemp1 = rand()%100;
		iArray[iIndex] = iTemp1;
	}
	printf("Printing Array. \n");
	for (iIndex = 0; iIndex<50; iIndex++)
	{
		if (iIndex%10 == 0)
		{
			printf("\n");
		}
		printf("%d ", iArray[iIndex]);
		
	}
	printf("\nSort the Array using Bubble Sort\n");
	vBubbleSort(iArray, 50);
	printf("Printing Bubble Sorted Array. \n");
	for (iIndex = 0; iIndex<50; iIndex++)
	{
		if (iIndex%10 == 0)
		{
			printf("\n");
		}
		printf("%d ", iArray[iIndex]);
		
	}
	printf("Populating Array.\n");
	for (iIndex = 0; iIndex<50; iIndex++)
	{
		iTemp1 = rand()%100;
		iArray[iIndex] = iTemp1;
	}
	printf("Printing Array. \n");
	for (iIndex = 0; iIndex<50; iIndex++)
	{
		if (iIndex%10 == 0)
		{
			printf("\n");
		}
		printf("%d ", iArray[iIndex]);
		
	}
	printf("\nSort the Array using Selection Sort\n");
	vSelectionSort(iArray, 50);
	printf("Printing Selection Sorted Array. \n");
	for (iIndex = 0; iIndex<50; iIndex++)
	{
		if (iIndex%10 == 0)
		{
			printf("\n");
		}
		printf("%d ", iArray[iIndex]);
		
	}
	printf("\nEnter an integer between 0-100->");
	scanf("%d", &iTemp1);
	printf("\nThe Square root is %f", fSquareRoot(iTemp1));
	return 0;
}