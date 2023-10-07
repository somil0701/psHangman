#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LETTERS_TO_KEEP 3

void checkLetter(char originalWord[], char modifiedWord[], int *randomIndices, char letter, int randomIndicesLength)
{
    for (int i = 0; i < randomIndicesLength; i++)
    {
        if (letter == originalWord[randomIndices[i]])
        {
            modifiedWord[randomIndices[i]] = letter;
            break;
        }
    }
}


int hasValue(int *array, int arrayLength, int val)
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (array[i] == val)
        {
            return 1;
        }
    }
    return 0;
}


void getRandomIndices(int stringLength, int *randomIndices, int randomIndicesLength)
{
    for (int j = 0; j < randomIndicesLength; j++)
    {
        randomIndices[j] = 999;
    }

    srand(time(0));
    for (int i = 0; i < stringLength - LETTERS_TO_KEEP; i++){
        starting:
            int random_index = rand() % stringLength;
            if (hasValue(randomIndices, randomIndicesLength, random_index) == 1)
                goto starting;
        randomIndices[i] = random_index;
    }
}


int* wordCreator(char word[], int *randomIndices, int randomIndicesLength) {
    int stringLength = strlen(word);
    getRandomIndices(stringLength, randomIndices, randomIndicesLength);
    for (int i = 0; i < stringLength - LETTERS_TO_KEEP; i++) {
        word[randomIndices[i]] = '_';
    }
    return randomIndices;
}


int main() {

    char user_input;

    char currentWord[] = "pikachu";
    char originalWord[] = "pikachu";
    int randomIndices[50];
    int randomIndicesLength = sizeof(randomIndices)/sizeof(randomIndices[0]);
    wordCreator(currentWord, randomIndices, randomIndicesLength);

    do {
        printf("%s\n", currentWord);
        scanf("\n%c", &user_input);
        checkLetter(originalWord, currentWord, randomIndices, user_input, randomIndicesLength);
    } while (strcmp(currentWord, originalWord));

    printf("%s\n", currentWord);
    
    return 0;
}
