#include <iostream>

using namespace std;

struct Person {
    string name;
    string age;
};
int main(int argc, char *argv[]) {
    if (argc != 5){
        cout << "usage: " << argv[0] << " <firstname> <age> <firstname> <age>" << endl;
    }
    else {
        Person guy;
        guy.name = argv[1];
        guy.age = argv[2];
        Person * guy_ptr = &guy;
        cout << "Your person is in memory at : " << guy_ptr << endl;
        cout << "Your person's name is " << guy_ptr->name << endl;
        cout << "Your person's age is " << guy_ptr->age << endl;
        cout << "*************************" << endl;
        Person guyTwo;;
        guyTwo.name = argv[3];
        guyTwo.age = argv[4];

        Person friends[2];
        friends[0] = guy;
        friends[1] = guyTwo;;
        
        for (int i = 0; i < 2; i++) {
            cout << friends[i].name << endl;
        }
    }
}
