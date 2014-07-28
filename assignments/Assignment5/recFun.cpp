#include <iostream>

using namespace std;
int fibonacci(int x);
int main() {
    int x = 4;
    int y = fibonacci(x);
    cout << y;
    return 0;
}

int fibonacci(int x) {
    if (x == 1 or x == 0)
        return x;
    else
        return fibonacci(x-1)+fibonacci(x-2);
}
