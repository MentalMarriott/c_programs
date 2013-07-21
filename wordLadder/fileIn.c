#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

char **wordsArray = NULL;

typedef struct ArrayData array_data;


/*Reads in file and stores in an array of strings*/
void readFile(int lengthOfWord)
{
	int wordLength = lengthOfWord;
	char fileName[15], length[5];
	int j;

	char *word;

	memset(fileName, 0, 15*(sizeof(fileName[0])));	    //clears array

	//convert int to string
	sprintf(length, "%d", wordLength);

	strcat(fileName, "dict");
	strcat(fileName, length);
	strcat(fileName, ".txt");
	
	char line[20];	
	int i = 0;
	int arraySize = 0;

	FILE *fp = fopen(fileName, "r");

	if(fp != NULL)
	{
		//char word[lengthOfWord+1];
		int charSize = sizeof(char);
		int sizeOfLine = sizeof(line);

		while(fgets(line, 20, fp) != NULL)
		{
			i++;
			arraySize++;
			wordsArray = (char**)realloc(wordsArray, sizeof(char*)*i);
			strtok(line, "\n");
			wordsArray[i-1] = strdup(line);
		}
		fclose(fp);
		
		addAllWords(wordsArray, arraySize);
	}else{
		perror(fileName);
	}
}


/**
* Prints array to make sure all words are added properly
*/
void printArray(char** wordsArray, int arraySize)
{
	int i, arrayLength;
	
	printf("Array length is: %d\n", arraySize);

	for(i = 0; i < arraySize; i++)
	{
		printf("%d: %s\n", i, wordsArray[i]);
	} 
}
