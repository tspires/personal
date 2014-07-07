#include <iostream>
#include <string>

using namespace std;

void split(string target, char delimiter);
int main() {
    string name;
    string firstName;
    string lastName;
    string middleInitial;
    
    cout << "Please enter your first and last name with middle initial." << endl;
    cin >> name;
    split(name,' '); 
}

void split(string target, char delimiter) {
    string tmp;
    for (int i = 0; i < target.length(); i++) {
        cout << i << endl;
        cout << target.at(i) << endl;
	
    }
}
