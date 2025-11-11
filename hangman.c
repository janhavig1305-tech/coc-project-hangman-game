#include <stdio.h>
#include <string.h>

int main() {
    char secret_word[] = "CLASH"; // The secret word
    char display_word[6];  // To show progress (5 letters + '\0')
    int lives = 5;  // Number of chances
    char guess;  // Player's guessed letter
    int i, correct;
// Step 1: Fill display_word with underscores
    for (i = 0; i < strlen(secret_word); i++) {
        display_word[i] = '_';
    }
    display_word[strlen(secret_word)] = '\0';  // End of string

    printf("Welcome to the Word Guessing Game!\n");
// Step 2: Main game loop
    while (lives > 0) {
        printf("\nWord: %s\n", display_word);
        printf("Lives left: %d\n", lives);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        correct = 0;  // assume wrong

        // Step 3: Check if guessed letter is in the word
        for (i = 0; i < strlen(secret_word); i++) {
            if (secret_word[i] == guess) {
                display_word[i] = guess;
                correct = 1;
            }
        }
// Step 4: Display message for guess
        if (correct == 1) {
            printf("Good guess!\n");
        } else {
            printf("Wrong guess!\n");
            lives--;
        }
// Step 5: Show updated word
        printf("Word: %s\n", display_word);
// Step 6: Check if the word is fully guessed
        if (strcmp(secret_word, display_word) == 0) {
            printf("\nCongratulations! You won! The word was: %s\n", secret_word);
            break;
        }
    }
// Step 7: If all lives are lost
    if (lives == 0) {
        printf("\nYou lost! The word was: %s\n", secret_word);
    }

    return 0;
}
