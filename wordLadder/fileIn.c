#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//method declarations
void readFile(int lengthOfWord);
void printArray(char** wordList, int arraySize);

/*array of strings at length of word + 1 for null terminater*/
//char words[][];


/**
* Start of the program where user enters a word and that word is then passed
* on and processed.
*/
int main()
{
	int length;
	char word[16];

	printf("Enter any word up to 15 characters long: ");
	scanf("%s", word);

	length = strlen(word);

	printf("Word is: %s, Length of word is: %d\n", word, length);
	
	readFile(length);
}


/*Reads in file and stores in an array of strings*/
void readFile(int lengthOfWord)
{
	printf("Word length: %d\n", lengthOfWord);

	int wordLength = lengthOfWord;
	char fileName[15];
	char length[5];
	int j;

	//creates a 2d array for words to go in
	/*for(j = 0; j < 9999; j++)
	{
		wordsArray[j] = (char*) malloc(wordLength*sizeof(char));	//each item has space for length of given word
	}*/
	
	char *word;
	//char wordsList[wordLength+1][999];

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
	
	char line[wordLength];	
	char **wordsArray = NULL;
	int i = 0;
	int arraySize = 0;

//	memset(wordsArray, 0, 999*(sizeof(wordsArray[0])));

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

		while(fgets(line, (sizeof line)+4, fp))
		{
			i++;
			arraySize++;
			wordsArray = (char**)realloc(wordsArray, sizeof(char*)*i);
			//printf("Line %d is: %s\n", i, line);
			wordsArray[i-1] = strdup(line);
			//strcpy(wordsArray[i], line);
		}
		fclose(fp);
		printArray(wordsArray, arraySize);
		printf("First word: %s\n", wordsArray[0]);
	}else{
		perror(fileName);
	}
}


//SORT OUT WORDS NOT ADDING TO ARRAY PROPERLY AND/OR PRINTING RIGHT

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







