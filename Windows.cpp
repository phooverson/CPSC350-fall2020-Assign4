#include "assign4.h"

//default Constructor
Windows::Windows(){
  int totalWindows;
}

//default destructor
Windows::~Windows(){
 //cout << "bye windows" << endl;
}

//set the total number of windows and create the appropriate amount of windows
void Windows::SetTotalWindows(int windowCount){
  totalWindows = windowCount;
  Window *window;
  if (windowList->getSize() == 0){
    for (int i = 0; i < totalWindows; ++i){
      window = new Window();
      windowList->insertFront(window);
    }
  }
}

//get a window are a cirtain position
Window* Windows::GetWindow(int windowNumber){
  return windowList->atPos(windowNumber);
}

//see if there are any open windows
bool Windows::CheckForOpenWindow(){
  for(int i = 0; i < totalWindows; i++){
    Window *currentWindow = windowList->atPos(i);
    if(currentWindow->IsOpen())
      return true;
  }
  return false;
}

//get the position of the first open window
int Windows::GetOpenWindowPosition(){
  for(int i = 0; i < totalWindows; i++){
    Window *currentWindow = windowList->atPos(i);
    if(currentWindow->IsOpen())
      return i;
  }
}

//check if all windows are open
bool Windows::AreAllWindowsOpen(){
  bool allWindowsOpen = true;
  for(int i = 0; i < totalWindows; i++){
    Window *currentWindow = windowList->atPos(i);
    if(!currentWindow->IsOpen())
      allWindowsOpen = false;
  }
  return allWindowsOpen;
}

//increment time for all windows
void Windows::IncrementWindowTime(){
  for(int i = 0; i < totalWindows; i++){
    Window *currentWindow = windowList->atPos(i);
    currentWindow->IncrementIdleTime();
  }
}

//get the max idle time of all windows
int Windows::getMaxIdleTime(){
  int maxIdleTime = 0;
  for(int i = 0; i < totalWindows; i++){
    Window* currentWindow = windowList->atPos(i);
    if(currentWindow->GetWaitTime() > maxIdleTime)
      maxIdleTime = currentWindow->GetWaitTime();
  }
  return maxIdleTime;
}

//return th total number of windows that were idle for more then 5 minutes
int Windows::getNumberOfIdleWindowsOverFiveMinutes(){
  int numberOfIdleWindowsOverFiveMinutes = 0;
  for(int i = 0; i < totalWindows; i++){
    Window* currentWindow = windowList->atPos(i);
    if(currentWindow->GetWaitTime() > 5)
      numberOfIdleWindowsOverFiveMinutes++;
  }
  return numberOfIdleWindowsOverFiveMinutes;
}

//retunr the mean window idle time
double Windows::getMeanWindowIdleTime(){
  double meanIdleTime = 0.0;
  for(int i = 0; i < totalWindows; i++){
    Window* currentWindow = windowList->atPos(i);
    meanIdleTime += currentWindow->GetWaitTime();
  }
  return meanIdleTime/windowList->getSize();
}
