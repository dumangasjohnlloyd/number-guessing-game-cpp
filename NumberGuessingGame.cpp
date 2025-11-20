#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void handleInput();

int main() {
    int difficulty;
    int easy = 100, medium = 500, hard = 1000;
    char playAgainSelection;
    int difficultySelection;

    //Don't forget to add asci colors after adding input handling

    while (true) {
        cout << "\n===\033[34m Number\033[0m \033[32mGuessing\033[0m \033[33mGame\033[0m ===" << endl;
        cout << "Select a difficulty:\n";
        cout << "\033[33m[1] Easy\033[0m\n";
        cout << "\033[32m[2] Medium\033[0m\n";
        cout << "\033[35m[3] Hard\033[0m\n";
        while (true) {
            cout << "Enter your selection: ";
            if (!(cin >> difficultySelection)) {
                handleInput();
                continue;
            } else if ( difficultySelection < 1 || difficultySelection > 3 ){
                cout << "\033[31m Invalid selection. Please try again!\033[0m\n";
                continue;
            }            
            else {
                break;
            }
        }

        switch (difficultySelection) {
            case 1: 
                difficulty = easy;
                break;
            
            case 2:
                difficulty = medium;
                break;
            
            case 3: 
                difficulty = hard;
        }
        
        //Seed the random number generator.
        srand(time(0));

        //Generate a random number between 1 and 100
        int secretNumber = rand() % difficulty + 1;
        int guess;
        int attempts = 0;

        cout << "\n===\033[34m Number\033[0m \033[32mGuessing\033[0m \033[33mGame\033[0m ===" << endl;
        cout << "I have selected a number between 1 and " << difficulty << ". Can you guess it?\n";
        cout << "You have 10 attempts. \n \n";

        //TODO: Use a loop to keep asking the player for guesses until they guess correctly
        while (attempts < 10) {
            cout << "Enter your guess: ";
            if (!(cin >> guess)) {
                handleInput();
                continue;
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

        if (attempts == 10)
            cout << "\n\033[35m Out of attempts! The number was: " << secretNumber << "\033[0m\n\n";

        while (true) {
            cout << "Play again? ( y / n ): ";
            cin >> playAgainSelection;

            if (playAgainSelection == 'y' || playAgainSelection == 'n' ) {
                break;
            } else {
                cout << "\033[31mInvalid input.\033[0m Please enter 'y' or 'n'.\n" << endl;
            }
        }

        if(playAgainSelection == 'y') {
            cout << "\n\033[32m Restarting game...\033[0m \n\n";
        } else {
            cout << "\nThanks for playing!\n";
            break;
        }
    }

    
    return 0;
}

void handleInput() {
    cout << "\033[31m Invalid input! \033[0m";
    cout << "Please enter a number.\n ";
    cin.clear();
    cin.ignore(1000, '\n');
}