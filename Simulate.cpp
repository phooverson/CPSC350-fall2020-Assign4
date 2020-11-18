#include "assign4.h"

//default Constructor
Simulate::Simulate(Windows *windows){
  this->windows = windows;
  time = 0;
  initilizeBooleans();
}

//default destructor
Simulate::~Simulate(){
 //cout << "bye simulate" << endl;
}

//run the simulations so we can find the appropriate stats
void Simulate::RunSimulation(){
  int numberOfStudentsArriving;
  int openWindowPosition;
  int count;
  initilizeBooleans();

  while (!canSimulationStop()){ //while the simulation is still running, loop through this loop
    if (time == 0) //assign the first arrival time
      timeOfStudentsArrival = timesStudentsArrive->remove();

    if (time == timeOfStudentsArrival){ //when time is at an arrival time do the following
      count = 0;
      numberOfStudentsArriving = numberOfStudentsThatArrive->remove(); // get th enumber of students arriving
      while(count != numberOfStudentsArriving){ //while there are still students to add
        liveQueue->insert(waitingQueue->remove()); //insert the students into the live wating queue
        count++;
      }
      if(!timesStudentsArrive->isEmpty()) //if there is still another arrival time in the queue, reassign the arrival time
        timeOfStudentsArrival = timesStudentsArrive->remove();
    }

    while(!liveQueue->isEmpty() && windows->CheckForOpenWindow()){ //while there is still students in the arrival queue and there is an open window assign the first student in the queue to a window
      openWindowPosition = windows->GetOpenWindowPosition();
      Window* window = windows->GetWindow(openWindowPosition);
      window->GiveStudent(liveQueue->remove());
    }
    incrementTime();
  }
}

void Simulate::AddStudentArrivalTime(int studentArrivalTime){ //add a new arrival time to the arrival time queue
  timesStudentsArrive->insert(studentArrivalTime);
}

void Simulate::AddNumberOfStudentsArriving(int numberOfStudentsArriving){ //add a new number of students arriving to the number of students arriving queue
  numberOfStudentsThatArrive->insert(numberOfStudentsArriving);
}

void Simulate::AddStudentToQueue(Student* student){ //add a new student to the student queue
  waitingQueue->insert(student);
}

void Simulate::incrementTime(){ //increment time across all classes
  time++;
  windows->IncrementWindowTime();
  Student* student;
  for(int i = 0; i < liveQueue->getSize(); ++i){ //increment time for each individual student
    student = liveQueue->atPos(i);
    student->IncrementQueueTime();
  }
}

bool Simulate::canSimulationStop(){ //check if the simulation still needs to run
  updateBooleans();
  if(windowsAreEmpty && liveQueueIsEmpty && noNewArrivalTimes)
    return true;
  return false;
}

void Simulate::updateBooleans(){ //update all the booleans
  checkWindows();
  checkLiveQueue();
  checkArrivalTimes();
}

void Simulate::initilizeBooleans(){ //initilize all the booleans
  windowsAreEmpty = true;
  liveQueueIsEmpty = true;
  noNewArrivalTimes = false;
}

void Simulate::checkWindows(){ //check if windows are empty
  if(windows->AreAllWindowsOpen())
    windowsAreEmpty = true;
  else
    windowsAreEmpty = false;
}

void Simulate::checkLiveQueue(){ //check if there are still students in the live queue
  if(liveQueue->isEmpty())
    liveQueueIsEmpty = true;
  else
    liveQueueIsEmpty = false;
}

void Simulate::checkArrivalTimes(){ //check if the current arrival time has passed and that there are no new arrival times
  if(timesStudentsArrive->isEmpty() && timeOfStudentsArrival < time)
    noNewArrivalTimes = true;
  else
    noNewArrivalTimes = false;
}
