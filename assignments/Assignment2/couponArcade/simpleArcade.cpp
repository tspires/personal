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
	pocket["candybar"] = coupons / reward["candybar"];
	pocket["gumball"] = (coupons % reward["candybar"]) / reward["gumball"];
    coupons = (coupons % reward["candybar"]) % reward["gumball"];
	cout << "You can buy " << pocket["candybar"] << " candy bars." << endl;
	cout << "And you can buy " << pocket["gumball"] << " gumballs." << endl;
    cout << "And you would have " << coupons << " coupons remaining." << endl;
}
