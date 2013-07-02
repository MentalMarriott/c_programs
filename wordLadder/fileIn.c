#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//method declarations
void readFile(int lengthOfWord);
void printArray(char** wordList);

/*array of strings at length of word + 1 for null terminater*/
//char words[][];

char **wordsArray;

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
	wordsArray = (char**)malloc(9999*sizeof(char*));
	for(j = 0; j < 9999; j++)
	{
		wordsArray[j] = (char*) malloc(wordLength*sizeof(char));
	}
//	wordsArray[9999][lengthOfWord+1];		   //sets array size to really large
	char *word;
	//FILE *fp;
	char wordsList[wordLength+1][999];

	memset(fileName, 0, 15*(sizeof(fileName[0])));	    //clears array
	memset(wordsArray, 0, 999*(sizeof(char))); 

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
	
	char line[wordLength+1];	
	char **lines = NULL;
	int i = 0;

	FILE *fp = fopen(fileName, "r");

	if(fp != NULL)
	{
		//char word[lengthOfWord+1];

		while(fgets(line, wordLength+1, fp))
		{
			i++;
			lines = (char**)realloc(lines, sizeof(char*)*i);
			lines[i-1] = strdup(line);
		}
		fclose(fp);
		printArray(lines);
	}else{
		perror(fileName);
	}
}


//SORT OUT WORDS NOT ADDING TO ARRAY PROPERLY AND/OR PRINTING RIGHT

/**
* Prints array to make sure all words are added properly
*/
void printArray(char** wordList)
{
	int i;
	int arrayLength;
	
	arrayLength = sizeof(wordList)/sizeof(char);

	for(i = 0; i < arrayLength; i++)
	{
		printf("%d: %s\n", i, wordList[i]);
	} 
}







