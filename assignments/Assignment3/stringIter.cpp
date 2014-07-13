#include <iostream>
#include <string>

using namespace std;

bool areMatch(string one, string two);

int main() {
    string targetOne;
    string targetTwo;
    string matchMessage = "The strings match!";
    string notMatchMessage = "The strings don't match!";
    cout << "Please enter a string: " << endl;
    getline(cin, targetOne);
    cout << "Please enter another string: " << endl;
    getline(cin, targetTwo);
    if (targetOne.length() != targetTwo.length()) {
	cout << notMatchMessage << endl;
    }
    else if (!areMatch(targetOne, targetTwo)) {	
	cout << notMatchMessage << endl;
    }
    else {
	cout << matchMessage << endl;
    }
    return 0;
}

bool areMatch(string one, string two) {
    return false;

}
