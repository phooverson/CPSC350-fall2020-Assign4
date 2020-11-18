#include "assign4.h"

//default Constructor
Window::Window(){
  hasStudent = false;
  idleTime = 0;
}

//default destructor
Window::~Window(){
 //cout << "bye window" << endl;
}

//check if the window is open
bool Window::IsOpen(){
  if (hasStudent)
    return false;
  return true;
}

//give the window a student
void Window::GiveStudent(Student* student){
  hasStudent = true;
  SetTimeWithStudent(student->GetTimeAtWindow());
}

//increment idle time, unless window has student, then increment time left with student
void Window::IncrementIdleTime(){
  if(IsOpen()){
    idleTime++;
  }
  else{
    timeLeftWithStudent--;
  }
  checkTimeLeftWithStudent();
}

//set the time left with a student
void Window::SetTimeWithStudent(int waitTime){
  timeLeftWithStudent = waitTime;
}

//check if there is anytime left with a student
void Window::checkTimeLeftWithStudent(){
  if(timeLeftWithStudent <= 0){
    hasStudent = false;
  }
}

//get the current wait time
int Window::GetWaitTime(){
  return idleTime;
}
