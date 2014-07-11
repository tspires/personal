#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int myRandom;
    int myIndex;
    //Set rand function's seed
    srand(time(NULL));
    //Random index for number of times to print a random number
    myIndex = rand() % 20 + 10;
    for (int i = 0; i < myIndex; i++) {
	//Fetch new random number
	myRandom = rand() % 20 + 10;
	cout << i << ": " << myRandom << endl;
    } 
}
