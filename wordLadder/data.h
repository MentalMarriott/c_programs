#ifndef DATA_H_GUARD
#define DATA_H_GUARD 


struct word_parent
{
        //char *word[];
        struct word_parent *parent;
        char *word;
};

typedef struct word_parent w_p;

//method declarations
void readFile(int lengthOfWord);
void printArray(char** wordList, int arraySize);
struct ArrayData getWords();
void enterWords();
void validateWords(int lengthWordOne, int lengthWordTwo);
void shortestPath(int wordLength);
void printQueue();
void printAllWords(int size);
void addAllWords();
int checkIfInAllWords(char *word);
void removeFromList(char *word, char** list, int size_of_list);
void ifEndWord(char *word, struct word_parent *curr);


#endif
