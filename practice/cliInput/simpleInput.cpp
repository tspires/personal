#include <iostream>
#include <string>

using namespace std;

string ask(string question);
int main() {
	const string QUESTION = "How many programming languages do you speak? ";
	string answer;
	ask("Hello");
	//getline(cin, answer);
}

string ask(string question) {
	cout << question << endl;
}

