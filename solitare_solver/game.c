#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declarations.h"


char **column1, **column2, **column3, **column4, **column5, **column6, **column7, **end1, **end2, **end3, **end4, **remaining_deck;


/**
* This will be where the game is dealt out and each move calculated and recorded.
*/
void dealGame(char **shuffled_deck)
{
	int i, card;
	card = 0;

	memoryAllocateStart();

	for(i = 1; i < 7; i++)
	{
			
	}
	
}


/**
* This will memory allocate the start game layout so cards can be dealt to the right places
*/
void memoryAllocateStart()
{
	column1 = (char**)malloc(sizeof(char*)*1);
	column2 = (char**)malloc(sizeof(char*)*2);
	column3 = (char**)malloc(sizeof(char*)*3);
	column4 = (char**)malloc(sizeof(char*)*4);
	column5 = (char**)malloc(sizeof(char*)*5);
	column6 = (char**)malloc(sizeof(char*)*6);
	column7 = (char**)malloc(sizeof(char*)*7);

	remaining_deck = (char**)malloc(sizeof(char*)*24);
}
