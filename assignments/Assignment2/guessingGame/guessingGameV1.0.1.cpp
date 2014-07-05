#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;

//Function Prototypes
bool isWon(int guess, int secret);
string processInequality(int guess, int secret);
int processMax(int guess, int rangeMax, int rangeMin, int secret);
int processMin(int guess, int rangeMax, int rangeMin, int secret);
int processClosest(int guess, int closest, int secret); 
int processDifference(int guess, int secret);
//Primary game data struct
struct Game {
	int allowedGuesses;
	int secret;
	int guess;
	int guesses;
	int closest;
	int remaining;
	int rangeMax;
	int rangeMin;
	bool isWon;
};

int main() {
	Game game;
	game.allowedGuesses = 4;
	game.guesses = 0;
	//EXECUTION
	cout << "Player 1, please enter a secret for Player 2 to guess. " << endl;
	cin >> game.secret;
	//Range is secret +- 50%
	game.rangeMax = game.secret * 1.5;
	game.rangeMin = game.secret * .5;
	cout << endl << "Player 2 the game is starting! " << endl;
	cout << "You have " << game.allowedGuesses << " guesses." << endl;
	while ((game.guess != game.secret) && ((game.allowedGuesses - game.guesses) > 0)) {
		game.remaining = game.allowedGuesses - game.guesses;
		game.guesses++;
		game.rangeMax = processMax(game.guess,game.rangeMax, game.rangeMin, game.secret);
		game.rangeMin = processMin(game.guess, game.rangeMax, game.rangeMin, game.secret);
		cout << "**********************************************" << endl;
		cout << "The secret is between " << game.rangeMin << " and " << game.rangeMax << endl;
		cout << "Enter a number to guess (You have " << game.remaining << " guesses remaining): " << endl;
		cin >> game.guess;
        game.closest = processClosest(game.guess, game.closest, game.secret);
		cout << "Your guess was " << processInequality(game.guess,game.secret) << " Player 1's secret!" << endl;
	}
	game.remaining = game.allowedGuesses - game.guesses;
	game.isWon = isWon(game.guess, game.secret);
    game.closest = processClosest(game.guess, game.closest, game.secret);
	if (game.isWon)
		cout << "CONGRATULATIONS!! You won!!" << endl;
	else if (!game.isWon)
		cout << "Sorry, you lost." << endl;
	cout << "You took " << game.guesses << " guesses and had " << game.remaining << " guesses remaining. " << endl;
	cout << "Your closest guess was " << game.closest << " and the secret was " << game.secret << endl;
}

bool isWon(int guess, int secret) {
	if (guess == secret) {
		return true;
	}
	else {
		return false;
	}
}
//Function to determine the guesses linear relationship to the secret
string processInequality(int guess, int secret) {
	if (guess == secret)
		return "equal to";
	else if (guess > secret)
		return "greater than";
	else if (guess < secret) 
		return "less than";
}

int processMax(int guess, int rangeMax, int rangeMin, int secret) {
	if ((guess < rangeMax) && (guess > rangeMin) && (guess > secret))
		rangeMax = guess;
	return rangeMax;
}

int processMin(int guess, int rangeMax, int rangeMin, int secret) {
	if ((guess < rangeMax) && (guess > rangeMin) && (guess < secret))
                rangeMin = guess;
	return rangeMin;
}

int processDifference(int guess, int secret) {
	return secret - guess;
}

int processClosest(int guess, int closest, int secret) {
    int guessDelta = secret - guess;
    int closestDelta = secret - closest;
    if (abs(guessDelta) < abs(closestDelta)) {
        cout << "Setting closest to " << guess << endl;
        return guess;
    }
    else {
        return closest;
    }
}
