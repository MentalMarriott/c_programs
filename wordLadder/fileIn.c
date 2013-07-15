#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

char **wordsArray = NULL;


/**
* Start of the program where user enters a word and that word is then passed
* on and processed.
*/
/*int main()
{
	int length;
	char word[16];

	printf("Enter any word up to 15 characters long: ");
	scanf("%s", word);

	length = strlen(word);

	printf("Word is: %s, Length of word is: %d\n", word, length);
	
	readFile(length);
}*/


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
			//printf("Line %d is: %s\n", i, line);
			wordsArray[i-1] = strdup(line);
			//strcpy(wordsArray[i], line);
		}
		fclose(fp);
		//printArray(wordsArray, arraySize);
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
char** getWords()
{
	return wordsArray;
}




