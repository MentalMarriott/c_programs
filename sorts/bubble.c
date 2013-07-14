#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "data.h"

/*goes through list and preforms bubble sort*/
void bubble_sort(int *numbers, int *sort_number)
{
	int i, j, check, temp_int, time_taken;

	printf("\nBUBBLE SORT IN PROGRESS\n");	
	
	while(check != 0)
	{
		/*resets check value*/
		check = 0;
		
		for(i = 0; i < *sort_number; i++)
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
	printf("\n BUBBLE SORT DONE\n");
	
	menu(numbers, sort_number);
}
