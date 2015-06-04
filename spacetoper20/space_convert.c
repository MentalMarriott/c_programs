/* Takes string as an argument with spaces and then replaces the spaces with %20 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_per20(char *word);

int main(int argc, char *argv[])
{
	// number of arguments minus one is number of words with spaces
	// 5 args = 4 words = 3 spaces eg file.c this is a sentance
	int all_words_size = 0;
	int i;


	for(i = 1; i < argc; i++)
	{
		all_words_size += strlen(argv[i]);
	}


	char all_words[all_words_size+1] ;
	strcpy(all_words, argv[1]);
	strcat(all_words, "%20");

	for(i = 2; i < argc; i++)
	{
		strcat(all_words, argv[i]);
		strcat(all_words, "%20");
	}

	printf("%s\n", all_words);	

	remove_per20(all_words);

	return 0;
}

void remove_per20(char *word)
{
	word[strlen(word)-3] = '\0';
	printf("%s\n", word);	
}
