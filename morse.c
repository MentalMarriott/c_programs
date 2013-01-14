#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lookup(char letter);

int main(int argc, char *argv[])
{
	int size_of_word, i;

	size_of_word = strlen(argv[1]); 

	char word[size_of_word];
	strcpy(word, argv[1]);	
        
	printf("Word entered was: %s\n\n In morse code that is: \n", argv[1]);
	
	for(i = 0; i < size_of_word; i++)
	{
		printf("%c = ", word[i]);
		lookup(word[i]);
	}

	printf("\n");

	return 0;
}

void lookup(char letter)
{
	switch(letter)
	{
		case 'a' :
			printf(".- ");
			break;

                case 'b' :
			printf("-... ");
			break;

                case 'c' :
			printf("-.-. ");
			break;

                case 'd' :
			printf("-.. ");
			break;

                case 'e' :
			printf(". ");
			break;

                case 'f' :
			printf("..- ");
			break;

                case 'g' :
			printf("--. ");
			break;
	
                case 'h' : 
			printf(".... ");
			break;
		
                case 'i' : 
			printf(".. ");
			break;
		
                case 'j' :
			printf(".--- ");
			break;

                case 'k' : 
			printf("-.- ");
			break;

                case 'l' : 
			printf(".-.. ");
			break;

                case 'm' :
			printf("-- ");
			break;
		
                case 'n' :
  			printf("-. ");
			break;
		
                case 'o' : 
			printf("--- ");
			break;

                case 'p' : 
			printf(".--. ");
			break;

                case 'q' : 
			printf("--.- ");
			break;

                case 'r' : 
			printf(".-. ");
			break;

                case 's' : 
			printf("... ");
			break;

                case 't' : 
			printf("- ");
			break;

                case 'u' : 
			printf("..- ");
			break;

                case 'v' : 
			printf("...- ");
			break;

                case 'w' : 
			printf(".-- ");
			break;

                case 'x' : 
			printf("-..- ");
			break;

                case 'y' : 
			printf("-.-- ");
			break;

                case 'z' : 
			printf("--.. ");
			break;

                case '1' : 
			printf(".---- ");
			break;
	
                case '2' : 
			printf("..--- ");
			break;

                case '3' : 
			printf("...-- ");
			break;

                case '4' : 
			printf("....- ");
			break;

                case '5' : 
			printf("..... ");
			break;

                case '6' : 
			printf("-.... ");
			break;

                case '7' : 
			printf("--... ");
			break;

                case '8' : 
			printf("---.. ");
			break;

                case '9' : 
			printf("----. ");
			break;

                case '0' : 
			printf("----- ");
			break;

                default :
			printf(" ");
			break;

	}
}
