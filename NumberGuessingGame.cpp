#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void handleInput();

int main() {
    //Seed the random number generator.
    srand(time(0));

    //Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;
    char playAgainSelection;

    cout << "===\033[34m Number\033[0m \033[32mGuessing\033[0m \033[33mGame\033[0m ===" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess it?\n";
    cout << "You have 10 attempts. \n \n";

    //TODO: Use a loop to keep asking the player for guesses until they guess correctly
    while (attempts < 10) {
        cout << "Enter your guess: ";
        if (!(cin >> guess)) {
            handleInput();
        }

        attempts++;

        if(guess > secretNumber) {
            cout << "\033[33m Too high! \033[0m\n";
        } else if (guess < secretNumber) {
            cout << "\033[34m Too low! \033[0m\n";
        } else {
            cout << "\033[32m Correct! You guessed it in " << attempts << " attempts. \033[0m \n \n";
            break;
        }
    }

    cout << "Thanks for playing!" << endl << endl;

    while (true) {
        cout << "Play again? ( y / n ): ";
        cin >> playAgainSelection;

        if (playAgainSelection == 'y' || playAgainSelection == 'n' ) {
            if(playAgainSelection == 'y') {
                //restart the game
            } else {
                break;
            }

        } else {
            cout << "Invalid input. Please enter 'y' or 'n'. " << endl;
        }
    }
    return 0;
}

void handleInput() {
    cout << "\033[31m Invalid input! \033[0m";
    cout << "Please enter a number: ";
    cin.clear();
    cin.ignore(1000, '\n');
}