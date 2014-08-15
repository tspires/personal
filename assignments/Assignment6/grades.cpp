#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int getGrade();
void addGrade(int (&grades)[6],int grade);
bool validGrade(int Grade);
void chartGrades(int (&grades)[6]);
int main ()
{
    int grades[6] = {0,0,0,0,0,0};
    int grade;
    std::string content;
    std::string line;
    do {
        std::cout << "Enter a grade (Enter to finish): ";
        getline(std::cin,line);
        grade = atoi(line.c_str()); 
        if (validGrade(grade) and !line.empty()) {
            addGrade(grades,grade);
        }
        else if (!line.empty()) {
            cout <<"Invalid grade!" << endl;
        }
        else {
            cout << "Done adding!" << endl;
            cout << string(40,'=') <<endl;
        }
    } while (!line.empty());
    chartGrades(grades);
    return 0;
    }
bool validGrade(int grade) {
    if (grade < 6 and grade >= 0) {
        return true;
    }
    else {
        return false;
    }
}
int getGrade() {
    int grade;
    cout << "Please enter a grade (or Return if done.) : ";
    return grade;
}
void addGrade(int (&grades)[6],int grade){
    if (grade < 7 and grade >= 0) {
        grades[grade] += 1;
    }   
    else {
        cout << "Grade not in range!" << endl;
    }   
}
void chartGrades(int (&grades)[6]) {
    for (int i = 0; i < sizeof(grades)/sizeof(*grades); i++) {
        cout << "There were " << grades[i] << " grades of " << i << endl;
    }
    cout << string(40,'=') <<endl;
    for (int i = 0; i < sizeof(grades)/sizeof(*grades); i++) {
        cout << i << " : " << string(i,'|') << endl;
    }

}

