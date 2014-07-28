#include <iostream>

using namespace std;

double compound(double P, double i, double n);
double requestDouble(string name);
int main() {
    double P = 0.0;
    double i = 0.0;
    double n = 0.0;
    P = requestDouble("principal amount");
    i = requestDouble("interest amount");
    n = requestDouble("compounding period");
    P = compound(P,i,n);
    cout << "Your balance after " << n << " years would be " << P << " dollars." << endl;
    return 0;
}

double requestDouble(string name) {
    double input = 0.0;
    cout << "Please enter the " << name << " : ";
    cin >> input;
    return input;
}

double compound(double P, double i, double n) {
    if (n > 0) {
        P = P + (P * i);
        n--;
        compound(P,i,n);
    }
    else {
        return P;
    }
}
