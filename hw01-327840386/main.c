#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    void playGame(int round, int* totalGuesses);

    srand(time(NULL));
    
    const int ROUNDS = 5;

    int totalGuesses[5] = {0};

    for (int round = 0; round < ROUNDS; round++) {
        playGame(round, totalGuesses);
    }

    // Output summary after 5 rounds
    printf("=================================\n");
    printf("|Here are the results of your guessing abilities|\n");
    printf("=================================\n");
    for (int i = 0; i < ROUNDS; i++) {
        printf("Game %d took you %d guesses\n", i, totalGuesses[i]);
    }

    return 0;
}

void playGame(int round, int* totalGuesses) {
    printf("==========================\n");
    printf("CPU Says: Pick a number 1-10\n");
    printf("==========================\n");

    int targetNumber = rand() % 10 + 1;
    int guess;
    int guesses = 0;

    do {
        printf("Make a guess:");
        scanf("%d", &guess);

        guesses++;

        if (guess < targetNumber) {
            printf("No guess higher!\n");
        } else if (guess > targetNumber) {
            printf("No guess lower!\n");
        } else {
            printf("You got it!\n");
        }
    } while (guess != targetNumber);

    totalGuesses[round] = guesses;
}
