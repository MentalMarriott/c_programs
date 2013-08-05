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

char **deck = NULL, **shuffled_deck = NULL;

/**
* Initialises the solver
*/
int main()
{
	while(0 == 0)
	{
		menu();
	}
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
	
	createDeck();

	printf("\f\nPlease select option\n"
		"Press 'S/s' to shuffle pack,\n"
		"Press 'P/p' to view sorted pack order (top down)\n"
		"Press 'R/r' to view shuffled pack\n"
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
		shufflePack();
		break;	

	case 'p':
		viewPack();

	case 'r':
		if(shuffled_deck == NULL)
		{
			printf("Deck not been shuffled yet!\n");
			break;
		}else{
			viewShuffled();
			break; 
		}
	
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
		break;
	}
}


/**
* This will create the initial deck in order starting with As(ace
* of spades) to Ks(King of spades) then will add the rest, Ac, Ah
* Ad(ace clubs on to king, ace hearts to king and ace diamonds to
* king. Types are Ace(A), Jack(J), Queen(Q) and King(K) and nums.
*/
void createDeck()
{
	int i, j, k, card_count;
	char *card = malloc(4*sizeof(char));

	deck = (char**)malloc(52*sizeof(char*));

	for(k = 0; k < 52; k++)
	{
		deck[k] = (char*)malloc(sizeof(char)*4);
	}

	card_count = 0;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 13; j++)
		{
			sprintf(card, "%d", j+1);
		
			if(j == 0)strcpy(card, "A");	
			if(j == 10)strcpy(card, "J");
			if(j == 11)strcpy(card, "Q");
			if(j == 12)strcpy(card, "K");

			if(i == 0)strcat(card, "s");
			if(i == 1)strcat(card, "c");
			if(i == 2)strcat(card, "h");
			if(i == 3)strcat(card, "d");

			strcpy(deck[card_count], card);
			printf("%s", deck[card_count]);
			card_count++;
		}

	}
}


/**
* This will take the sorted deck and create a new deck where the cards will be in a random order 
* simulating a shuffled deck.
*/
void shufflePack()
{
	int i, j, cards_picked[52], places_occupied[52], cards_left, rand_card, rand_pos, can_copy, add_pos;

	cards_left = 52;
	add_pos = 0;	

	shuffled_deck = (char**)malloc(sizeof(char*)*52);

	srand(time(NULL));
	
	while(cards_left != 0)
	{
		rand_card = rand()%52;
		rand_pos = rand()%52;
		
		can_copy = 0;

		for(i = 0; i < 51; i++)
		{
			if(cards_picked[i] == rand_card || places_occupied[i] == rand_pos)
				can_copy = 1;
		}	

		if(can_copy == 0)
		{
			shuffled_deck[rand_pos] = deck[rand_card];
			
			cards_picked[add_pos] = rand_card;
			places_occupied[add_pos] = rand_pos;

			printf("pos: %d swapping %d with %d\n", add_pos, rand_card, rand_pos);
	
			add_pos++;	
			cards_left--;
		}			
	}
}


/**
* This will print out the current order of the deck
*/
void viewPack()
{
	int i;

	for(i = 0; i < 52; i++)
	{
		printf("Card %s is at position %d\n", deck[i], i);
	}
}


/**
* This will print out the shuffled deck
*/
void viewShuffled()
{
	int i;
	
        for(i = 0; i < 52; i++)
        {   
                printf("Card %s is at position %d\n", shuffled_deck[i], i); 
        } 
}
