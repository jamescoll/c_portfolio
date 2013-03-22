#include <stdio.h>
#include <stdlib.h>

#ifndef __cplusplus
typedef char bool;
#define true 1
#define false 0
#endif

struct list_element
{
	struct list_element *next;
};

//because this struct contains a reference to itself we can't use a typedef 
//until after it is declared that has to be done afterwards - see below

typedef struct list_element list_element;

//this structure will represent the list as a whole
//it contains a pointer to the first element in the list 
//and the last element in the list
typedef struct 
{
	list_element *first;
	list_element *last;
	
} list;

//this is initializing the list to a known state
//this will also allow us the convenience of checking to see
//whether the list is empty

void list_init (list *container)
{
	container->first = 0;
	container->last = 0;
}

bool list_empty(list *container)
{
	//this checks to see if the first element in the list is zero
	return 0 == container->first;
}

list_element *list_begin(list *container)
{
	return container->first;
}

list_element *list_next(list_element *element)
{
	return element->next;
}

void list_push_back(list *container, list_element *element)
{
	//if the list is empty then the newly-added element
	//is both the first and the last element
	if(list_empty(container))
	{
		container->first = element;
		container->last = element;
	}
	else
	{
		//if the list is not empty then we need to
		//update the last element to point to the new element as its
		//next element and then we need to set the last element to point to the 
		//new element
		container->last->next = element;
		container->last = element;
	}
	//this properly marks the end of the list for safe iteration
	element->next = 0;
	
}

list_element *list_pop_front(list *container)
{
	//update the lists first element to point to the next element
	//if there isn't a next element that's okay it will just point to an empty list
	list_element *element = container->first;
	container->first = container->first->next;
	return element;
}

typedef struct
{
	//this is to improve performance
	//as the memory assigned for the list will also 
	//provide memory for the list_element
	
	list_element header;
	int value;
	//the list element is the ***first*** element of the apple structure
	//so that a pointer to the apple structure has the same address in memory as it
} apple;

int main()
{
	list apples;
	
	apples *a = (apple *)malloc(sizeof(apple));
	apples *b = (apple *)malloc(sizeof(apple));
	apples *c = (apple *)malloc(sizeof(apple));
	apples *index = (apple *)malloc(sizeof(apple));
	
	a->value = 1;
	b->value = 2;
	c->value = 3;
	
	list_init(&apples);
	
	list_push_back(&apples, &a->header);
	list_push_back(&apples, &b->header);
	list_push_back(&apples, &c->header);
	
	//index here is being iterated through the list
	//
	for(index = (apple *) list_begin(&apples); index; index=(apple *) list_next(&index->header) )
	{
			printf("%d\n", index->value);
			
	}
	
	//here we are clearing the memory used by the variables in the list
	while (!list_empty(&apples))
	{
		index = (apple *) list_pop_front(&apples);
		free(index);
	}
	
	
	return 0;
}