#include "menu.cpp"

void test() {
    std::cout <<"Hello" << std::endl;
}
Menu buildMenu() {
    Menu menu;
    MenuItem addProperty;
    addProperty.setContent("Add Property");
    addProperty.setExecution(test);
    menu.addContent('A',addProperty);
    return menu;

}
int main() {
   Menu menu = buildMenu();
   menu.start();
}
