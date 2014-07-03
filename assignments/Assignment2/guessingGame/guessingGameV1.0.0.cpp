#include <iostream>
#include <string>
using namespace std;

string processStatus(int guess, int number);
string processInequality(int guess, int number);
int processMax(int guess, int rangeMax, int rangeMin, int number);
int processMin(int guess, int rangeMax, int rangeMin, int number);
int main() {
	//DECLERATION
	const int ALLOWED_GUESSES = 5;
	int number;
	int guess;
	int guesses = 0;
	int remaining = 0;
	static int rangeMax;
	static int rangeMin;
	string status;
	//EXECUTION
	cout << "Please enter a number for Player 2 to guess. " << endl;
	cin >> number;
	//Range is number +- 50%
	rangeMax = number * 1.5;
	rangeMin = number * .5;
	cout << endl << "Player 2 the game is starting! " << endl;
	cout << "You have " << ALLOWED_GUESSES << " guesses." << endl;
	while ((guess != number) && (ALLOWED_GUESSES - guesses > 0)) {
		remaining = ALLOWED_GUESSES - guesses;
		guesses++;
		rangeMax = processMax(guess,rangeMax, rangeMin, number);
		rangeMin = processMin(guess, rangeMax, rangeMin, number);
		cout << "**********************************************" << endl;
		cout << "The number is between " << rangeMin << " and " << rangeMax << endl;
		cout << "Enter a number to guess (You have " << remaining << " guesses remaining): " << endl;
		cin >> guess;
		cout << "Your guess was " << processInequality(guess,number) << " Player 1's number!" << endl;
	}
	remaining--;
	status = processStatus(guess,number);
	cout << "Game over! You " << status << " with " << guesses << " guesses taken and " << remaining << " guesses remaining. " << endl;
}

string processStatus(int guess, int number) {
	if (guess == number) {
		return "WON";
	}
	else {
		return "LOST";
	}
}

string processInequality(int guess, int number) {
	if (guess == number)
		return "equal to";
	else if (guess > number)
		return "greater than";
	else if (guess < number) 
		return "less than";
}

int processMax(int guess, int rangeMax, int rangeMin, int number) {
	if ((guess < rangeMax) && (guess > rangeMin) && (guess > number))
		rangeMax = guess;
	return rangeMax;
}

int processMin(int guess, int rangeMax, int rangeMin, int number) {
	if ((guess < rangeMax) && (guess > rangeMin) && (guess < number))
                rangeMin = guess;
	return rangeMin;
}

