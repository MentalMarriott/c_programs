#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//method declarations
void readFile(int lengthOfWord);

/*array of strings at length of word + 1 for null terminater*/
//char words[][];

int main()
{
	int length;
	char word[16];

	printf("Enter any word up to 15 characters long: ");
	scanf("%s", word);

	length = strlen(word);

	printf("Word is: %s, Length of word is: %d\n", word, length);
	
	readFile(length);
}


/*Reads in file and stores in an array of strings*/
void readFile(int lengthOfWord)
{
	printf("%d", lengthOfWord);

	char fileName[15];
	char length[5];
	char *words[99999][lengthOfWord+1];		   //sets array size to really large
	char *word;
	FILE *fp;
	int i = 0;

	memset(fileName, 0, 15*(sizeof(fileName[0])));	    //clears array

	//FIX ISSUE WITH NOT CONVERTING 2 DIGIT NUMBERS//

	//convert int to string
	sprintf(length, "%d", lengthOfWord);
	printf("temp:%s\n", length);

	printf("%s",fileName);
	strcat(fileName, "dict");
	printf("1:%s\n", fileName);
	strcat(fileName, length);
	printf("2:%s\n", fileName);
	strcat(fileName, ".dat");
	printf("3:%s\n", fileName);
		
/*
	fp = fopen(fileName, "r");

	if(fp != NULL)
	{
		char word[lengthOfWord+1];

		while(fgets(word, sizeof(word), fp) != NULL)
		{
			fputs(word, stdout);
		}
		fclose(fp);
	}else{
		perror(fileName);
	}
*/
//	fclose(fp);
}










