#include <iostream>
using namespace std;

int main() {
    int grades [] = {95, 94, 89};
    int a = 24125125;
    int length = sizeof(grades)/sizeof(grades[0]);
    cout << sizeof(grades[0]) << endl;
    cout << sizeof(grades) << endl;
    cout << sizeof(a) << endl;
    cout << length << endl;


}
