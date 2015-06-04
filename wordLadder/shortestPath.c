#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

//my array of structs, array of all words and the start and end word
w_p *queue;
char **all_words = NULL;
char *start_word, *end_word;

//keeps track of list sizes and words length
int words_length;
int all_words_size;
int queue_size;


/**
* Initialises program
*/
int main()
{
	enterWords();
}


/**
* This is where you enter the two words that you want to create a word ladder between. It then validates and processes.
*/
void enterWords()
{
        int startWordLength, endWordLength;
        char startWord[16], endWord[16];

        printf("Enter two words up to 15 characters long of equal length: ");
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
* This adds all the words from the read in file to the all words array to be processed later
*/
void addAllWords(char **wordsArray, int size)
{
	int i;
	all_words = (char**)malloc(size*sizeof(char*));

	all_words_size = size;

	for(i = 0; i < size; i++)
	{
		all_words[i] =  wordsArray[i];
	}
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
* Process words starting with start_word and creates a type of linked list where each word discoverd has a pointer to the struct of current word. e.g If start word was: CAT then words 1 letter different such at BAT, RAT, MAT etc. would all have the struct pointer in their individual structs pointing to CAT struct.
*/
void shortestPath(int wordLength)
{
	int i, j;
	char word;
	char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	w_p *head;

	//sets up the first head, this will be checked for when recursing through tree.
	head = (w_p*)malloc(sizeof(w_p));
	head->word = "";
	head->parent = NULL;

	//creates space for first element in queue
	queue_size = 1;
	queue = (w_p*)realloc(queue, sizeof(w_p)*queue_size);

	//set first element in queue
	queue[0].word = start_word;
	queue[0].parent = head;

	//removes first word so doesn't get stuck in a loop
	removeFromAllWords(start_word, all_words, all_words_size);

	printf("\nTHINKING\n");

	//if words are the same ladder is already complete
	if(strcmp(start_word, end_word) == 0)
	{
		printf("The ladder is %s -> %s\n", start_word, end_word);
		exit(0);
	}

	//while there are elements in the queue test the word variations and add to the queue, also checks for final word.
	while(queue_size != 0)
	{
		for(i = 0; i < words_length; i++)
		{
			for(j = 0; j < sizeof(alphabet); j++)
			{
				char *test_word = malloc(sizeof(char)*(words_length +1));
				strcpy(test_word, queue[0].word);
				test_word[i] = alphabet[j];

				checkIfInAllWords(test_word);

				if(strcmp(test_word, end_word) == 0)
				{
					ifEndWord(test_word, queue[queue_size-1]);
					exit(0);
				}
			}
		}
		//removes the sorted word from the queue
		removeFromQueue();
	}
	//if the queue becomes empty then there is no ladder to be found
	printf("No ladder found\n");
	exit(0);
}


/**
* Takes the found words struct and recursively returns the parents word until the parent is null.
*/
void ifEndWord(char *word, struct word_parent curr)
{
	struct word_parent final_struct;
	w_p *parent_struct;

	int i;
	i = 0;

	final_struct = curr;
	printf("\n%s->", curr.word);
	parent_struct = final_struct.parent;

	while(strcmp("", parent_struct->word) != 0)
	{
		//parent_struct = parent_struct->parent;
		printf("%s->", parent_struct->word);
		parent_struct = parent_struct->parent;
	}

	printf("DONE!\n\n");
}


/**
* Checks new word to see if in list of all words and if it is it will add a struct containing the parent stuct and itself as a string.
*/
void checkIfInAllWords(char *word)
{
	int i, in_words;
	w_p *head;

	for(i = 0; i < all_words_size; i++)
	{
		if(strcmp(all_words[i], word) == 0)
		{
			queue_size++;
			queue = (w_p*)realloc(queue, sizeof(w_p)*queue_size);
			queue[queue_size-1].word = word;

			head = (w_p*)malloc(sizeof(w_p));
			head->word = queue[0].word;
			head->parent = queue[0].parent;

			queue[queue_size-1].parent = head;
			removeFromAllWords(word, all_words, all_words_size);
		}
	}

}


/**
* Find the word in all_words and shuffles all down one from the position one ahead of the given word and reallocates space. This  effectivelly removes that word.
*/
void removeFromAllWords(char *word, char **list, int list_size)
{
	int i, j;

	for(i = 0; i < all_words_size; i++)
	{
		if(strcmp(word, all_words[i]) == 0)
		{
			strcpy(all_words[i], "0");
			all_words_size--;
			all_words = (char**)realloc(all_words, sizeof(char*)*all_words_size);
		}
	}
}


/**
* removes the head of the queue and shuffles the rest of the queue down one.
*/
void removeFromQueue()
{
	int i;

	for(i = 0; i < queue_size-1; i++)
	{
		queue[i] = queue[i+1];
	}
	queue_size--;
	queue = (w_p*)realloc(queue, sizeof(w_p)*queue_size);
}


/**
* Prints out the contents of the queue
*/
void printQueue()
{
	int i;

	for(i = 0; i < all_words_size; i++)
	{
		printf("Queue contains: %s at pos %d\n", all_words[i], i);
	}
}


/**
* This will check the lengths of both words to see if they match if not the program will close
*/
void validateWords(int lengthWordOne, int lengthWordTwo)
{
	if(lengthWordOne != lengthWordTwo)
	{
		printf("\nThe lengths of the two words do not match, the program will now terminate\n\n");
		exit(0);
	}
}
