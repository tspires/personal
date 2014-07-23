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
    if (!areMatch(targetOne, targetTwo)) {	
	cout << notMatchMessage << endl;
    }
    else {
	cout << matchMessage << endl;
    }
    return 0;
}

bool areMatch(string one, string two) {
    if (one.length() != two.length()) {
	return false;
    }
    else {
	for (int i = 0; i < one.length(); i++) {
	    if (one.at(i) != two.at(i)){
		return false;
	    }
	}
    }
    return true;
}
