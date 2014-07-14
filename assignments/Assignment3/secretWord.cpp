#include <iostream>
#include <string.h>
 
short linear_search(char[], char, short = 0);
#define VERSIONSTRING "Hangman [Version 1]"
#define GUESSLIMIT 8
using namespace std; 
int main(char argc, char * argv[]) {
 
char guess;
bool guessed_it = false;
char * secret = argv[1];
char * blanks = new char[strlen(secret) + 1];
short blanks_size = strlen(secret) + 1;
char wrong_letters[GUESSLIMIT] = {0};
short wrong_guesses = 0;
 
blanks[blanks_size - 1] = '\0';
memset(blanks, '_', blanks_size - 1);
 
std::cout << VERSIONSTRING << "\n\n"
<< "The secret is " << strlen(secret) << " long. "
<< "If you guess it we'll let you free.\n"
<< " If you guess wrong we'll hang you."
<< std::endl;
 
while (wrong_guesses < GUESSLIMIT) {
std::cout << "Word: " << blanks << " | "
<< "Hearts: " << GUESSLIMIT - wrong_guesses << " "
<< "Said letters [" << wrong_letters << "]"
<< std::endl;
 
std::cout << "Guess> ";
std::cin >> guess;
 
short index = linear_search(secret, guess);
 
if (index != -1) {
do {
blanks[index] = secret[index];
index = linear_search(secret, guess, ++ index);
 
} while (index != -1);
 
if (strcmp(blanks, secret) == 0) {
guessed_it = true;
break;
}
}
else if (linear_search(wrong_letters, guess) == -1) {
wrong_letters[wrong_guesses] = guess;
++ wrong_guesses;
}
}
 
if (guessed_it)
std::cout << "You're free!" << std::endl;
else
std::cout << "They hung you!" << std::endl;
return 0;
}
 
short linear_search(char array[], char key, short offset) {
short index = offset;
 
while (index < strlen(array)) {
if (array[index] == key)
return index;
++ index;
}
 
return -1;
}
