#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LETTERS_TO_KEEP 3

void drawHangMan(int hangman_value){
    char hangman[][50] = {
        "-----\n  |\n", "  o  \n", " /", "|", "\\ \n", "  |  \n", " /", " \\ \n"
    };

    for (int i = 0; i<hangman_value; i++)
        printf("%s", hangman[i]);
}

int checkLetter(char originalWord[], char modifiedWord[], int *randomIndices, char letter, int randomIndicesLength)
{
    for (int i = 0; i < randomIndicesLength; i++)
    {
        if (letter == originalWord[randomIndices[i]])
        {
            modifiedWord[randomIndices[i]] = letter;
            return 1;
            break;
        }
    }
    return 0;
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
    int hangman_value = 0;
    int temp;
    char currentWord[] = "PIKACHU";
    char originalWord[] = "PIKACHU";
    int randomIndices[50];
    int randomIndicesLength = sizeof(randomIndices)/sizeof(randomIndices[0]);
    wordCreator(currentWord, randomIndices, randomIndicesLength);

    do {
        if (hangman_value == 8)
            break;
        
        printf("\n%s\n", currentWord);
        scanf("\n%c", &user_input);
        temp = checkLetter(originalWord, currentWord, randomIndices, user_input, randomIndicesLength);

        if (temp == 0)
            hangman_value += 1;
            printf("\n");
        drawHangMan(hangman_value);
        
        
    } while (strcmp(currentWord, originalWord));

    printf("%s\n", currentWord);
    
    return 0;
}
