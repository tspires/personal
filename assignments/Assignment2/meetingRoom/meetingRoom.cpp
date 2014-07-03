#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    int participant_cap;
    int participant_count;
    int participant_delta;
    cout << "What is the fire regulation defined max room capacity for the conference room? ";
    cin >> participant_cap;
    cout << "How many people will be in attendance at the meeting? ";
    cin >> participant_count;
    participant_delta = participant_cap - participant_count;
    if ( participant_count <= participant_cap ) {
        cout << "Your meeting is within fire code and you can have " << participant_delta << " more participants." << endl;
    }
    if ( participant_count > participant_cap) {
        cout << "Your meeting is not within fire code and you have " << abs(participant_delta) << " more participants than allowed." << endl;
    }
}
