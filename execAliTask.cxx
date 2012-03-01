#include "AliRun.h"
#include "TRint.h"

#include "testRoot.C"
#include "runAliTask.C"

int main(int argc, char* argv[])
{
  // This Initializes the AliROOT enviroment, global variables etc...
  // In some cases this may be removed, methinks.
  new AliRun("gAlice","The ALICE Off-line Simulation Framework");

  // This Initializes the Root enviorment, global variables etc...
  // In some cases this may be removed, methinks.
  TRint *theApp = new TRint("ROOT example", &argc, argv);

  // Don't know what this does, but i keept it...
  #ifdef FORTRAN_G95
    g95_runtime_start();
  #endif


  // here you can do whatever, for instance run testRoot.
  testRoot();
  runAliTask();
  

  // starts interactive cint session.
  // If reomved,the program will just close.
  theApp->Run();

  return 0;
}