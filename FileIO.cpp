#include <iostream>
#include <fstream>
#include "assign4.h"

//default Constructor
FileIO::FileIO(Windows *windows, Simulate *simulate, Calculate *calculate){
  this->windows = windows;
  this->simulate = simulate;
  this->calculate = calculate;
}

//default destructor
FileIO::~FileIO(){
 //cout << "bye FileIO" << endl;
}

//read the file and pull the appropriate information from it
void FileIO::ReadFile(string fileName){
  fstream inputFile;
  inputFile.open(fileName);
  if(inputFile.is_open()){
    int lineCount = 1;
    string currentLine;
    int timeStudentArrives;
    int numberOfStudentsArriving;
    int nextArrivalTime = 2;
    int studentsTimeAtWindow;

    while(getline(inputFile, currentLine)){
      if(lineCount == 1){ //get the number of windows
        windows->SetTotalWindows(stoi(currentLine));
      }
      else if (lineCount == nextArrivalTime){ //get the arrival times
        timeStudentArrives = stoi(currentLine);
        simulate->AddStudentArrivalTime(timeStudentArrives);
      }
      else if(lineCount == nextArrivalTime+1){ //get the num ber of students arriving at said time and find the next arrival time
        numberOfStudentsArriving = stoi(currentLine);
        simulate->AddNumberOfStudentsArriving(numberOfStudentsArriving);
        nextArrivalTime = lineCount+numberOfStudentsArriving+1;
      }
      else if(lineCount != nextArrivalTime){ //for each student, create a new student with the appropriate time at a window and add it to the queue's
        studentsTimeAtWindow = stoi(currentLine);
        Student* student = new Student();
        student->SetTimeAtWindow(studentsTimeAtWindow);
        simulate->AddStudentToQueue(student);
        calculate->AddStudent(student);
      }
      lineCount++;
    }
  }
  else{
    cout << "file not found" << endl;
  }
}
