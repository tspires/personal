#include <iostream>
#include <cstring>
#include <sstream>
#include "utilities.h"

using namespace std;
int main() {
    print("TEST");
}


//Comparison Utilities
bool is
//Transformation Utilities
string toString(bool b) {
    stringstream converter;
    converter << b;
    if (converter.str() == "1") {
        return "true";
    }
    else if (converter.str() == "0") {
        return "false";
    }
    else {
        return "None";
    }
}
string toString(char c) {
    stringstream converter;
    converter << c;
    return converter.str();
}

//Array Utilities
//A search function to find the position of value in the char array
void stringIter(string value, bool (*f)(string)) {
    for (int i = 0; i < value.length(); i++) {
        string strValue = toString(value[i]);
        //*f(strValue);
    }
}
short find(char list[], char value, short offset) {
    short i = offset;
    while (i < strlen(list)) {
        if (list[i] == value) {
            return i;
        }
        i++;
    }
    return -1;
}

//Validation Utilities
bool isValidWord(string word) {
    char c;
    for (int i = 0; i < word.length(); i++){
        c = word.at(i);
        if (!((c <= 'z' && c >= 'a') || ((c <= 'Z') && c >= 'A')))
            return false;
    }
    return true;
}

bool isValidLetter(char c) {
    if (!((c <= 'z' && c >= 'a') || ((c <= 'Z') && c >= 'A')))
        return false;
    else
        return true;
}

bool isDigit(char value) {
    if ((value >= '0') && (value <= '9')) {
        return true;
    }
    else {
        return false;
    }
}

bool isInt(string value) {
    for (int i = 0; i < value.length(); i++) {
        if (!isDigit(value[i])) {
            return false;
        }
    }
    return true;
}

bool isBool(string value) {
    if (value == "true" || value == "false"){
        return true;
    }
    else {
        return false;
    }
}

//CLI Utilities
void print(string value) {
    cout <<  value;
}
void print(int value) {
    cout << value;
}
void print(char value) {
    cout << value;
}
void printline(string value) {
    cout << value << endl;
}
