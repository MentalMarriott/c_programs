#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "data.h"

/**
* Initialises program
*/
int main()
{
	enterWords();
}

/**
* This is where you enter the two words that you want to
* create a word ladder between
*/
void enterWords()
{
        int startWordLength, endWordLength;
        char startWord[16];
        char endWord[16];

        printf("Enter two words up to 15 characters long: ");
        scanf("%s %s", startWord, endWord);

        startWordLength = strlen(startWord);
	endWordLength = strlen(endWord);

	validateWords(startWordLength, endWordLength);	

        printf("Words are: %s %s, Length of words are: %d %d\n", startWord, endWord, startWordLength, endWordLength);

        readFile(startWordLength);
}


void validateWords(int lengthWordOne, int lengthWordTwo)
{
	if(lengthWordOne != lengthWordTwo)
	{
		printf("\nThe lengths of the two words do not match, the program will now terminate\n\n");
		exit(0);
	}	
}
