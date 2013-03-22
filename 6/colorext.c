#include <stdio.h>

int main(void)
{
	char buffer[10];
	
	printf("Whats your favourite color?\n");
	scanf("%9s", buffer);
	printf("The first letter is: %c\n", buffer[0]);
	return 0;
}
