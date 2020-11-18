#include "assign4.h"

using namespace std;

int main(int argc, char** argv){
  Windows *windows = new Windows();
  Simulate *simulate = new Simulate(windows);
  Calculate *calculate = new Calculate(windows);

  FileIO *fileIO = new FileIO(windows, simulate, calculate);
  fileIO->ReadFile(argv[1]);

  simulate->RunSimulation();

  calculate->RunCalculations();
  calculate->PrintCalculations();

  delete fileIO;
  delete calculate;
  delete simulate;
  delete windows;
}
