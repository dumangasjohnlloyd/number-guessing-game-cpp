#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void handleInput();

int main() {
    //Seed the random number generator.
    srand(time(0));

    //Generate a random number between 1 and 100
    int secretNumber = rand() % 1000 + 1;

    int guess;
    int attempts = 0;

    cout << "=== Number Guessing Game ===" << endl;
    cout << "I have selected a number between 1 and 1000. Can you guess it?\n";
    cout << "You have 10 attempts.";

    //TODO: Use a loop to keep asking the player for guesses until they guess correctly
    while (attempts < 10) {
        cout << "Enter your guess: ";
        if (!(cin >> guess)) {
            handleInput();
        }

        attempts++;

        if(guess > secretNumber) {
            cout << "Too high!\n";
        } else if (guess < secretNumber) {
            cout << "Too low!\n";
        } else {
            cout << "Correct! You guessed it in " << attempts << " attempts. \n \n";
            break;
        }
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}

void handleInput() {
    cout << "\033[31m Invalid input! \033[0m";
    cout << "Please enter a number: ";
    cin.clear();
    cin.ignore(1000, '\n');
}