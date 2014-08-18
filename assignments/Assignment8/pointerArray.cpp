#include <iostream>

using namespace std;

struct Person {
    string name;
    int age;
};
int main() {
    Person friends[3];
    Person * friends_ptr[3];
    Person friendOne;
    Person friendTwo;
    Person friendThree;
    friendOne.name = "Tim";
    friendOne.age = 23;
    friendTwo.name = "Ethel";
    friendTwo.age = 83;
    friendThree.name = "Richard";
    friendThree.age = 93;
    friends[0] = friendOne;
    friends[1] = friendTwo;
    friends[2] = friendThree;
    
    for (int i = 0; i < 3; i++) {
        friends_ptr[i] = &friends[i];
    }
    

    for (int i = 0; i < 3; i++) {
        cout << friends_ptr[i]->name << endl;
    }
}
