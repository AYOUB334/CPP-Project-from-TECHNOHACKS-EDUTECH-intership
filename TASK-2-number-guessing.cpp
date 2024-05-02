#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation
    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Try to guess a number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low. Try again.\n";
        } else if (guess > secretNumber) {
            cout << "Too high. Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number " << secretNumber << " correctly!\n";
            cout << "Number of attempts: " << attempts << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
