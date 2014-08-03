#include <iostream>

using namespace std;
int len(int x);
int main() {
    int values[5];
    int sum = 0;
    char x;
    int len = (sizeof(values)/sizeof(*values));
    for (int i = 0; i < len; i++ ) {
        cout << "Please enter a number (" << len - i << " remaining). : " ;
        cin >> x;
        if (isdigit(x)){
            values[i] = x - '0';
        }
        cout << endl;
    }
    for (int i = 0; i < len; i++) {
        sum += values[i];
    }
    cout << "The sum of your numbers is " << sum << endl;
    return 0;
}
