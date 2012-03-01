#include "TRint.h"
#include "testRoot.C"

int main(int argc, char* argv[])
{
  // This Initializes the Root enviorment, global variables etc...
  // In some cases this may be removed, methinks.
  TRint *theApp = new TRint("ROOT example", &argc, argv);

  // here you can do whatever, for instance run testRoot.
  testRoot();

  // starts interactive cint session.
  // If reomved,the program will just close.
  theApp->Run();

  return 0;
}