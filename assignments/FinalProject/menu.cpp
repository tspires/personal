#include <iostream>
#include <map>

class MenuItem {
    std::string content;
    public:
        std::string getContent();
        void setContent(std::string text);
};
class Menu {
    std::map<char, MenuItem> contents;
    
    public:
        std::map<char, MenuItem> getContents();
        void addContent(char option, MenuItem item);
        void display();
};

std::string MenuItem::getContent(){
    return content;
}

void MenuItem::setContent(std::string text) {
    content = text;
}

std::map<char, MenuItem> Menu::getContents() {
    return contents;
}

void Menu::addContent(char option, MenuItem item) {
    contents[option] = item;
}

void Menu::display() {
    std::map<char, MenuItem>::iterator it;
    for (it = contents.begin(); it != contents.end(); ++it) {
        std::cout << it->first << " : " << it-> second.getContent() << std::endl;
    }
}
int main() {
    std::cout << "Compiled.";

}
