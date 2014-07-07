#include <iostream>
#include <string>

using namespace std;

string split(string target, char delimiter);
int main() {
    string name;
    string firstName;
    string lastName;
    string middleInitial;
    
    cout << "Please enter your first and last name with middle initial." << endl;
    cin >> name;
    split(name,' '); 
}

string split(string target, char delimiter) {
    string tmp;
    cout << target.length() << endl;
    for (int i = 0; i < target.length(); i++) {
        cout << i << endl;
        //tmp += target.at(i);
    }
}
