#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	// declare variables
	int *ages, how_many_ages;
	
	printf("Enter how many ages you wish to enter \n");
	
	//store how many ages to enter
	scanf("%d", &how_many_ages);

	// allocates memory
	ages = malloc(how_many_ages * sizeof(int));

	printf("Allocated %ld for memory\n", how_many_ages * sizeof(int));

	//assigns age for each space in the array
	int i;
	for(i = 0; i < how_many_ages; i++)
	{
		printf("Please enter age for position %d \n", i);
		scanf("%d", ages+i);
	}

	printf("\nPrintitng ages\n");
	//deliberate error
	for(i = 0; i < sizeof(ages); i++)
	{
		printf("\n%d", *ages+i);
	}
	
	printf("\n");

	return 0;
}
