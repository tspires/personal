#include <iostream>
#include <string>
using namespace std;

bool isMatch(string &stringOne, string &stringTwo);
int main() {
    string testOne = "test";
    string testTwo = "tast";
    bool match = isMatch(testOne, testTwo);
    cout << match;
    return 0;
}

bool isMatch(string &stringOne, string &stringTwo) {
    if (stringOne.length() == stringTwo.length()){
        for (int i = 0; i < stringOne.length(); i++) {
            if (stringOne.at(i) != stringTwo.at(i)) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}
