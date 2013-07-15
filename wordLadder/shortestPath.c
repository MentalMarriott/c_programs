#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

char **queue = NULL;
char **all_words = NULL;
char *start_word, *end_word;
//char ***word_parent = NULL;
struct word_parent
{
	//char *word[];
	struct word_parent *parent;
	char *word[];
};

typedef struct word_parent w_p;


/**
* Initialises program
*/
int main()
{
	enterWords();
	//item *curr, *parent;
}

/**
* This is where you enter the two words that you want to
* create a word ladder between. It then validates and processes.
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

	start_word = malloc(sizeof(char*)*startWordLength);
	end_word = malloc(sizeof(char*)*endWordLength);

	start_word = startWord;
	end_word = endWord;	

        printf("Words are: %s %s, Length of words are: %d %d\n", startWord, endWord, startWordLength, endWordLength);

        readFile(startWordLength);
	all_words = getWords();
	shortestPath(startWordLength);
}


void shortestPath(int wordLength)
{
	int i, j, queue_size;
	char word;
	char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	queue_size = 1;

	//printf("Size of char* should be %lu\n", sizeof(char*)); 

	queue = (char**)realloc(queue, sizeof(char*)*queue_size);
	queue[0] = strdup(start_word);
	

	if(strcmp(start_word, end_word) == 0)
	{
		printf("The ladder is %s -> %s\n", start_word, end_word);
		exit(0);
	}

	while(queue == NULL)
	{
		//compare start word with all possible one letter off words that are in the all_words array
		
		//if exists add to end of queue

		//allocate a struct where it is the word and the pointer is to the current word processing's struct

		//lather rinse repeat until either queue is empty or end_word is found

		//if end_word is found then add end word to a list and get the struct it is pointing to
			//then get that structs word and work back until find start_word 
			//then print out final list of sorted words
		//else terminate program declaring there is no word ladder 
		//THE END!
		
		queue_size++;
		printf("full\n");
		queue = (char**)realloc(queue, sizeof(char*)*queue_size);
		queue[queue_size-1] = strdup("this");		
	}
		printQueue();
}


void printQueue()
{
	int i;

//	printf("size of queue is %lu", sizeof(queue));
	
	for(i = 0; i < sizeof(queue)/sizeof(char*); i++)
	{
		printf("Queue contains: %s at pos %d\n", queue[i], i);
	}
}

/**
* This will check the lengths of both words to see if they match 
* if not the program will close
*/
void validateWords(int lengthWordOne, int lengthWordTwo)
{
	if(lengthWordOne != lengthWordTwo)
	{
		printf("\nThe lengths of the two words do not match, the program will now terminate\n\n");
		exit(0);
	}	
}


/**
* This will check all posible one letter difference combinations
* and submit them to see if they are a valid word that has not already
* been found
*/

