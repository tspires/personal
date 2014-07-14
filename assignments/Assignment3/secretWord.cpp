#include <iostream>
#include <string.h>
short find(char list[], char value, short = 0);
using namespace std; 
int main() {
    //Temporary secret string to be converted later
    string secretStr;
    //Get secret from user
    cout << "Please enter the secret. " << endl;
    cin >> secretStr;
    const int guessesAllowed = 5;
    char guess;
    bool isWon = false;
    //Convert our secret string into a character array
    char * secret = (char*) secretStr.c_str();
    //Initialize a character array of the length of our secret so we can show the guessed word per turn
    char * preview = new char[strlen(secret) + 1];
    short preview_size = strlen(secret) + 1;
    char wrongLetters[guessesAllowed] = {0};
    short wrongGuesses = 0;
    cout << "The secret is " << strlen(secret) << " characters. " << endl;
    while (wrongGuesses < guessesAllowed) {
        cout << "Secret: " << preview << " | " << "Remaining: " << guessesAllowed - wrongGuesses << " " << "You have guessed the letters : " << wrongLetters << endl;
        cin >> guess;
        short i = find(secret, guess);
        //Loop to update preview. Stops when it can't find anymore of the guess in the secret
        if (i != -1) {
            do {
                //Replace the preview position at i with the correct guess in the secret
                preview[i] = secret[i];
                //Find the position of the guess in the secret 
                i = find(secret, guess, ++ i);
            } while (i != -1);
             
            if (strcmp(preview, secret) == 0) {
                isWon = true;
                break;
            }
        }
        else if (find(wrongLetters, guess) == -1) {
            wrongLetters[wrongGuesses] = guess;
            wrongGuesses++;
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
//A search function to find the position of value in the char array 
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
