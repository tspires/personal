#include <iostream>
struct Record
{
    double quizOne;
    double quizTwo;
    double midterm;
    double final;
    double avg;
    char grade;
};

void calculateAvg(Record& record);
void writeRecord(Record record);
char getGrade(double numericGrade);
 
int main()
{
  Record record;
  std::cout << "Enter your grades." << std::endl;
  std::cout << "Quiz Score One: ";
  std::cin >> record.quizOne;
  std::cout << "Quiz Score Two: "; 
  std::cin >> record.quizTwo; 
  std::cout << "Midterm Exam Score: ";
  std::cin >> record.midterm; 
  std::cout << "Final Exam Score: ";
  std::cin >> record.final;
  calculateAvg(record);
  record.grade = getGrade(record.avg);
  writeRecord(record);
}
 
char getGrade(double numericGrade)
{
  char alpha;
  if (numericGrade < 60) {
    alpha = 'F';
    }
  else if (numericGrade < 70) {
    alpha = 'D';
    }
  else if (numericGrade < 80) {
    alpha = 'C';
    }
  else if (numericGrade < 90) {
    alpha = 'B';
    }
  else {
    alpha = 'A';
    }
  return alpha;
}
 
 
void writeRecord(Record record)
{
  std::cout << "***************************" << std::endl;
  std::cout << "Quiz One Score: " << record.quizOne << std::endl;
  std::cout << "Quiz Two Score: " << record.quizTwo << std::endl;
  std::cout << "Midterm Score: " << record.midterm << std::endl;
  std::cout << "Final Score: " << record.final << std::endl;
  std::cout << "Course Average: " << record.avg << std::endl;
  std::cout << "***************************" << std::endl;
  std::cout << "Final Grade: " << record.grade << std::endl;
}
 
 
void calculateAvg(Record& record)
{
  const double EXAM_WEIGHT = 0.5;
  const double MIDTERM_WEIGHT = 0.25;
  const double QUIZ_WEIGHT = 0.25;
  double quizOneGrade;
  double quizTwoGrade;
  quizOneGrade = 100 * record.quizOne / 10.0;
  quizTwoGrade = 100 * record.quizTwo / 10.0;
  double quizAvg = (quizOneGrade + quizTwoGrade) / 2;
  record.avg = quizAvg * QUIZ_WEIGHT + record.midterm * MIDTERM_WEIGHT + 
  record.final * EXAM_WEIGHT;
}
 


