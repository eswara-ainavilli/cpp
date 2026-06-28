#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int number, guess;
    int attempts = 3;

    srand(time(0));
    number = rand() % 100 + 1;

    cout << "=====================================\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "=====================================\n";
    cout << "I have chosen a number between 1 and 100.\n";
    cout << "You have only 3 attempts.\n\n";

    for (int i = 1; i <= attempts; i++) {
        cout << "Guess (1-100): ";
        cin >> guess;

        if (guess == number) {
            cout << "\nCongratulations! You guessed the correct number in "
                 << i << " attempt(s).\n";
            return 0;
        }
        else if (guess > number) {
            cout << "Too High!\n";
        }
        else {
            cout << "Too Low!\n";
        }

        cout << "Attempts Left: " << attempts - i << "\n\n";
    }

    cout << "Game Over!\n";
    cout << "The correct number was: " << number << endl;

    return 0;
}