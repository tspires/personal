#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
void displayWord(string words[]);
string getRandomWord();
string words[9] = { "There", "once", "was", "a", "man","who", "played", "with", "taipans" };
int main()
{
    srand(time(0));
    
    string words[9] = { "There", "once", "was", "a", "man","who", "played", "with", "taipans" };

    string phrase[2];
    phrase[0] = getRandomWord();
    phrase[1] = getRandomWord(); 
    displayWord(phrase);

    return 0;
}

void displayWord(string phrase[]) {
    for (int i = 0; i < 2;i++) {
        cout << phrase[i] << " ";
    }
}

string getRandomWord() {
    srand(time(0));
    int pos = rand() % 10 + 0;
    cout <<words[0];
    return words[0];
}
