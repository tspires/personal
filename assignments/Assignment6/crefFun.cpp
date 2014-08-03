#include <iostream>


using namespace std;
bool isMatch(char *wOne, int oneSize, char *wTwo, twoSize) {
int main() {
    char wordOne[] = "hello";
    int sizeOne = sizeof(wordOne) / sizeof(*wordOne);
    char wordTwo[] = "hello";
    int sizeOne = sizeof(wordTwo) / sizeof(*wordTwo);
    if (isMatch(&wordOne, &wordTwo)) {
        cout << "The words match!";
    }
    else {
        cout << "The words don't match!";
    }
    return 0;
}

bool isMatch(char *wOne, int oneSize, char *wTwo, twoSize) {
    if (oneSize == twoSize) {
        for (int i = 0; i < oneSize; i++) {
            if (wOne[i] != wTwo[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}

