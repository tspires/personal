#include <iostream>
#include <map>
#include <sstream>
#include <stdlib.h>
void clear();
std::string ctos(char c); 
bool in(std::string x, std::string y[]);
bool validate(char in);
//-----------------------------------------------------------------------
//Requirement #26: Demonstrate "something awesome." I rewrote the menu application
//to be highly reusable. As a working developer, I think this is awesome. This is the 
//embodiement of Don't Repeat Yourself. Code like this is what makes it possible for me 
//to focus on my job and not on writing low level functionality
//that shouldn't be re-written every time I need it. In any event, as I was doing the menu application
//I was thinking that it could be done in a really reusable way and after thinking about it for
//a few days I put it together here and was very pleased with myself.
//-----------------------------------------------------------------------
//Class Name: MenuItem
//Description : The Menu Item represents a single option in the menu.
//It has content, the text which is displayed for the option, and 
//it has a function to be execute for the option which is set when
//the menu is built from its parent application
//-----------------------------------------------------------------------
//Requirement #22: Demonstrate one class and object (Object instantiated elsewhere)
//-----------------------------------------------------------------------
class MenuItem {
    std::string content;
    void (*execution)();
    public:
        std::string getContent();
        void setContent(std::string text);
        void setExecution(void (*function)());
        void execute();
};
//Class Name : Menu
//Description : The Menu class contains a map of characters to menu items.
//It also has a display function to show the menu to the user.
class Menu {
    //-----------------------------------------------------------------------
    //Requirement #13: Demonstrate variable scope (private member variables below)  
    //-----------------------------------------------------------------------
    std::map<char, MenuItem> contents;
    //-----------------------------------------------------------------------
    //Requirement #23: Demonstrate a pointer to an array 
    //-----------------------------------------------------------------------
    char *applicationName;
    public:
        std::map<char, MenuItem> getContents();
        char* getApplicationName();
        void setApplicationName(char * name);
        void addContent(char option, MenuItem item);
        void display();
        void start();
        void select(char option);
        void run();
        void choose();

};

std::string MenuItem::getContent(){
    return content;
}
//-----------------------------------------------------------------------
//Requirement #14: Demonstrate passing mechanisms (Part 2) Pass By Value  
//-----------------------------------------------------------------------

void MenuItem::setContent(std::string text) {
    content = text;
}
//Function Name: setExecution
//Description: The setExecution function sets the MenuItem's function pointer
//to the function pointer argument
//-----------------------------------------------------------------------
//Requirement #14: Demonstrate passing mechanisms (Part 1) Pass By Reference  
// Something else awesome (Requirement #26) I am passing a function pointer to be used in an abstract way! 
//I thought this was cool
//-----------------------------------------------------------------------
void MenuItem::setExecution( void (*function)()) {
    execution = function;
}

void MenuItem::execute() {
    execution();
}
std::map<char, MenuItem> Menu::getContents() {
    return contents;
}

void Menu::addContent(char option, MenuItem item) {
    contents[option] = item;
}
void Menu::display() {
    clear();
    std::cout << applicationName << std::endl;
    std::map<char, MenuItem>::iterator it;
    //-----------------------------------------------------------------------
    //Requirement #07: Demonstrate a loop
    //-----------------------------------------------------------------------
    for (it = contents.begin(); it != contents.end(); ++it) {
        //----------------------------------------------------------------------
        //Requirement #01: Demonstrate simple output
        //----------------------------------------------------------------------
        std::cout << it->first << " : " << it-> second.getContent() << std::endl;
    }
    std::cout << "Selection: ";
}

void Menu::run() {
    display();
    choose();
}
//----------------------------------------------------------------------
//Requirement #11: Demonstrate a function
//----------------------------------------------------------------------
void Menu::start(){
    std::string affirmative[] = {"y","yes"};
    char response;
    do {
        run();
        std::cout << "Would you like to continue? [y/n]";
        //-----------------------------------------------------------------------
        //Requirement #02: Demonstrate simple input
        //-----------------------------------------------------------------------
        std::cin >> response;
    } while (in(ctos(response),affirmative));
}

void Menu::choose() {
    char response;
    std::cin >> response;
    //-----------------------------------------------------------------------
    //Requirement #10: Demonstrate debugging "trick" This helps the user by ignoring case
    //based on the expectation that all menu items will be upper case letters
    //-----------------------------------------------------------------------
    response = toupper(response);
    //-----------------------------------------------------------------------
    //Requirement #04: Demonstrate conditional statements
    //-----------------------------------------------------------------------
    if (contents.find(response) == contents.end() && !(validate(response))) {
        std::cout << "Invalid Selection" << std::endl;
    }
    else {
        contents[response].execute();
    }
}

void Menu::select(char option) {
    if (contents.find(option) == contents.end() && !(validate(option))) {
        std::cout << "Invalid option!" << std::endl;
    }
    else {
        contents[option].execute();
    }
}

char* Menu::getApplicationName() {
    return applicationName;
}

//-----------------------------------------------------------------------
//Requirement #16: Demonstrate a c string
//-----------------------------------------------------------------------
void Menu::setApplicationName(char * name) {
    applicationName = name;
}

//Function: in
//Description: The in function checks if a string value is present in an
//array of strings
//Requirement #27: More extra credit. I thought this was a really neat function.
//It mimics python's in operator and really reduces the amount of necessary code
//Don't Repeat Yourself!
bool in(std::string x, std::string y[]) {
    for (int i = 0; i < y->length(); i++) {
        //-----------------------------------------------------------------------
        //Requirement #05: Demonstrate a logical operator 
        //-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------
//Requirement #10: Demonstrate debugging trick (input validation)
//This also exists elsewhere
//-----------------------------------------------------------------------

bool validate(char in) {
    if (isalpha(in)){
        return true;
    }
    else {
        return false;
    }
}

