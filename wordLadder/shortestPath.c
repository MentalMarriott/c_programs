#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

char **queue = NULL;
char **all_words = NULL;
char *start_word, *end_word;
//char ***word_parent = NULL;

int words_length;
int all_words_size;
int queue_size;

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
	words_length = startWordLength;
	
	start_word = malloc(sizeof(char*)*startWordLength);
	end_word = malloc(sizeof(char*)*endWordLength);

	start_word = startWord;
	end_word = endWord;	

        printf("Words are: %s %s, Length of words are: %d %d\n", startWord, endWord, startWordLength, endWordLength);

        readFile(startWordLength);
	shortestPath(startWordLength);
}


/**
* This adds all the words from the read in file to the 
* all words array to be processed later
*/
void addAllWords(char **wordsArray, int size)
{
	int i;
	all_words = (char**)malloc(size*sizeof(char*));
	
	all_words_size = size;

	for(i =0; i < size; i++)
	{
		all_words[i] =  wordsArray[i];
	}	
	//printAllWords(size);
	
//	printf("The size of given is %d\n", size);
}

/**
* Prints all words to make sure they have been properly added
*/
void printAllWords(int size)
{
	int i;
		
	for(i = 0; i < size; i++)
	{
		printf("Word %i is %s\n", i, all_words[i]);
	}
}


/**
* Process words starting with start_word and creates a type of linked list
* where each word discoverd has a pointer to the struct of current word.
* e.g If start word was: CAT then words 1 letter different such at BAT, RAT, MAT etc.
* would all have the struct pointer in their individual structs pointing to CAT struct.
*/
void shortestPath(int wordLength)
{
	int i, j;
	char word;
	char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int inList;
	w_p *curr, *head;

	inList = 1;

	head = NULL;
	
	queue_size = 1;

	queue = (char**)realloc(queue, sizeof(char*)*queue_size);
        queue[0] = strdup(start_word);

	removeFromList(start_word, all_words, all_words_size);

	if(strcmp(start_word, end_word) == 0)
	{
		printf("The ladder is %s -> %s\n", start_word, end_word);
		exit(0);
	}

	while(queue[0] != "")
	{
        	curr = (w_p*)malloc(sizeof(w_p));
	        curr->word = queue[0];
        	curr->parent = head;	
	
		head = curr;
		printf("testing %s\n", queue[0]);
		for(i = 0; i < words_length; i++)
		{
			for(j = 0; j < sizeof(alphabet); j++)
			{
				char test_word[words_length];
				strcpy(test_word, queue[0]);
				test_word[i] = alphabet[j];
				
				inList = checkIfInAllWords(test_word);
				//printf("inList is %d\n", inList);	
				if(inList == 0)
				{
					printf("Adding %s to queue queue_size is %d\n", test_word, queue_size); 
					curr =(w_p*)malloc(sizeof(w_p));			
					curr->word = test_word;	
					curr->parent = head;		
			
					inList = 1;
				}
				//checks if test_word to see if end_word 	
				if(strcmp(test_word, end_word) == 0)
				{
					ifEndWord(test_word, curr);
					printf("End word found %s\n", test_word);
					exit(0);
				}
			}
		}
		removeFromList(queue[0], queue, queue_size);
	}
}

/**
* Takes the found words struct and recursively returns the parent
* until the parent is null.
*/
void ifEndWord(char *word, struct word_parent *curr)
{
	w_p *final_struct, *parent_struct;
	int i;
	i = 0;

	final_struct = curr;
	printf("%s->", final_struct->word);	
	parent_struct = final_struct->parent;

//	while(strcmp(final_struct->word, "") != 0)
	while(i != 100)
	{
		printf("%s->", parent_struct->word);
		printf("%s->", (parent_struct->parent)->word);
		i++;
	}
}


/**
* Checks new word to see if in list of all words and if it is
* it will remove it from the list
*/
int checkIfInAllWords(char *word)
{
	int i;
	int inList = 1;
	//printf("sizeof allwords is %d\n", all_words_size);

	for(i = 0; i < all_words_size; i++)
	{
		if(strcmp(all_words[i], word) == 0 && strcmp(all_words[i], queue[0]) != 0)
		{
			queue_size++;
			queue = (char**)realloc(queue, sizeof(char*)*queue_size);
			queue[queue_size-1] = strdup(word);
			inList = 0;	
			//exit(0);
		}
	}
	return inList;
}

/**
* Find the word in the list given and shuffles all down one from the 
* position one ahead of the given word and reallocates space. This 
* effectivelly removes that word;
*/
void removeFromList(char *word, char** list, int list_size)
{
	int i, j;

	for(i = 0; i < list_size; i++)
	{
		if(strcmp(word, list[i]) == 0)
		{
			printf("removing word at %d\n", i);
			for(j = i; j < list_size-1; j++)
			{
				strcpy(list[i], list[i+1]);
				list = (char**)realloc(list, sizeof(char*)*list_size-1);
			}
		}
	}	
} 


/**
* Prints out the contents of the queue
*/
void printQueue()
{
	int i;

	printf("size of queue is %lu", sizeof(all_words));
	
	for(i = 0; i < sizeof(all_words)/sizeof(char*); i++)
	{
		printf("Queue contains: %s at pos %d\n", all_words[i], i);
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

