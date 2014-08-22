#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

#include "guessing.h"

const std::string APPLICATION_NAME = "Game Menu";

std::string ctos(char c);
void repeat( void (*f)() );
bool in(std::string x, std::string y[]);
void run();
void displayMenu();
void clear();
void parseInput();
bool validate(std::string input);

void helloWorld();
void echo();
void guessing();

int main() {
    repeat(run);
    return 0;
}
//Function: run
//Description: 
void run() {
    displayMenu();
    parseInput();
}
//Function: displayMenu
//Description: The function contains the definition of the menu and displays the menu
void displayMenu() {
    clear();
    std::cout << APPLICATION_NAME << std::endl;
    std::cout << "1. Hello World " << std::endl;
    std::cout << "2. Echo " << std::endl;
    std::cout << "3. Number Guessing " << std::endl;
    std::cout << "4. Quit " << std::endl;
    std::cout << std::endl;
    std::cout << "Selection: ";
}

void parseInput() {
    char resp;
    std::cin >> resp;
    if (isdigit(resp)){
        switch(resp) {
            case '1':
                clear();
                helloWorld();
                break;
            case '2':
                clear();
                echo();
                break;
            case '3':
                clear();
                guessing();
                break;
            case '4':
                clear();
                break;
        }
    }
    else {
        std::cout << "Invalid input! Please enter a number" << std::endl;
    }
}

//Function: repeat
//Description: The repeat function calls the function that is passed to it
//on a continuous loop as long as the user responds affirmative
void repeat( void (*f)() ) {
    std::string affirmative[] = {"y","yes"};
    char response;
    do {
        (*f)();
        std::cout << "Would you like to continue? [y/n] ";
        std::cin >> response;
    } while (in(ctos(response),affirmative));
}
//Function: in
//Description: The in function checks if a string value is present in an 
//array of strings
bool in(std::string x, std::string y[]) {
    for (int i = 0; i < y->length(); i++) {
        if (x == y[i]) {
            return true;
        }
    }
    return false;
}
//Function: ctos
//Description: The ctos function converts a char to a string
std::string ctos(char c) {
    std::stringstream ss;
    std::string s;
    ss << c;
    ss >> s;
    return s;
}

void clear() {
    system("clear");   
}
void helloWorld() {
    std::cout << "Hello World!" << std::endl;
}
void echo() {
    std::string input;
    std::cout << "Echo" << std::endl;
    std::cout << "Enter text: ";
    std::cin.ignore();
    std::getline(std::cin,input);
    if (validate(input)) {
        std::cout << input << std::endl;
    }
    else {
        std::cout << "Invalid input!" << std::endl;
    }
}

bool validate(std::string input) {
    return true;

}
