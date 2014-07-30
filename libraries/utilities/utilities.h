#include <string>

using namespace std;

//Conversion Utilities
string toString(bool b);
string toString(char c);
//Validation Utilities
bool isInt(string value);
bool isDigit(char value);
bool isChar(string value);
bool isBool(string value);
bool isWord(string w);
bool isLetter(char c);

//Array Utilities
void stringIter(string value, void (*f)(string) );
short find(char list[], char value, short offset);

//CLI Utilities
void cliLoop(void (*f)());
void print(string value);
void print(int value);
void print(char value);
void printLine(string value);
int getInt(string name);
string getString(string name);
char getChar(string name);
long getLong(string name);
short getShort(string name);
char confirmOrDeny(char response);
