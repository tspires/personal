#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
bool intIn(vector<int> list, int value);
int main() {
    //Set random number generator seed
    srand(time(0));
    vector<int> winner;
    int potential;
    while (winner.size() < 4) {
        potential = rand() % 25 + 1;
        if (!(intIn(winner,potential))) {
            cout << "Contestant number " << potential << " is a winner!" << endl;
            winner.push_back(potential);
        }
    }
    return 0;
}

bool intIn(vector<int> list, int value) {
    for (int i = 0; i < list.size(); i++) {
        if (list.at(i) == value) {
            return true;
        }
    }
    return false;
}
