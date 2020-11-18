#include "assign4.h"

//default Constructor
Student::Student(){
  totalQueueTime = 0;
  SetTimeAtWindow(5);
  IsAtWindow = false;
}
//overloaded Constructor
Student::Student(int studentsTimeAtWindow){
  totalQueueTime = 0;
  SetTimeAtWindow(studentsTimeAtWindow);
  IsAtWindow = false;
}

//default destructor
Student::~Student(){
 //cout << "bye student" << endl;
}

//return the time the student needs at a window
int Student::GetTimeAtWindow(){
  return timeAtWindow;
}

//get the total queue time of the student
int Student::GetTotalQueueTime(){
  return totalQueueTime;
}

//set the time the student needs at the window
void Student::SetTimeAtWindow(int studentsTimeAtWindow){
  timeAtWindow = studentsTimeAtWindow;
}

//increment queue time for student
void Student::IncrementQueueTime(){
  totalQueueTime++;
}
