/* struct - a program that contains a struct
* with types name, phone and student number
* The values can be read from a dat file, entered by the user
* and written to a disk if required 
* last modified 02/Dec/2012 James Coll
*/


#include <stdio.h>
#include <stdlib.h>


struct s_student_info {
	char name[100];
	char phone_number[20];//store as char to allow for symbols and brackets
	int student_number;
};

typedef struct s_student_info student_info;

void update_struct(student_info *student);
void write_struct(student_info *student);
void read_struct(student_info *student);

const char filename[] = "struct.dat";

int main(void)
{
	//for this program - as we're just handling one set of data 
	//i'm going to make the array on the stack and then write
	//it at the close of the program - for the next i will use dynamic 
	//allocation
	student_info student;
	char c;
	
	
	printf("**** Student Table ****\n");
	printf("\nLoad information from file y/n");
	
	do{
		c=getchar();
		
	} while (c != 'y' && c!='n');
	
	if (c == 'y')
	{
		read_struct(&student);
	}
	
	if (c == 'n')
	{
		update_struct(&student);
	}
	
	printf("\n**** Table Now Contains ****\n");
	printf("Name: %s\n", student.name);
	printf("Phone Number: %s\n", student.phone_number);
	printf("Student Number: %d\n", student.student_number);
	printf("\n**** Writing Data To File ****\n");
	write_struct(&student);
	
	return 0;
}

void update_struct(student_info *student)
{
	printf("Enter name:");
	scanf("%s", &student->name);
	printf("Enter phone number:");
	scanf("%s", &student->phone_number);
	printf("Enter student number:");
	scanf("%d", &student->student_number);
	
	return;
}

void write_struct(student_info *student)
{

	FILE *fp;	
	fp=fopen(filename, "w+");
	
	if (fp == NULL)
	{
		printf("Unable to open %s for reading\n", filename);
		exit(1);
	}
	
	fprintf(fp, "%s %s %d", &student->name, &student->phone_number, &student->student_number);
	
	fclose(fp);
	
	return;
}

void read_struct(student_info *student)
{
	
	FILE *fp;
	
	fp=fopen(filename, "r");
	
	if (fp == NULL)
	{
		printf("Unable to open %s for reading\n", filename);
		exit(1);
	}
	
	fscanf(fp, "%s %s %d", &student->name, &student->phone_number, &student->student_number);
	
	fclose(fp);
	
	return;
}


