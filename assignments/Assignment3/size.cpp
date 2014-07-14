#include <iostream>

using namespace std;

double calculateWaistSize(double weight, double age);
double calculateJacketSize(double height, double weight, double age);
double calculateHatSize(double weight, double height);
int round(double value);
int main() {
    bool done = false;
    char response;
    double height;
    double weight;
    double age;
    double hatSize;
    double jacketSize;
    double waistSize;
    while (done == false) {
        cout << "Please enter your weight in pounds : ";
        cin >> weight;
        cout << "Please enter your height in inches : ";
        cin >> height;
        cout << "Please enter your age in years : ";
        cin >> age;
        jacketSize = calculateJacketSize(height, weight, age);
        hatSize = calculateHatSize(weight, height);
        waistSize = calculateWaistSize(weight, age);
        cout << "Your jacket size is " << round(jacketSize) << endl;
        cout << "Your waist size is " << round(waistSize) << endl;
        cout << "Your hat size is " << round(hatSize) << endl;
        cout << "Would you like to go again? " << endl;
        cin >> response;
        if (response == 'y') {
            done = false;
        }
        else {
            done = true;
        }
    }
    return 0;
}

double calculateHatSize(double weight, double height) {
    return ( weight / height ) * 2.9;
}

double calculateJacketSize(double height, double weight, double age) {
    if ( age > 39 ) {
        double adjustment = ( (age - 30) / 10 ) * (1.0 / 8.0);
        return height * weight / 288.0 + adjustment;
        }
    else {
        return height * weight / 288.0;
    }
}

double calculateWaistSize(double weight, double age) {
    if (age > 29) {
        double result = ( ( age - 28.0 ) / 2.0 ) * .10;
        result = result + (weight / 5.7);
        return result;
    }
    else {
        return weight / 5.7;
        }
}

int round(double value) {
    value += .5;
    return (int) value;
}
