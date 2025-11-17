#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
        cin >> guess;

        //TODO: Add input validation here
        //Hint: check if cin failed

        attempts++;

        // TODO: Compare guess to secretNumber
        // If guess is too low, print "Too low!"
        // If guess is correct, print "Congratulations! You guessed it in X attempts!" and break the loop 
        if(guess > secretNumber) {
            cout << "Too high!";
        } else if (guess < secretNumber) {
            cout << "Too low!";
        } else {
            cout << "Correct!";
            break;
        }
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}