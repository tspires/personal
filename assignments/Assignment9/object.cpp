#include <iostream>


class Person {
    public:
        std::string name;
        int age;

};
Person person();

int main() {
    Person human = person();
    Person inhuman = person();
    Person *p = &human;
    std::cout << "Your person's name is " << p->name << std::endl;
    Person *i = &inhuman;
    std::cout << "Your person's name is " << i->name << std::endl;
    Person people[2];
    people[0] = person(); 
    people[1] = person(); 
    Person * people_ptrs[2];
    people_ptrs[0] = &people[0];
    people_ptrs[1] = &people[1];
    std::cout << "Your first person pointer's name is " << people_ptrs[0]->name;
    std::cout << "Your second person pointer's name is " << people_ptrs[1]->name;
}
Person person() {
    Person fellow;
    std::cout << "Please enter a name: ";
    std::cin >> fellow.name;
    std::cout << "Please enter an age: ";
    std::cin >> fellow.age;
    return fellow;
}
