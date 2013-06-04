#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//method declarations
void readFile(int lengthOfWord);

/*array of strings at length of word + 1 for null terminater*/
//char words[lengthOfWord+1][numberOfWords];

int main()
{
	int length;
	char word[16];

	printf("Enter any word up to 15 characters long: ");
	scanf("%s", word);

	length = strlen(word);

	printf("Word is: %s, Length of word is: %d\n", word, length);
}


/*Reads in file and stores in an array of strings*/
void readFile(int lengthOfWord)
{
	char fileName[10];
	char length[2];
	char *word;
	FILE *fp;

	//convert int to string
	sprintf(length, "%d", lengthOfWord);
	printf("%s", length);

	strcpy(fileName, "dict");
	strcpy(fileName, length);
	strcpy(fileName, ".dat");
	
	fp = fopen(fileName, "r");

	if(fp = NULL)
	{
		printf("File could not be opened");
		exit(0);
	}else{
	}

}
