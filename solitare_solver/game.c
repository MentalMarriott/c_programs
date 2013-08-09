#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declarations.h"


char **column1, **column2, **column3, **column4, **column5, **column6, **column7, **end1, **end2, **end3, **end4, **remaining_deck, ***game;

int end1_total, end2_total, end3_total, end4_total;


/**
* This will be where the game is dealt out and each move calculated and recorded.
*/
void dealGame(char **shuffled_deck)
{
	int i, j, card, pile_count, card_pile;
	card = 0;
	pile_count = 0;
	card_pile = 0;

	memoryAllocateStart();

	//deals the cards out, those with * at the start of the name will be face down
	for(i = 0; i < 7; i++)
	{
		game[i][pile_count] = shuffled_deck[card];
		card++;
		pile_count++;
		
		for(j = i+1; j < 7; j++)
		{
			char *face_down = malloc(sizeof(char)*5);
			strcpy(face_down, "*");
			strcat(face_down, shuffled_deck[card]);
	
			game[j][card_pile] = shuffled_deck[card];
		}
		card_pile++;	
	}
	
}


/**
* This will memory allocate the start game layout so cards can be dealt to the right places
*/
void memoryAllocateStart()
{
	int i;

	column1 = (char**)malloc(sizeof(char*)*1);
	column2 = (char**)malloc(sizeof(char*)*2);
	column3 = (char**)malloc(sizeof(char*)*3);
	column4 = (char**)malloc(sizeof(char*)*4);
	column5 = (char**)malloc(sizeof(char*)*5);
	column6 = (char**)malloc(sizeof(char*)*6);
	column7 = (char**)malloc(sizeof(char*)*7);

	remaining_deck = (char**)malloc(sizeof(char*)*24);

	end1_total = end2_total = end3_total = end4_total = 1;
	
	end1 = (char**)malloc(sizeof(char*)*end1_total);
	end2 = (char**)malloc(sizeof(char*)*end2_total);
	end3 = (char**)malloc(sizeof(char*)*end3_total);
	end4 = (char**)malloc(sizeof(char*)*end4_total);

	game = (char***)malloc(sizeof(char**)*12);

	game[0] = column1;
	game[1] = column2;
	game[2] = column3;
	game[3] = column4;
	game[4] = column5;
	game[5] = column6;
	game[6] = column7;

	game[7] = remaining_deck;
	
	game[8] = end1;
	game[9] = end2;
	game[10] = end3;
	game[11] = end4;
	
}




