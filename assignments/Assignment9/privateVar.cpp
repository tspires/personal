#include <iostream>


class Person {
    std::string name;
    int age;
    public:
        void having_birthday();
        int get_age();
        std::string get_name();
        void set_age(int x);
        void set_name(std::string n);
};
Person person();
int main() {
    Person guy = person();
    std::cout << "Your person's name is " << guy.get_name() << std::endl;
    std::cout << "Your person is " << guy.get_age() << " years old.";

    return 0;
}

Person person() {
    Person fellow;
    std::string name;
    int age;
    std::cout << "Please enter a name: ";
    std::cin >> name;
    std::cout << "Please enter an age: ";
    std::cin >> age;
    fellow.set_name(name);
    fellow.set_age(age);
    return fellow;
}

void Person::having_birthday() {
    age += 1;
}

std::string Person::get_name() {
    return name;
}
int Person::get_age() {
    return age;
}
void Person::set_name(std::string n ) {
    name = n;
}
void Person::set_age(int x) {
    age = x;
}
