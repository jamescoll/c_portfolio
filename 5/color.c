#include <stdio.h>

int main(void)
{
	char buffer[10];
	
	printf("Whats your favourite color?\n");
	scanf("%9s", buffer);
	printf("Your favourite color is: %s\n", buffer);
	return 0;
}
