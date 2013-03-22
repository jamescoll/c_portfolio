/* unsigned.c A program which looks at the
* behaviour of an unsigned integer in C
* Last Modified 09/Nov/2012
***/

#include <stdio.h>

int main(void)
{
	unsigned int iUnsignedInteger;
	unsigned int iReferenceInt;
	
	iUnsignedInteger = 1;
	
	printf("The value of the unsigned integer is: %u\n", iUnsignedInteger);
	
	iReferenceInt = iUnsignedInteger - 2;
	
	printf("The value of the unsigned integer is now: %u\n", iReferenceInt);
	
	return 0;
}
	