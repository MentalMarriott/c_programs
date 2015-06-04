#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv)
{

	char *name1 = "hello";
	//char name2[6] = "hello";

	char **names1; // allocate memory for how many names you enter
	char *names2[10]; // can only enter 10 names

	printf("name one is : %s\n", name1);
	//printf("name two is : %s\n", name2);

	int i;

	for(i = 0; i < (sizeof(names2)/sizeof(char*)); i++)
	{
		names2[i] = (char*)malloc(11*sizeof(char));
		printf("Please enter words up to 10 characters long\n");
		scanf("%s", names2[i]);
		printf("%d\n", i);
	}

	for(i = 0; i < (sizeof(names2)/sizeof(char*)); i++)
	{
		printf("Position %d in names2 is %s\n", i, names2[i]);
	}

	return 0;
}
