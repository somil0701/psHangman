#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LETTERS_TO_KEEP 3


void drawScoreboard(int score){
    printf("+-------------+-----+\n");
    printf("| SCORE BOARD |  %d  |\n", score);
    printf("+-------------+-----+\n");
}


void drawHangMan(int hangman_value){
    char hangman[][50] = {
        "-----\n  |\n", "  o  \n", " /", "|", "\\ \n", "  |  \n", " /", " \\ \n"
    };

    printf(hangman[0]);
    for (int i = 1; i<hangman_value; i++)
        printf("%s", hangman[i]);
}


int checkLetter(char originalWord[], char modifiedWord[], int *randomIndices, char letter, int randomIndicesLength)
{
    for (int i = 0; i < randomIndicesLength; i++)
    {
        if (letter == originalWord[randomIndices[i]] && randomIndices[i] != -1)
        {
            modifiedWord[randomIndices[i]] = letter;
            randomIndices[i] = -1;
            return 1;
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
    char words[][50] = {"PIKACHU", "BULBASAUR", "CHARMANDER", "SQUIRTLE", "IVYSAUR", "VENUSAUR", "CHARMANDER", "CHARMELEON", "CHARIZARD", "BLASTOISE"};
    int user_score = 0;

    while (1){
        beginning:
            system("clear");
            srand(time(0));
            int random_number = rand() % 10;
            char currentWord[30], originalWord[30];

            strcpy(currentWord, words[random_number]);
            strcpy(originalWord, currentWord);

            int hangman_value = 0;
            int randomIndices[50];
            int randomIndicesLength = sizeof(randomIndices)/sizeof(randomIndices[0]);

            wordCreator(currentWord, randomIndices, randomIndicesLength);

        do {
            drawScoreboard(user_score);
            drawHangMan(hangman_value);
            if (hangman_value == 8) {
                user_score--;
                goto beginning;
            }

            printf("\n%s\n", currentWord);
            scanf("\n%c", &user_input);
            if(checkLetter(originalWord, currentWord, randomIndices, user_input, randomIndicesLength) == 0) {

                hangman_value += 1;
                printf("\n");
            }
            system("clear");
        } while (strcmp(currentWord, originalWord));

        user_score += 1;
        printf("%s\n", currentWord);
    }
    return 0;
}
