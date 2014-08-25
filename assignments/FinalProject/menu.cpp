#include <iostream>
#include <map>
#include <sstream>
#include <stdlib.h>
void clear();
std::string ctos(char c); 
bool in(std::string x, std::string y[]);
//Class Name: MenuItem
//Description : The Menu Item represents a single option in the menu.
//It has content, the text which is displayed for the option, and 
//it has a function to be execute for the option which is set when
//the menu is built from its parent application
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
    std::map<char, MenuItem> contents;
    std::string applicationName;
    public:
        std::map<char, MenuItem> getContents();
        std::string getApplicationName();
        void setApplicationName(std::string name);
        void addContent(char option, MenuItem item);
        void display();
        void start();
        void run();
        void choose();

};

std::string MenuItem::getContent(){
    return content;
}

void MenuItem::setContent(std::string text) {
    content = text;
}
//Function Name: setExecution
//Description: The setExecution function sets the MenuItem's function pointer
//to the function pointer argument
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
    std::map<char, MenuItem>::iterator it;
    for (it = contents.begin(); it != contents.end(); ++it) {
        std::cout << it->first << " : " << it-> second.getContent() << std::endl;
    }
}

void Menu::run() {
    display();
    choose();
}

void Menu::start(){
    std::string affirmative[] = {"y","yes"};
    char response;
    do {
        run();
        std::cout << "Would you like to continue? [y/n]";
        std::cin >> response;
    } while (in(ctos(response),affirmative));
}

void Menu::choose() {
    char response;
    std::cin >> response;
    if (contents.find(response) == contents.end()) {
        std::cout << "Invalid Selection" << std::endl;
    }
    else {
        contents[response].execute();
    }
}

std::string Menu::getApplicationName() {
    return applicationName;
}

void Menu::setApplicationName(std::string name) {
    applicationName = name;
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

