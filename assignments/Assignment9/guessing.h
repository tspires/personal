
#ifndef guessing_h 
#define guessing_h
void guessing();
bool isWon(int guess, int secret);
std::string processInequality(int guess, int secret);
int processMax(int guess, int rangeMax, int rangeMin, int secret);
int processMin(int guess, int rangeMax, int rangeMin, int secret);
int processClosest(int guess, int closest, int secret); 
int processDifference(int guess, int secret);
#endif
