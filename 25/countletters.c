/* countletters.c A program which counts out the
* number of letters in a word, stores it in an array and prints it to stdout
* Last Modified 09/Nov/2012 James Coll
***/

#include <stdio.h>
#include <string.h>

const int SENTENCE_LENGTH=300; 

 
int main(void)
{
char caSentence[SENTENCE_LENGTH]; 
int  i, iLength; //an index variable, a length variable and a counter for non-alpha symbols
char caAlphabet[26];
int iaLetterCount[26];


	strcpy(caAlphabet, "abcdefghijklmnopqrstuvwxyz");//set up alphabet array to make life easier later on
	for(i=0;i<26;i++)//initialize the array to zeros
	{
		iaLetterCount[i] = 0;
	}


printf("Enter a Sentence:\n"); //Ask user to enter a caSentence
fgets(caSentence, SENTENCE_LENGTH, stdin); //use fgets to get caSentence

iLength=strlen(caSentence);
printf ("That Sentence has %d letters\n", iLength);

	
	i=0; //reset index for this loop
	do//check for each letter upper and lowercase
	{
		
			if (caSentence[i] == 'a' || caSentence[i] == 'A')
				iaLetterCount[0]+=1;
			if (caSentence[i] == 'b' || caSentence[i] == 'B')
				iaLetterCount[1]+=1;
			if (caSentence[i] == 'c' || caSentence[i] == 'C')
				iaLetterCount[2]+=1;
			if (caSentence[i] == 'd' || caSentence[i] == 'D')
				iaLetterCount[3]+=1;
			if (caSentence[i] == 'e' || caSentence[i] == 'E')
				iaLetterCount[4]+=1;
			if (caSentence[i] == 'f' || caSentence[i] == 'F')
				iaLetterCount[5]+=1;
			if (caSentence[i] == 'g' || caSentence[i] == 'G')
				iaLetterCount[6]+=1;
			if (caSentence[i] == 'h' || caSentence[i] == 'H')
				iaLetterCount[7]+=1;
			if (caSentence[i] == 'i' || caSentence[i] == 'I')
				iaLetterCount[8]+=1;
			if (caSentence[i] == 'j' || caSentence[i] == 'J')
				iaLetterCount[9]+=1;
			if (caSentence[i] == 'k' || caSentence[i] == 'K')
				iaLetterCount[10]+=1;
			if (caSentence[i] == 'l' || caSentence[i] == 'L')
				iaLetterCount[11]+=1;
			if (caSentence[i] == 'm' || caSentence[i] == 'M')
				iaLetterCount[12]+=1;
			if (caSentence[i] == 'n' || caSentence[i] == 'N')
				iaLetterCount[13]+=1;
			if (caSentence[i] == 'o' || caSentence[i] == 'O')
				iaLetterCount[14]+=1;
			if (caSentence[i] == 'p' || caSentence[i] == 'P')
				iaLetterCount[15]+=1;
			if (caSentence[i] == 'q' || caSentence[i] == 'Q')
				iaLetterCount[16]+=1;
			if (caSentence[i] == 'r' || caSentence[i] == 'R')
				iaLetterCount[17]+=1;
			if (caSentence[i] == 's' || caSentence[i] == 'S')
				iaLetterCount[18]+=1;
			if (caSentence[i] == 't' || caSentence[i] == 'T')
				iaLetterCount[19]+=1;
			if (caSentence[i] == 'u' || caSentence[i] == 'U')
				iaLetterCount[20]+=1;
			if (caSentence[i] == 'v' || caSentence[i] == 'V')
				iaLetterCount[21]+=1;
			if (caSentence[i] == 'w' || caSentence[i] == 'W')
				iaLetterCount[22]+=1;
			if (caSentence[i] == 'x' || caSentence[i] == 'X')
				iaLetterCount[23]+=1;
			if (caSentence[i] == 'y' || caSentence[i] == 'Y')
				iaLetterCount[24]+=1;
			if (caSentence[i] == 'z' || caSentence[i] == 'Z')
				iaLetterCount[25]+=1;
			
			i++;
	}while (caSentence[i] != '\0');

printf("Sentence contained the following letters:\n");
	for (i=0; i<26; i++)
	{
		if(i%5 == 0 && i !=0)//this makes things easier to read
			printf("\n");
		printf("%c : %d\t", caAlphabet[i], iaLetterCount[i]);//this prints out the letter count using an array (saves a lot of typing)

	}
	

return 0;
}