#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	//Decleration
	map<string, int> reward;
	map<string, int> pocket;
	int coupons = 0;
	//Assignment
	reward["candybar"] = 10;
	reward["gumball"] = 3;
	//Execution
	cout << "How many coupons do you have? " << endl;
	cin >> coupons;
	cout << "You have " << coupons << " coupons." << endl;
	int remainingCoupons = coupons;
	while (remainingCoupons >= reward["gumball"]) {
		if (remainingCoupons >= reward["candybar"]) {
			pocket["candybar"] += 1;
			remainingCoupons -= reward["candybar"];
		}
		else if (remainingCoupons >= reward["gumball"]) {
			pocket["gumball"] += 1;
			remainingCoupons -= reward["gumball"];
		}
	}
	string candybar = string(pocket["candybar"],'|');
	string gumball = string(pocket["gumball"],'|');
	string coupon = string(remainingCoupons,'|');
	cout << "Candybars         : " << candybar << endl;
	cout << "Gumballs          : " << gumball << endl;
	cout << "Remaining Coupons : " << coupon << endl;
	cout << endl;
	cout << "You could buy " << pocket["candybar"] << " candy bars." << endl
	<< "And you could buy " << pocket["gumball"] << " gumballs." << endl
	<< "And you would have " << remainingCoupons << " coupons remaining." << endl;
}
