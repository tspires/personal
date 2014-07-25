#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string target, char delimiter);
int main() {
    string name;
    vector<string> splitName; 
    cout << "Please enter your first and last name with middle initial." << endl;
    getline(cin,name);
    splitName = split(name,' ');
    cout << string(20, '*') << endl;
    if (splitName.size() == 3) {
	cout << splitName.at(2) << ", " << splitName.at(0) << " " << splitName.at(1).substr(0,1) << endl;
    }
    else if (splitName.size() == 2) {
	cout << splitName.at(1) << ", " << splitName.at(0) << endl;
    }
    return 0;
}

//Simple split implemenetation
vector<string> split(string target, char delimiter) {
    vector<string> result;
    string tmp;
    for (int i = 0; i < target.length(); i++) {
	if (target.at(i) != delimiter) {
		tmp += target.at(i);
	}
	else if (target.at(i) == delimiter) {
		result.push_back(tmp);
		tmp = "";
	}
    }
    result.push_back(tmp);
    return result;
}
