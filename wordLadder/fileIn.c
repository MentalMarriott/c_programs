#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

char **wordsArray = NULL;

typedef struct ArrayData array_data;

struct ArrayData
{
	int size;
	char **wordList;
};


/*Reads in file and stores in an array of strings*/
void readFile(int lengthOfWord)
{
	printf("Word length: %d\n", lengthOfWord);

	int wordLength = lengthOfWord;
	char fileName[15];
	char length[5];
	int j;

	char *word;

	memset(fileName, 0, 15*(sizeof(fileName[0])));	    //clears array

	//convert int to string
	sprintf(length, "%d", wordLength);
	printf("temp:%s\n", length);

	printf("%s",fileName);
	strcat(fileName, "dict");
	printf("1:%s\n", fileName);
	strcat(fileName, length);
	printf("2:%s\n", fileName);
	strcat(fileName, ".txt");
	printf("3:%s\n", fileName);
	
	char line[20];	
	int i = 0;
	int arraySize = 0;

	printf("Word length: %d\n", wordLength);

	FILE *fp = fopen(fileName, "r");

	if(fp != NULL)
	{
		//char word[lengthOfWord+1];
		int charSize = sizeof(char);
		int sizeOfLine = sizeof(line);
		printf("Sizeof line is: %i\n", sizeOfLine);
		printf("Sizeof char is: %i\n", charSize);
		printf("One line total size is: %d\n", charSize*sizeOfLine);

		while(fgets(line, 20, fp) != NULL)
		{
			i++;
			arraySize++;
			wordsArray = (char**)realloc(wordsArray, sizeof(char*)*i);
			wordsArray[i-1] = strdup(line);
		}
		fclose(fp);
		printf("First word: %s\n", wordsArray[0]);
	}else{
		perror(fileName);
	}
}



/**
* Prints array to make sure all words are added properly
*/
void printArray(char** wordsArray, int arraySize)
{
	int i;
	int arrayLength;
	
	printf("Array length is: %d\n", arraySize);

	for(i = 0; i < arraySize; i++)
	{
		printf("%d: %s\n", i, wordsArray[i]);
	} 
}

/**
* Returns the list of words equal to the length entered
*/
struct ArrayData getWords()
{
	printf("cake");
	array_data arr_data = {4, wordsArray};
	printf("Bossom");
//	printf("Word array size: %lu\n", sizeof(int));
	return arr_data;
}




