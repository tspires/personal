#include <iostream>


struct Person {
    char name[20];
    int age;
};
Person newPerson();
int main() {
    Person person = newPerson();
    std::cout << person.name << " is " << person.age << " years old." << std::endl;
    return 0;
}

Person newPerson(){
   Person person;
   std::cout << "Please enter your person's name : ";
   std::cin >> person.name;
   std::cout << "Please enter your person's age : ";
   std::cin >> person.age;
   return person;
}

