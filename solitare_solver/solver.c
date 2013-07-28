/**
* @author Christopher Marriott
* This program is intended to solve a random game of solitaire and display all
* the moves either a step by step or list them all.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "declarations.h"

/**
* Initialises the solver
*/
int main()
{
	menu();
	return 0;
}


/**
* This is where the user gets to choose options to shuffle pack, view
* pack, Deal cards, view current card layout, make single move,
* complete game. 
*/
void menu()
{
	char choice;
	char **deck;
	
	deck = (char**)malloc(sizeof(char*)*52);
	createDeck(deck);

	printf("\nPlease select option\n"
		"Press 'S/s' to shuffle pack,\n"
		"Press 'P/p' to view pack order (top down)\n"
	 	"Press 'D/d' to deal cards out\n"
                "Press 'V/v' to view currently dealt game'\n"
		"Press 'M/m' to make a single move\n"
		"Press 'C/c' to complete the game\n"
		"Press 'X/x' to exit program\n\n");

	choice = getchar();
	choice = tolower(choice);

	switch(choice)
	{
	
	case 's':
		//shufflePack();
		break;	

	case 'p':
		viewPack(deck);
		break;
	
	case 'd':
		//dealCards();
		break;

	case 'v':
		//viewGame();
		break;

	case 'm':
		//singleMove();
		break;
	
	case 'c':
		//completeGame();
		break;

	case 'x':
		printf("System will now exit\n");
		exit(0);
		break;

	default:
		printf("Invalid selection try again\n");
		main();
		break;
	}

	printf("ErRoR! System will now exit\n");
}


/**
* This will create the initial deck in order starting with As(ace
* of spades) to Ks(King of spades) then will add the rest, Ac, Ah
* Ad(ace clubs on to king, ace hearts to king and ace diamonds to
* king. Types are Ace(A), Jack(J), Queen(Q) and King(K) and nums.
*/
void createDeck(char **new_deck)
{
	int i, j, card_count;
	char suit, type;
	char *card;

	new_deck = (char**)malloc(sizeof(char*)*52);

	card = malloc(sizeof(char)*2);

	card_count = 0;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 13; j++)
		{
			type = (char)i;

			if(i == 0)suit = 's';
			if(i == 1)suit = 'c';
			if(i == 2)suit = 'h';
			if(i == 3)suit = 'd';		

			if(j == 0)type = 'A';	
			if(j == 10)type = 'J';
			if(j == 11)type = 'Q';
			if(j == 12)type = 'K';

			card[0] = type;
			card[1] = suit; 	
			new_deck[card_count] = card;
			card_count++;
			printf("card %d is %s\n", card_count, new_deck[card_count]);
		}

	}
}


/**
* This will print out the current order of the deck
*/
void viewPack(char **deck)
{
	int i;

	for(i = 0; i < 52; i++)
	{
		printf("Card %s is at position %d\n", deck[i], i);
	}
}




