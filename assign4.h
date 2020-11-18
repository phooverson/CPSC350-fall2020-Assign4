#include <iostream>
#include "GenQueueT.h"
#include "DoublyLinkedListT.h"

using namespace std;

class Student{
public:
  Student();
  Student(int studentsTimeAtWindow);
  ~Student();

  int GetTimeAtWindow();
  void IncrementQueueTime();
  void SetTimeAtWindow(int studentsTimeAtWindow);
  int GetTotalQueueTime();
private:
  int timeAtWindow;
  int totalQueueTime;
  bool IsAtWindow;
};

class Window{
public:
  Window();
  ~Window();

  bool IsOpen();
  void GiveStudent(Student* student);
  void IncrementIdleTime();
  int GetWaitTime();
private:
  bool hasStudent;
  int idleTime;
  int timeLeftWithStudent;

  void SetTimeWithStudent(int waitTime);
  void checkTimeLeftWithStudent();
};

class Windows{
public:
  Windows();
  ~Windows();
  void SetTotalWindows(int windowCount);
  Window* GetWindow(int windowNumber);
  bool CheckForOpenWindow();
  int GetOpenWindowPosition();
  int GetTotalWindows();
  bool AreAllWindowsOpen();
  void IncrementWindowTime();
  int getMaxIdleTime();
  int getNumberOfIdleWindowsOverFiveMinutes();
  double getMeanWindowIdleTime();

private:
  int totalWindows;
  DoublyLinkedListT<Window*> *windowList = new DoublyLinkedListT<Window*>;
};

class Simulate{
public:
  Simulate(Windows *windows);
  ~Simulate();

  void RunSimulation();
  void AddStudentArrivalTime(int studentArrivalTime);
  void AddNumberOfStudentsArriving(int numberOfStudentsArriving);
  void AddStudentToQueue(Student* student);
private:
  Windows *windows;
  int time;
  bool windowsAreEmpty;
  bool liveQueueIsEmpty;
  bool noNewArrivalTimes;
  int timeOfStudentsArrival;
  GenQueueT<int> *timesStudentsArrive = new GenQueueT<int>;
  GenQueueT<int> *numberOfStudentsThatArrive = new GenQueueT<int>;
  GenQueueT<Student*> *waitingQueue = new GenQueueT<Student*>;
  GenQueueT<Student*> *liveQueue = new GenQueueT<Student*>;

  bool canSimulationStop();
  void updateBooleans();
  void initilizeBooleans();
  void checkWindows();
  void checkLiveQueue();
  void checkArrivalTimes();
  void incrementTime();
};

class Calculate{
public:
  Calculate(Windows *windows);
  ~Calculate();

  void RunCalculations();
  void PrintCalculations();
  void AddStudent(Student* student);
private:
  Windows *windows;

  double MeanWaitTime;
  double MedianWaitTime;
  double MeanWindowIdleTime;
  int MaxWaitTime;
  int StudentsWaitingOverTenMinutes;
  int MaxWindowIdleTime;
  int NumberOfIdleWindowsOverFiveMinutes;
  int totalStudents;
  int totalStudentsWaiting;
  GenQueueT<Student*> *allStudents = new GenQueueT<Student*>;

  void calculateWindowCalculations();
  void calculateStudentCalculations();
  double calculateMeanWaitTime();
  double calculateMedianWaitTime();
  double calculateMeanWindowIdleTime();
  int calculateMaxWaitTime();
  int calculateStudentsWaitingOverTenMinutes();
  int calculateMaxWindowIdleTime();
  int calculateNumberOfIdleWindowsOverFiveMinutes();
};

class FileIO{
public:
  FileIO(Windows *windows, Simulate *simulate, Calculate *calculate);
  ~FileIO();

  void ReadFile(string fileName);
  void PrintToFile(string fileName);

private:
  Windows *windows;
  Simulate *simulate;
  Calculate *calculate;
};
