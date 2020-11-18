#include "assign4.h"
#include <algorithm>

//default Constructor
Calculate::Calculate(Windows *windows){
  this->windows = windows;
  totalStudents = 0;
}

//default destructor
Calculate::~Calculate(){
 //cout << "bye Calculate" << endl;
}

//run/calculate the calulations
void Calculate::RunCalculations(){
  calculateWindowCalculations();
  calculateStudentCalculations();
}

//print calculations to the screen
void Calculate::PrintCalculations(){
  cout << "The mean student wait time: " << MeanWaitTime << endl;
  cout << "The median student wait time: " << MedianWaitTime << endl;
  cout << "The longest student wait time: " << MaxWaitTime << endl;
  cout << "The number of students waiting over 10 minutes: " << StudentsWaitingOverTenMinutes << endl;
  cout << "The mean window idle time: " << MeanWindowIdleTime << endl;
  cout << "The longest window idle time: " << MaxWindowIdleTime << endl;
  cout << "The number of windows idle for over 5 minutes: " << NumberOfIdleWindowsOverFiveMinutes << endl;
}

//add a student to the queue that hols all students
void Calculate::AddStudent(Student* student){
  allStudents->insert(student);
  totalStudents++;
}

//calculate the window calulations
void Calculate::calculateWindowCalculations(){
  MeanWindowIdleTime = calculateMeanWindowIdleTime();
  MaxWindowIdleTime = calculateMaxWindowIdleTime();
  NumberOfIdleWindowsOverFiveMinutes = calculateNumberOfIdleWindowsOverFiveMinutes();
}

//calculate the student calulations
void Calculate::calculateStudentCalculations(){
  MeanWaitTime = calculateMeanWaitTime();
  MedianWaitTime = calculateMedianWaitTime();
  MaxWaitTime = calculateMaxWaitTime();
  StudentsWaitingOverTenMinutes = calculateStudentsWaitingOverTenMinutes();
}

//calculate the mean wait time for students
double Calculate::calculateMeanWaitTime(){
  double totalWaitingTime = 0;
  for(int i = 0; i < totalStudents; i++){
    Student *currentStudent = allStudents->atPos(i);
    totalWaitingTime += (double)currentStudent->GetTotalQueueTime();
    if(currentStudent->GetTotalQueueTime() != 0)
      totalStudentsWaiting++;
  }
  if(totalWaitingTime == 0)
    return 0;
  return totalWaitingTime/totalStudentsWaiting;
}

//calculate the median wait time for students
double Calculate::calculateMedianWaitTime(){
  int arrayOfWaitTimes[totalStudentsWaiting];
  int currentQueueTime;
  double medianWaitTime;
  // Initializes the array
  for(int i = 0; i < totalStudents; i++){ //add student queue time to an array
    Student *currentStudent = allStudents->atPos(i);
    currentQueueTime = currentStudent->GetTotalQueueTime();
    if(currentQueueTime > 0) {
      arrayOfWaitTimes[i] = currentQueueTime;
    }
  }

  int sizeOfArray = sizeof(arrayOfWaitTimes)/sizeof(arrayOfWaitTimes[0]);
  sort(arrayOfWaitTimes, arrayOfWaitTimes+sizeOfArray); //sort the array

  if (sizeOfArray % 2 == 0) //if the number of students is even
    medianWaitTime = (arrayOfWaitTimes[sizeOfArray/2] + arrayOfWaitTimes[(sizeOfArray/2)-1] /2);
  else //if the number of students is odd
    medianWaitTime = arrayOfWaitTimes[sizeOfArray/2];

  return medianWaitTime;
}

//calculate the mean window idle time
double Calculate::calculateMeanWindowIdleTime(){
  return windows->getMeanWindowIdleTime();
}

//calculate the max wait time for the students
int Calculate::calculateMaxWaitTime(){
  int longestWaitTime = 0;
  for(int i = 0; i < totalStudents; i++){
    Student *currentStudent = allStudents->atPos(i);
    if(currentStudent->GetTotalQueueTime() > longestWaitTime)
      longestWaitTime = currentStudent->GetTotalQueueTime();
  }
  return longestWaitTime;
}

//calculate the number of students that wait over ten minutes
int Calculate::calculateStudentsWaitingOverTenMinutes(){
  int count = 0;
  for(int i = 0; i < totalStudents; i++){
    Student *currentStudent = allStudents->atPos(i);
    if(currentStudent->GetTotalQueueTime() > 10)
      count++;
  }
  return count;
}

//calculate the max window idle time
int Calculate::calculateMaxWindowIdleTime(){
  return windows->getMaxIdleTime();
}

//claclulate the number of windows idle for over 5 minutes
int Calculate::calculateNumberOfIdleWindowsOverFiveMinutes(){
  return windows->getNumberOfIdleWindowsOverFiveMinutes();
}
