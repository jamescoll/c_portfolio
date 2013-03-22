#include <stdio.h>

int main(void)
{
	char color[3];
	
	printf("Whats your favourite color?\n");
	scanf("%s", color);
	printf("The first letter is: %c\n", color[0]);
	return 0;
}
