#include <stdio.h>
#include <stdlib.h>

typedef struct sPOINT {
	int x,y;
	struct sPOINT* next;
} point;

point *create_element(void);
point *add_point(point *start);
point *remove_point(point *start);
point *element_at_index(point *e, int index);

void input(point *p);
void display(point *p);
void display_all(point *p);

int main(void)
{
	int option;
	point *start=NULL;

	do
	{
		//Display user menu
		printf("0 - quit\n");
		printf("1 - add\n");
		printf("2 - remove\n");
		printf("3 - display all\n");
		printf("Enter option: ");
		fflush(stdout);

		scanf("%2d", &option);

		//Process option
		switch (option)
		{
			case 1: start = add_point(start);
				break;
			case 2: start = remove_point(start);
				break;
			case 3: display_all(start);
				break;
		}
	}while (option != 0);


	return 0;
}

//This function just allocates a single element, and initialises its values
point *create_element(void)
{
	point *p = (point*) malloc(sizeof(point));
	p->next=NULL;
	p->x = 0;
	p->y = 0;
	return p;
}

//Adds a new point to the array. start may be NULL.
point* add_point(point *start)
{
	point *last;
	point *n = create_element();

	input(n);
	
	//Add n to the end of the list
	if (start != NULL) 
	{
		for (last = start; last->next != NULL; last = last->next);
		last->next = n;
	}
	else start=n; //this element is the new start

	return start;
}

//return a pointer to the element at the specified index
point *element_at_index(point *e, int index)
{
	for (; index > 0 && e != NULL; index--, e=e->next);
	return e;
}

point *remove_point(point *start)
{
	point *rem, *previous;
	int index,count;

	if (start == NULL)
	{
		printf("No elements to remove\n");
		return start;
	}

	printf("Which element index do you want to remove? (starting from 0)\n");
	scanf("%9d", &index);

	//The first element is a special case as the 2nd element will become the start
	if (index == 0)
	{
		point *next = start->next;
		free(start);
		return next;
	}
	
	//find the element to remove and the previous element
	rem = element_at_index(start, index);
	previous = element_at_index(start, index-1);

	if (rem == NULL)
	{
		printf("Invalid index: %d\n", index);
		return start;
	}

	//set the previous element to point to the one after the
	//one being removed
	previous->next = rem->next;

	free(rem);
	return start;
}

//input values into element
void input(point *p)
{
	printf("enter values for x and y (e.g. 1 2): ");
	scanf("%d %d", &p->x, &p->y);
	display(p);
}

//display a single element
void display(point *p)
{
	printf("x: %d, y: %d\n", p->x, p->y);
}

//display all elements
void display_all(point *p)
{
	int count=0;
	if (p == NULL)
	{
		printf("No elements in the list!\n");
		return;
	}

	printf("\n\nAll points in the list:\n");
	for (; p != NULL; p = p->next)
	{
		printf("%d: ", count++);
		display(p);
	}
	printf("\n\n");
}