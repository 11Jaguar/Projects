#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a prefix for error messages
#define ERROR_PREFIX "ERROR: "   // A message prefix instead of a color
#define RESET "\033[0m"          // Reset to default color (used for other text formatting)

// Function to choose a subject
void chooseSubject(char subject) {
    switch (subject) {
        case 'M':
        case 'm':
            printf("Enjoy Studying MATHEMATICS.\n");
            break;
        case 'A':
        case 'a':
            printf("Enjoy Studying APPLIED PHYSICS.\n");
            break;
        case 'P':
        case 'p':
            printf("Enjoy Studying PROGRAMMING LANGUAGE.\n");
            break;
        case 'E':
        case 'e':
            printf("Enjoy Studying ENGINEERING GRAPHICS.\n");
            break;   
        case 'B':
        case 'b':
            printf("Enjoy Studying BASICS OF ELECTRICAL TECHNOLOGY.\n");
            break; 
        default:
            printf(ERROR_PREFIX "Invalid subject input! Please enter M, A, P, E or B.\n");
    }
}

// Function to choose a sport
void chooseSport(char sport) {
    switch (sport) {
        case 'F':
        case 'f':
            printf("Enjoy Playing FOOTBALL.\n");
            break;
        case 'B':
        case 'b':
            printf("Enjoy Playing BASKETBALL.\n");
            break;
        case 'T':
        case 't':
            printf("Enjoy Playing TENNIS.\n");
            break;
        case 'C':
        case 'c':
            printf("Enjoy Playing CRICKET.\n");
            break;   
        case 'V':
        case 'v':
            printf("Enjoy Playing VOLLEYBALL.\n");
            break; 
        default:
            printf(ERROR_PREFIX "Invalid sport input! Please enter F, B, T, C or V.\n");
    }
}

// Simple number guessing game
void numberGuessingGame() {
    int randomNumber, guess, attempts = 0;
    const int MAX_ATTEMPTS = 5;

    // Seed the random number generator
    srand(time(0));
    randomNumber = rand() % 100 + 1; // Random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess the number.\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts.\n", randomNumber, attempts);
            return; // Exit the game if guessed correctly
        }
    }
    printf("Sorry! You've used all your attempts. The correct number was %d.\n", randomNumber);
}

int main() {
    int switchState;
    char input;

    while (1) { // Infinite loop to allow repeated interaction
        // Prompt the user for the switch state
        printf("Do you want to study a subject? (0 for NO, 1 for YES, any other key to exit): ");
        if (scanf("%d", &switchState) != 1) {
            break; // Exit loop on invalid input
        }

        // Check the input for switch state
        if (switchState == 0) {
            printf("You have chosen not to study.\n");

            // Prompt the user to play a sport instead
            printf("Would you like to play a sport? (1 for YES, 0 for NO): ");
            scanf(" %c", &input);
            
            if (input == '1') {
                // Present sports options to the user
                printf("You can choose a sport by pressing:\n");
                printf("F for FOOTBALL\n");
                printf("B for BASKETBALL\n");
                printf("T for TENNIS\n");
                printf("C for CRICKET\n");
                printf("V for VOLLEYBALL\n");
                printf("Enter the desired sport (F, B, T, C or V): ");
                scanf(" %c", &input); // Note the space before %c to consume any whitespace

                // Choose the sport
                chooseSport(input);
                printf("\n"); // Additional line break for clarity
            } else {
                printf("You have chosen not to play a sport.\n");
                // Start the guessing game
                numberGuessingGame();
            }
        } else if (switchState == 1) {
            printf("You are ready to study!\n");

            // Present subject options to the user
            printf("You can choose a subject by pressing:\n");
            printf("M for MATHEMATICS\n");
            printf("A for APPLIED PHYSICS\n");
            printf("P for PROGRAMMING LANGUAGE\n");
            printf("E for ENGINEERING GRAPHICS\n");
            printf("B for BASICS OF ELECTRICAL TECHNOLOGY\n");
            printf("Enter the desired subject (M, A, P, E or B): ");
            scanf(" %c", &input); // Note the space before %c to consume any whitespace

            // Choose the subject
            chooseSubject(input);
            printf("\n"); // Additional line break for clarity
        } else {
            printf(ERROR_PREFIX "Invalid input! Please enter 0 or 1.\n");
            return 1; // Exit the program on invalid input
        }
    }

    printf("Thank you for using the study and sport selector. Goodbye!\n");
    return 0;
}
