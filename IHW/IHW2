#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int secretNum, 
        attempts = 0, 
        maxAttempts = 10, 
        score = 0;

    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Number Guessing Game\n";

    cout << "choose a difficulty level (1: easy, 2: medium, 3: hard): ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            secretNum = rand() % 50 + 1;
            break;
        case 2:
            secretNum = rand() % 100 + 1;
            break;
        case 3:
            secretNum = rand() % 200 + 1;
            break;
        default:
            cout << "invalid choice, setting to Medium difficulty\n";
            secretNum = rand() % 100 + 1;
            break;
    }

    while (attempts < maxAttempts) {
        int guess;
        cout << "enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == secretNum) {
            cout << "Congratulations! You guessed the number " << secretNum << " in " << attempts << " attempts.\n";
            break;
        } else if (guess < secretNum) {
            cout << "Too low. Try again.\n";
        } else {
            cout << "Too high. Try again.\n";
        }
    }

    score = max(0, maxAttempts - attempts) * 10;

    cout << "Game over! Your score: " << score << "\n";
    cout << "Thanks for playing!\n";

    return 0;
}
