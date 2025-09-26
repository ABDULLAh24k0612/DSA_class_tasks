#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void guessNumber(int target, string players[], int playerCount, int currentPlayerIndex = 0) {
    string currentPlayer = players[currentPlayerIndex];
    int guess;

    
    cout << currentPlayer << ", enter your guess (1-100): ";
    cin >> guess;

    
    if (cin.fail() || guess < 1 || guess > 100) {
        cin.clear();
        cin.ignore(1000, '\n'); 
        cout << "Invalid input. Please enter a number between 1 and 100.\n";
        guessNumber(target, players, playerCount, currentPlayerIndex); 
        return;
    }

   
    if (guess == target) {
        cout << currentPlayer << "! You guessed the correct number: " << target << endl;
        return; 
    } else if (guess < target) {
        cout << "Too low!\n";
    } else {
        cout << "Too high!\n";
    }

    
    int nextPlayerIndex = (currentPlayerIndex + 1) % playerCount;

  
    guessNumber(target, players, playerCount, nextPlayerIndex);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int targetNumber = rand() % 100 + 1; 

    
    string players[2] = {"Alice", "Bob"};
    int playerCount = 2; 

    cout << "🎯 Welcome to the Number Guessing Game!\n";
    cout << "Players take turns to guess a number between 1 and 100.\n";

   
    guessNumber(targetNumber, players, playerCount);

    return 0;
}
