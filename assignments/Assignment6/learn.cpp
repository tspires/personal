#include <iostream>
#include <string>
using namespace std;
int main() {
    int number = 5;
    char character = 'c';
    bool condition = false;
    
    if (not condition) {
        cout << "Hello" << endl;
    }
    while ( number < 10 ) {
        cout << character;
        number++;
    }
    return 0;
}
