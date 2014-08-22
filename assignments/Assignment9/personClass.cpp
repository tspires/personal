#include <iostream>


class Person {
    public:
        char name[20];
        int age;
        void having_birthday();
};
Person person();
int main() {
    Person guy = person();
    std::cout << "Your person's name is " << guy.name << " and age is " << guy.age << std::endl;
    guy.having_birthday();
    std::cout << "After a birthday your person's age is " << guy.age << std::endl;
    return 0;
}

Person person() {
    Person fellow;
    std::cout << "Please enter a name: ";
    std::cin >> fellow.name;
    std::cout << "Please enter an age: ";
    std::cin >> fellow.age;
    return fellow;
}

void Person::having_birthday() {
    age += 1;
}
