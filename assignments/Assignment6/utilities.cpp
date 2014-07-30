#include <iostream>
#include <string>
#include "utilities.h"

//A search function to find the position of value in the char array
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

