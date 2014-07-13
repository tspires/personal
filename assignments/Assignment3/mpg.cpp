#include <iostream>
#include <iomanip>
using namespace std;

double literToGallon(double liters);
int main() {
    bool done = false;
    char response;
    int milesTraveled;
    int litersConsumed;
    double gallonsConsumed;
    double mpg;
    while (done == false) {
	cout << "How many liters of fuel did you use? " << endl;
	cin >> litersConsumed;
	cout << "How many miles did you travel? " << endl;
	cin >> milesTraveled;
	gallonsConsumed = literToGallon(litersConsumed);
	mpg = milesTraveled / gallonsConsumed;
	cout << "You used " << gallonsConsumed << " gallons of fuel and you got " << mpg << " miles per gallon. " << endl;
	cout << "Would you like to go again? [y/n] ";
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

double literToGallon(double liters) {
    return liters * 0.264179;
}
