#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

char **game = NULL;

/**
*Deals out a new ame 
*/
char** dealGame(char **shuffled_deck)
{
	char **game_deck = shuffled_deck;
	int i, j;

	printf("%c", game_deck[0][0]);	

	j = 0;

	// takes cards from end of deck to make qucker deletion
	for(i = 51; i > 42; i--)
	{
		game = realloc(game, (i+1) * sizeof(char*));

		for( j = 0; j < sizeof(shuffled_deck[i]); j++)
		{
			strcpy(game[i][j], shuffled_deck[i][j]);
		}

		// takes the card that has been added to the game and removes from sffled deck
		shuffled_deck = realloc(shuffle_deck, i-1 * sizeof(char*));
	}
	
}

/**
* displays the game as a 3 x 3 grid
*/
void view_game()
{

}

/*(**char) remove_top_card(char **shuffled_deck)
{
	int i;

	for(i = 0; i < shuffled_deck.length; i++)
	{
		strcpy(shuffled_deck[i], shuffled_deck[i+1];
		
	}

	shuffled_deck = (char*)realloc(shuffled_deck, (shuffled_deck.length-1) * char);
}*/
