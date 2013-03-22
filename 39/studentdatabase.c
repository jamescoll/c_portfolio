/* studentdatabase.c - a program that contains a linked list
* of structs with type name, phone and student number
* The values are read from a dat file at runtime, entered by the user
* and saved to disk if the user requests.
* last modified 05/Dec/2012 James Coll
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct sStudent {
	char name[100];
	char surname[100];
	char phone_number[20];
	int student_number;
	struct sStudent* next;
} student;



const char filename[] = "database.dat";


student *create_record(void);
student *add_student(student *start);
student *remove_student(student *start);
student *element_at_index(student *e, int index);
student *load_all(student *p);
student* add_student_from_file (student *start);

void save_all(student *p);
void input(student *p);
void display(student *p);
void display_all(student *p);


int main(void)
{
	int option;
	student *start=NULL;

	//load data from file database.dat into database 
	//and return pointer to end element
	start=load_all(start);
	
	do
	{

		//Display user menu
		printf("\t****Student Database****\n");
		printf("\t0 - quit\n");
		printf("\t1 - add student\n");
		printf("\t2 - remove student\n");
		printf("\t3 - display all records\n");
		printf("\t4 - save all records and exit\n");
		printf("\tEnter option: ");
		fflush(stdout);

		scanf("%2d", &option);
		
		
			//Process option
			switch (option)
			{
				case 1: start = add_student(start);
					break;
				case 2: start = remove_student(start);
					break;
				case 3: display_all(start);
					break;
				case 4: save_all(start);
					exit(0);
			}
	}while (option != 0);


	return 0;
}

student *load_all(student *start)
{
	FILE *fp;
	start = create_record();
	int ch, iNumberOfRecords;
	ch = 0;
	iNumberOfRecords = 0;
	
	
	printf("\n\t****Loading Records****\n");
	
	fp=fopen(filename, "r");
	
	if (fp == NULL)
	{
		printf("\n\tUnable to open %s for reading\n", filename);
		exit(1);
	}
	
	//we will count the number of records (lines) in the file
	
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '\n')
			++iNumberOfRecords;
	}

	printf("\t****Number of Student Records: %d ****\n", iNumberOfRecords);
	
	//then go back to the beginning
	rewind(fp);
	
	//now read in each line remembering to add code for the fact that fscanf != EOF will read
	//the last line twice
	while(fscanf(fp, "%s %s %s %d", &start->name, &start->surname, &start->phone_number, &start->student_number)!=EOF)
	{	
		start = add_student_from_file(start);
	}
	
	//this code handles the fact that fscanf != EOF will read the last line 
	//twice - we simply remove the repeated first entry in the list
	
	student *next = start->next;
	free(start);
	
	fclose(fp);
	
	return next;
	
	
}

student* add_student_from_file (student *start)
{
	student *last;
	student *new = create_record();

	strcpy(new->name, start->name);
	strcpy(new->surname, start->surname);
	strcpy(new->phone_number, start->phone_number);
	new->student_number=start->student_number;
	
	//Add new student to the end of the list
	if (start != NULL) 
	{
		for (last = start; last->next != NULL; last = last->next);
		last->next = new;
	}
	else start=new; //this record is the new start

	return start;
}




//This function allocates a single record and initialises its values
student *create_record(void)
{
	student *p = (student*) malloc(sizeof(student));
	p->next=NULL;
	strcpy(p->name, " "); 
	strcpy(p->surname, " "); 
	strcpy(p->phone_number, " ");
	p->student_number = 0;
	return p;
}

//Adds a new student to the array. start may be NULL.
student* add_student(student *start)
{
	student *last;
	student *n = create_record();

	input(n);
	
	//Add n to the end of the list
	if (start != NULL) 
	{
		for (last = start; last->next != NULL; last = last->next);
		last->next = n;
	}
	else start=n; //this record is the new start

	return start;
}

//return a pointer to the student at the specified index
student *element_at_index(student *e, int index)
{
	for (; index > 0 && e != NULL; index--, e=e->next);
	return e;
}

student *remove_student(student *start)
{
	student *rem, *previous;
	int index,count;

	if (start == NULL)
	{
		printf("\n\tNo students to remove\n");
		return start;
	}

	printf("\n\tWhich student index do you want to remove? (starting from 0)\n");
	scanf("%9d", &index);

	//The first element is a special case as the 2nd student will become the start
	if (index == 0)
	{
		student *next = start->next;
		free(start);
		return next;
	}
	
	//find the student to remove and the previous student
	rem = element_at_index(start, index);
	previous = element_at_index(start, index-1);

	if (rem == NULL)
	{
		printf("\n\tInvalid index: %d\n", index);
		return start;
	}

	//set the previous student to student to the one after the
	//one being removed
	previous->next = rem->next;

	free(rem);
	return start;
}



//input values into student
void input(student *p)
{
	printf("\tEnter student name: ");
	scanf("\t%50s", &p->name);
	printf("\tEnter student surname: ");
	scanf("\t%50s", &p->surname);
	printf("\tEnter phone number: ");
	scanf("\t%10s", &p->phone_number);
	printf("\tEnter student number: ");
	scanf("\t%10d", &p->student_number);

}



//display a single student
void display(student *p)
{
	printf("\tName: %s\n", p->name);
	printf("\tSurname: %s\n", p->surname);
	printf("\tPhone number: %s\n", p->phone_number);
	printf("\tStudent number: %d\n", p->student_number);
}

//display all students
void display_all(student *p)
{
	int count=0;
	if (p == NULL)
	{
		printf("No student records!\n");
		return;
	}

	printf("\n\n\tStudent Records:\n");
	for (; p != NULL; p = p->next)
	{
		printf("\tEntry %d\n", count++);
		display(p);
	}
	printf("\n\n");
}



void save_all(student *p)
{
	FILE *fp;	
	fp=fopen(filename, "w+");
	
	printf("\n\t****Saving Records and Exiting****");
	if (fp == NULL)
	{
		printf("\t****Unable to open %s for reading****\n", filename);
		exit(1);
	}
	
	for (; p != NULL; p = p->next)
	{
		//print records to file entries delimited by newline
		fprintf(fp, "%s %s %s %d\n", &p->name, &p->surname, &p->phone_number, &p->student_number);

		//release memory allocated by malloc
		free(p);
	}
	
	
	
	fclose(fp);
	
	
	return;
}