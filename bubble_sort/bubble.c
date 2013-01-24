#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void random_generate(int *numbers, int sort_number);
void user_choice(int *numbers, int sort_number);
void print(int *numbers, int sort_number);
void menu(int *numbers, int sort_number);
void bubble_sort(int *numbers, int sort_number);

int main()
{
        int sort_number;

        printf("Please enter amount of numbers you wish to sort through:\n");
        scanf("%d", &sort_number);

        int numbers[sort_number];

	menu(numbers, sort_number);	

	return 0;
}


void menu(int *numbers, int sort_number)
{
	int option;

	printf("\nPress 1 for random numbers");
	printf("\nPress 2 for user inputted numbers");
	printf("\nPress 3 to bubble sort");
	printf("\nPress 4 to print list");
	printf("\nPress 5 to change size of list");
	printf("\nPress 6 to exit\n");
	scanf("%d", &option);

	switch(option)
	{
		
		case 1:
			random_generate(numbers, sort_number);
			break;

		case 2:
			user_choice(numbers, sort_number);
			break;
		
		case 3:
			bubble_sort(numbers, sort_number);
			break;
	
		case 4:
			print(numbers, sort_number);
			break;

		case 5:
			main();
			break;

		case 6:
			exit(0);
			break;

		default:
			printf("Invalid selection try again\n");
			main();
	}
}


void random_generate(int *numbers, int sort_number)
{
	int i;

	for(i = 0; i < sort_number; i++)
	{
		srand(time(NULL));
		numbers[i] = rand();
	}

	menu(numbers, sort_number);
}


void user_choice(int *numbers, int sort_number)
{
	int i, number;

	for(i = 0; i < sort_number; i++)
	{
		printf("Please enter a number to go in position %d\n", i);
		scanf("%d", &number); 

		numbers[i] = number;
	}

	menu(numbers, sort_number);	
}


void bubble_sort(int *numbers, int sort_number)
{
	int i, j, check, temp_int;

	while(check != 0)
	{
		/*resets check value*/
		check = 0;
		
		for(i = 0; i < sort_number; i++)
		{		
			if(numbers[i+1] >= 0)
			{
				if(numbers[i] > numbers[i+1])
				{
					/* store next number in temp int*/
					temp_int = numbers[i+1];
					
					/*set next int value to current int checking */
					numbers[i+1] = numbers[i];

					/*put temp int in previous int location */
					numbers[i] = temp_int;

					/*set check to 1 so still loops */
					check = 1;
				}
			}
		}
	}
	
	menu(numbers, sort_number);
}

void print(int *numbers, int sort_number)
{
	int i;

	for(i = 0; i < sort_number; i++)
	{
		printf("%d--", numbers[i]);
	}
	
	menu(numbers, sort_number);
}
