#include <stdio.h>

int main(void)
{
	int a;
	char b;
	float c;
	double d;
	int iArray[3];
	char cArray[4];
	float fArray[5];
	double dArray[6];
	
	printf("The size of an int is %d\n bytes", sizeof(a));
	printf("The size of an char is %d\n bytes", sizeof(b));
	printf("The size of an float is %d\n bytes", sizeof(c));
	printf("The size of an double is %d\n bytes", sizeof(d));
	printf("The size of an int array of 3 elements is %d\n bytes", sizeof(iArray));
	printf("The size of an char array of 4 elements is %d\n bytes", sizeof(cArray));
	printf("The size of an float array of 5 elements is %d\n bytes", sizeof(fArray));
	printf("The size of an double array of 6 elements is %d\n bytes", sizeof(dArray));
	return 0;
}
