#include <iostream>

using namespace std;
void sort(int &a, int &b, int &c);
int main() {
    int a = 3;
    int b = 2;
    int c = 1;
    sort(a,b,c);
    cout << a <<' '<<b<<' '<<c << endl;
    a = 10;
    b = 5;
    c = 100;
    sort(a,b,c);
    cout << a <<' '<<b<<' '<<c << endl;
    return 0;
}

void sort(int &a, int &b, int &c) {
    int tmp = 0;
    if ( a > c ) {
        swap(a,c);
    }
    if ( a > b ) {
        swap(a,b);
    }
    if ( b > c) {
        swap(b,c);
    }
}

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = a;
}
