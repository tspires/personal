
//Validation Utilities
bool isInt(string value);
bool isDigit(char value);
bool isString(string value);
bool isChar(string value);
bool isBool(string value);
bool isWord(string w);
bool isLetter(char c);

//Array Utilities
short find(char list[], char value, short offset);

//CLI Utilities
void cliLoop(function<void()> f);
int getInt(string name);
string getString(string name);
char getChar(string name);
long getLong(string name);
short getShort(string name);
char confirmOrDeny(char response);
