#include <iostream>
#include <stdlib.h>
using namespace std;
int processClosest(int guess, int closest, int secret);
int main() {
    int guess = 12;
    int closest = 9;
    int secret = 10;
    closest = processClosest(guess, closest, secret);
    cout << "Should be 9 : " << closest << endl; 
    closest = 20;
    closest = processClosest(guess, closest, secret);
    cout << "Should be 12 : " << closest << endl;

}

int processClosest(int guess, int closest, int secret) {
    int guessDelta = secret - guess;
    int closestDelta = secret - closest;
    if (abs(guessDelta) < abs(closestDelta)) {
        return guess;
    }
    else {
        return closest;
    }
}
