#include <iostream>

using namespace std;

struct Person {
    string name;
    int age;
};
int main(int argc, char *argv[]) {
    Person tim;
    tim.name = "Tim";
    tim.age = 23;
    Person * tim_ptr = &tim;
    cout << tim_ptr << endl;
    cout << tim_ptr->name << endl;

    Person julie;
    julie.name = "Julie";
    julie.age = 43;

    Person friends[2];
    friends[0] = tim;
    friends[1] = julie;
    
    for (int i = 0; i < 2; i++) {
        cout << friends[i].name << endl;
    }
}
