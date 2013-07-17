#ifndef DATA_H_GUARD
#define DATA_H_GUARD 


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
void checkIfInAllWords(char *word);

#endif
