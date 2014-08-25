#include <iostream>
#include <string.h>
using namespace std; 
short find(char list[], char value, short = 0);
bool isValidWord(string word);
bool isValidLetter(char c);
int main() {
    //Temporary secret string to be converted later
    string secretStr;
        const int guessesAllowed = 5;
    char wrongcs[guessesAllowed] = {0};
    short wrongGuesses = 0;
    bool done = false;
    while (!done) {
         //Get secret from user
        cout << "Please enter the secret. " << endl;
        cin >> secretStr;
        cout << string(50,'\n');
        char guess;
        bool isWon = false;
        //Convert our secret string into a character array
        char * secret = (char*) secretStr.c_str();
        //Initialize a character array of the length of our secret so we can show the guessed word per turn
        char * preview = new char[strlen(secret) + 1];
        short preview_size = strlen(secret) + 1;
        cout << "The secret is " << strlen(secret) << " characters. " << endl;
        if (isValidWord(secret)){
            while (wrongGuesses < guessesAllowed) {
                cout << "Secret: " << preview << " | " << "Remaining: " << guessesAllowed - wrongGuesses << " " << "You have guessed the cs : " << wrongcs << endl;
                cin >> guess;
                if (isValidLetter(guess)) {
                    short i = find(secret, guess);
                    //Loop to update preview. Stops when it can't find anymore of the guess in the secret
                    if (i != -1) {
                        do {
                            cout << "Found the letter " << guess << "!" << endl;
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
                    else if (find(wrongcs, guess) == -1) {
                        wrongcs[wrongGuesses] = guess;
                        wrongGuesses++;
                    }
                }
                else {
                    cout << "Invalid guess!" << endl;
                }
            }
        }
        else {
            cout << "Invalid secret word!" << endl;
        }
        if (isWon) {
            cout << "You win!" << endl;
        }
        else {
            cout << "You lose!" << endl;
        }
        char response;
        cout << "Would you like to play again? [y/n]" << endl;
        cin >> response;
        if (response == 'n')
            done = true;
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

bool isValidWord(string word) {
    char c;
    for (int i = 0; i < word.length(); i++){
        c = word.at(i);
        if (!((c <= 'z' && c >= 'a') || ((c <= 'Z') && c >= 'A')))
            return false;
    }
    return true;
}

bool isValidLetter(char c) {
    if (!((c <= 'z' && c >= 'a') || ((c <= 'Z') && c >= 'A')))
        return false;
    else
        return true;
}
