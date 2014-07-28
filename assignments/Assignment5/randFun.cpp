#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void rand_int(const int &min, const int &max, int &val);
int main() {
    const int min = 10;
    const int max = 20;
    int val = 0;
    rand_int(min, max, val);
    cout << val;
    return 0;
}

void rand_int(const int &min, const int &max, int &val) {
    srand(time(0));
    val = rand() % max + min;
}
