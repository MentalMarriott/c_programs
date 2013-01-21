#include <stdio.h>
#include <stdlib.h>

/* The list stucture with only int data */
struct list
{
	int data;
	struct list *next;
};

typedef struct list list_data;

/* Prototypes */
void add(list_data *curr, list_data *head);
void delete();
void print_list();

/* Main method lets user chose whether to add, delete or print list */
int main(int argc, char *argv)
{
	int choice;
	list_data *curr, *head;

	printf("Please select option:\nEnter '1' to add number to list\nEnter '2' to delete a number\nEnter '3' to print list\n");
	scanf("%d", &choice);

	switch(choice)
	{
	
	case 1:
		add(curr, head);
		break;

	case 2:
		delete();	
		break;

	case 3:
		print_list();
		break;

	default :
		printf("Error invalid selection");
		break;	
	}

	return 0;
}

/* Add to last item in the list */
void add(list_data *curr, list_data *head)
{
	int number;

	if(head == NULL)
	{
		printf("Works");
	}

	printf("Please enter a number to add to list");
	scanf("%d", &number);

	
}

/* Delete number entered */
void delete()
{

}

/* Prints contents of the list */
void print_list()
{

}
