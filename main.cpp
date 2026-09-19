#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator using current time
    srand(time(0));
    
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "=======================================" << endl;
    cout << "      WELCOME TO NUMBER GUESSING GAME   " << endl;
    cout << "=======================================" << endl;
    cout << "I have chosen a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?\n" << endl;

    // Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Input validation
        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(10000, '\n'); // Ignore invalid input
            cout << "Invalid input! Please enter a valid number.\n" << endl;
            continue;
        }

        attempts++;

        if (userGuess > randomNumber) {
            cout << "Too High! Try guessing a lower number.\n" << endl;
        } else if (userGuess < randomNumber) {
            cout << "Too Low! Try guessing a higher number.\n" << endl;
        } else {
            cout << "\n---------------------------------------" << endl;
            cout << "🎉 Congratulations! You guessed the correct number!" << endl;
            cout << "Total attempts taken: " << attempts << endl;
            cout << "---------------------------------------" << endl;
        }
    }

    return 0;
}