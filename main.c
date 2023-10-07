#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LETTERS_TO_KEEP 3

void checkLetter(char word[], int *randomIndices, char letter)
{
    // First check if letter is in word,
    // If letter exists, replace _ with that letter at the right index.
}

int hasValue(int *array, int arrayLength, int val)
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (*(array + i) == val)
        {
            return 1;
        }
    }
    return 0;
}

int *getRandomIndices(int stringLength)
{
    static int randomIndices[50];

    for (int j = 0; j < 50; j++)
    {
        randomIndices[j] = 999;
    }

    srand(time(0));
    for (int i = 0; i < stringLength - LETTERS_TO_KEEP; i++){
        starting:
            int random_index = rand() % stringLength;
            printf("i is %d and random_index is %d\n", i, random_index);
            if (hasValue(randomIndices, (sizeof(randomIndices) / sizeof(randomIndices[0])), random_index) == 1)
                goto starting;
        randomIndices[i] = random_index;
        printf("Ending loop\n");
    }
    return randomIndices;
}

void wordCreator(char word[]) {
    int stringLength = strlen(word);
    int *randomIndices = getRandomIndices(stringLength);

    for (int i = 0; i < stringLength - LETTERS_TO_KEEP; i++) {
        int randomIndex = *(randomIndices + i);
        *(word + randomIndex) = '_';
    }
}

int main() {

    // int user_input, name_len;
    // char name[] = "Pikachu";
    // name_len = strlen(name);
    static char name[] = "Prayag";
    wordCreator(name);
    printf("%s", name);
    return 0;
}
