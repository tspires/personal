#include <iostream>

using namespace std;

int fibonacci(int n);

int main() {
    int x = 3;
    cout << fibonacci(x);
    for (int i = 0; i < x; i++){
        cout << fibonacci(x);
        x++;
   }
}
int fibonacci(int n){
    if ( n <= 1 && n >= 0)
        return n;
    else if ( n > 1 ) 
        return (fibonacci(n - 1) + fibonacci(n - 2));
    else 
        return -1;
}
