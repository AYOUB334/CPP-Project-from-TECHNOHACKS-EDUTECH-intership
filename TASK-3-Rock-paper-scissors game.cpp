#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation

    char choice;
    int computerChoice;
    int userScore = 0, computerScore = 0;

    cout << "Welcome to the Rock, Paper, Scissors game!\n";

    do {
        cout << "Enter your choice (R for Rock, P for Paper, S for Scissors, Q to quit): ";
        cin >> choice;

        if (choice == 'Q' || choice == 'q') {
            break; // Exit the game if the user chooses to quit
        }

        // Generate computer's choice
        computerChoice = rand() % 3; // 0 for Rock, 1 for Paper, 2 for Scissors

        // Determine winner
        if ((choice == 'R' || choice == 'r') && computerChoice == 2 ||
            (choice == 'P' || choice == 'p') && computerChoice == 0 ||
            (choice == 'S' || choice == 's') && computerChoice == 1) {
            cout << "You win!\n";
            userScore++;
        } else if ((choice == 'R' || choice == 'r') && computerChoice == 1 ||
                   (choice == 'P' || choice == 'p') && computerChoice == 2 ||
                   (choice == 'S' || choice == 's') && computerChoice == 0) {
            cout << "Computer wins!\n";
            computerScore++;
        } else {
            cout << "It's a tie!\n";
        }

        cout << "Your score: " << userScore << ", Computer's score: " << computerScore << endl;
    } while (true);

    cout << "Thanks for playing!\n";

    return 0;
}
