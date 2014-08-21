#include <iostream>
#include <sstream>
#include <string>
std::string ctos(char c);
void repeat( void (*f)() );
bool in(std::string x, std::string y[]);
void run();
int main() {
    repeat(run);
    return 0;
}
//Function: run
//Description: 
void run() {
    
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
