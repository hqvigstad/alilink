#include "TSystem.h"
#include "TROOT.h"
#include "TChain.h"
#include "AliAnalysisManager.h"
#include "AliESDInputHandler.h"

#include "CreateESDChain.C"

#include "AliAnalysisTaskPt.h"

void runAliTask() {
  TStopwatch timer;
  timer.Start();
//   gSystem->Load("libTree.so");
//   gSystem->Load("libGeom.so");
//   gSystem->Load("libVMC.so");
//   gSystem->Load("libPhysics.so");
//   //____________________________________________________//
//   //_____________Setting up required packages___________//
//   //____________________________________________________//
//   gSystem->Load("libSTEERBase.so");
//   gSystem->Load("libESD.so");
//   gSystem->Load("libAOD.so");
//   gSystem->Load("libANALYSIS.so");
//   gSystem->Load("libANALYSISalice.so");
//   gROOT->ProcessLine(".include $ALICE_ROOT/include");
// 
//   //___________Compile analysis task using AClic____________//
//   gROOT->LoadMacro("../task/AliAnalysisTaskPt.cxx+g");
// 
// 
//   gROOT->LoadMacro("$ALICE_ROOT/PWG0/CreateESDChain.C");

  TChain* chain = CreateESDChain("files.txt", 2);

  //____________________________________________//
  // Make the analysis manager
  AliAnalysisManager *mgr = new AliAnalysisManager("TestManager");
  AliESDInputHandler* esdH = new AliESDInputHandler();
  mgr->SetInputEventHandler(esdH);  
  //____________________________________________//
  // 1st Pt task
  AliAnalysisTaskPt *task1 = new AliAnalysisTaskPt("TaskPt");
  mgr->AddTask(task1);
  // Create containers for input/output
  AliAnalysisDataContainer *cinput1 = mgr->CreateContainer("cchain1",TChain::Class(),AliAnalysisManager::kInputContainer);
  AliAnalysisDataContainer *coutput1 = mgr->CreateContainer("chist1", TH1::Class(),AliAnalysisManager::kOutputContainer,"Pt.ESD.root");
  
  //____________________________________________//
  mgr->ConnectInput(task1,0,cinput1);
  mgr->ConnectOutput(task1,0,coutput1);
  if (!mgr->InitAnalysis()) return;
  mgr->PrintStatus();
  //mgr->StartAnalysis("local",chain);

  timer.Stop();
  timer.Print();
}
