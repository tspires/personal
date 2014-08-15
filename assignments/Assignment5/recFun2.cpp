#include <iostream>


using namespace std;
int pins(int rowCount);
int main() {
    cout << pins(10);

}

int pins(int rowCount) {
    if ( rowCount == 1 )
        return 1;
    else 
        return ( rowCount + pins(rowCount - 1) );
}
