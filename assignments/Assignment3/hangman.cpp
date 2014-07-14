#include <iostream>
#include <string.h>
short find(char[], char, short = 0);
using namespace std;
int main() {
    //Get secret from user
    string secretStr;
    cout << "Please enter the secret. " << endl;
    cin >> secretStr;

    const int guessesAllowed = 5;
	char guess;
	bool isWon = false;
    //Convert our secret string into a character list
	char * secret = (char*) secretStr.c_str();
	char * spaces = new char[strlen(secret) + 1];
	short spaces_size = strlen(secret) + 1;
	char wrongLetters[guessesAllowed] = {0};
	short wrongGuesses = 0;


		cout << "The secret is " << strlen(secret) << " long. "
		<< "If you guess it we'll let you free.\n"
		<< " If you guess wrong we'll hang you."
		<< endl;

	while (wrongGuesses < guessesAllowed) {
        cout << "Secret: " << spaces << " | " << "Remaining: " << guessesAllowed - wrongGuesses << " " << "You have guessed the letters : " << wrongLetters << endl;
		cin >> guess;
		short i = find(secret, guess);
		if (i != -1) {
			do {
				spaces[i] = secret[i];
				i = find(secret, guess, i++);
			} while (i != -1);
			if (strcmp(spaces, secret) == 0) {
				isWon = true;
				break;
			}
		}
		else if (find(wrongLetters, guess) == -1) {
			wrongLetters[wrongGuesses] = guess;
			++ wrongGuesses;
		}
	}

	if (isWon) {
		cout << "You win!" << endl;
    }
	else {
		cout << "You lose!" << endl;
    }
	return 0;
}

short find(char list[], char value, short offset) {
	short i = offset;

	while (i < strlen(list)) {
		if (list[i] == value) {
			return i;
        }
        i++;
	}

	return -1;
}
