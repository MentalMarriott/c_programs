/* This takes a string and compresses it using numbers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declaration
void compress(char *word);


// main method ran on program call
int main(int argc, char *argv[])
{
	// call compress function
	if(argc > 1)
	{
		compress(argv[1]);
	}else{
		printf("No word entered\n");	
	}

	return 0;
}


/* takes a string and compresses it */
void compress(char *word)
{
	int size = strlen(word);
	int i;
	int count = 0;
	char *comp_word = (char*) calloc(size +1, sizeof(char)); // ad space for null term if same length even after compressed 

	printf("You entered %s length of %ld\n", word, strlen(word));

	for(i = 0; i < size; i++)
	{
		if(word[i] == word[i+1])
		{
			count += 1;
		}else{
			// if only one letter dont add number
			if(count == 0)
			{
				char buff[2];
				sprintf(buff, "%c", word[i]);
				strcat(comp_word, buff);
			}else{
				count += 1;
				char buf[4];  // buf onlu work for numbers up to 3 digits long
				// creates a char[] representing part of compressed string	
				sprintf(buf, "%d%c", count, word[i]);

				strcat(comp_word, buf);	
			}

			// reset count
			count = 0;
		}
	}
	comp_word = (char*) realloc(comp_word, strlen(comp_word));
	
	printf("After realloc word size is %d in memory and word is %s length is %ld\n", malloc_usable_size(comp_word), comp_word, strlen(comp_word));
}
