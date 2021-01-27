//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 11 17:13:09 2018 by ROOT version 6.14/00
// from TTree tree/Tagger events
// found on file: /nfs/ldas01/d01-3/ag_au/NEPTUN_2018/August2018/root/r010_0011.root
//////////////////////////////////////////////////////////

#ifndef test_h
#define test_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class test {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          event_cnt;
   vector<unsigned int> *gala_ch;
   vector<double>  *gala_tsC;
   vector<unsigned int> *gala_pileup;
   vector<unsigned int> *gala_En;
   vector<double>  *gala_En_cal;
   vector<unsigned int> *ge_ch;
   vector<double>  *ge_tsC;
   vector<unsigned int> *ge_pileup;
   vector<unsigned int> *ge_En;
   vector<double>  *ge_En_cal;
   vector<unsigned int> *sipm_num;
   vector<double>  *sipm_tsC;
   vector<unsigned int> *sipm_pileup;
   vector<unsigned int> *sipm_En;
   vector<unsigned int> *sipm_mpc;
   vector<unsigned int> *strip_num;
   vector<unsigned int> *strip_mpc;
   vector<double>  *strip_tsC1;
   vector<double>  *strip_tsC2;
   vector<double>  *strip_tsC;
   vector<unsigned int> *strip_En1;
   vector<unsigned int> *strip_En2;
   vector<unsigned int> *strip_sumEnergy;
   vector<double>  *strip_gala_tdiff;
   vector<double>  *gala_En_coinc;
   vector<double>  *gala_ch_coinc;
   vector<double>  *strip_gala_coinc;

   // List of branches
   TBranch        *b_event_cnt;   //!
   TBranch        *b_gala_ch;   //!
   TBranch        *b_gala_tsC;   //!
   TBranch        *b_gala_pileup;   //!
   TBranch        *b_gala_En;   //!
   TBranch        *b_gala_En_cal;   //!
   TBranch        *b_ge_ch;   //!
   TBranch        *b_ge_tsC;   //!
   TBranch        *b_ge_pileup;   //!
   TBranch        *b_ge_En;   //!
   TBranch        *b_ge_En_cal;   //!
   TBranch        *b_sipm_num;   //!
   TBranch        *b_sipm_tsC;   //!
   TBranch        *b_sipm_pileup;   //!
   TBranch        *b_sipm_En;   //!
   TBranch        *b_sipm_mpc;   //!
   TBranch        *b_strip_num;   //!
   TBranch        *b_strip_mpc;   //!
   TBranch        *b_strip_tsC1;   //!
   TBranch        *b_strip_tsC2;   //!
   TBranch        *b_strip_tsC;   //!
   TBranch        *b_strip_En1;   //!
   TBranch        *b_strip_En2;   //!
   TBranch        *b_strip_sumEnergy;   //!
   TBranch        *b_strip_gala_tdiff;   //!
   TBranch        *b_gala_En_coinc;   //!
   TBranch        *b_gala_ch_coinc;   //!
   TBranch        *b_strip_gala_coinc;   //!

   test(TTree *tree=0);
   virtual ~test();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef test_cxx
test::test(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/nfs/ldas01/d01-3/ag_au/NEPTUN_2018/August2018/root/r010_0011.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/nfs/ldas01/d01-3/ag_au/NEPTUN_2018/August2018/root/r010_0011.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

test::~test()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t test::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t test::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void test::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   gala_ch = 0;
   gala_tsC = 0;
   gala_pileup = 0;
   gala_En = 0;
   gala_En_cal = 0;
   ge_ch = 0;
   ge_tsC = 0;
   ge_pileup = 0;
   ge_En = 0;
   ge_En_cal = 0;
   sipm_num = 0;
   sipm_tsC = 0;
   sipm_pileup = 0;
   sipm_En = 0;
   sipm_mpc = 0;
   strip_num = 0;
   strip_mpc = 0;
   strip_tsC1 = 0;
   strip_tsC2 = 0;
   strip_tsC = 0;
   strip_En1 = 0;
   strip_En2 = 0;
   strip_sumEnergy = 0;
   strip_gala_tdiff = 0;
   gala_En_coinc = 0;
   gala_ch_coinc = 0;
   strip_gala_coinc = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event_cnt", &event_cnt, &b_event_cnt);
   fChain->SetBranchAddress("gala_ch", &gala_ch, &b_gala_ch);
   fChain->SetBranchAddress("gala_tsC", &gala_tsC, &b_gala_tsC);
   fChain->SetBranchAddress("gala_pileup", &gala_pileup, &b_gala_pileup);
   fChain->SetBranchAddress("gala_En", &gala_En, &b_gala_En);
   fChain->SetBranchAddress("gala_En_cal", &gala_En_cal, &b_gala_En_cal);
   fChain->SetBranchAddress("ge_ch", &ge_ch, &b_ge_ch);
   fChain->SetBranchAddress("ge_tsC", &ge_tsC, &b_ge_tsC);
   fChain->SetBranchAddress("ge_pileup", &ge_pileup, &b_ge_pileup);
   fChain->SetBranchAddress("ge_En", &ge_En, &b_ge_En);
   fChain->SetBranchAddress("ge_En_cal", &ge_En_cal, &b_ge_En_cal);
   fChain->SetBranchAddress("sipm_num", &sipm_num, &b_sipm_num);
   fChain->SetBranchAddress("sipm_tsC", &sipm_tsC, &b_sipm_tsC);
   fChain->SetBranchAddress("sipm_pileup", &sipm_pileup, &b_sipm_pileup);
   fChain->SetBranchAddress("sipm_En", &sipm_En, &b_sipm_En);
   fChain->SetBranchAddress("sipm_mpc", &sipm_mpc, &b_sipm_mpc);
   fChain->SetBranchAddress("strip_num", &strip_num, &b_strip_num);
   fChain->SetBranchAddress("strip_mpc", &strip_mpc, &b_strip_mpc);
   fChain->SetBranchAddress("strip_tsC1", &strip_tsC1, &b_strip_tsC1);
   fChain->SetBranchAddress("strip_tsC2", &strip_tsC2, &b_strip_tsC2);
   fChain->SetBranchAddress("strip_tsC", &strip_tsC, &b_strip_tsC);
   fChain->SetBranchAddress("strip_En1", &strip_En1, &b_strip_En1);
   fChain->SetBranchAddress("strip_En2", &strip_En2, &b_strip_En2);
   fChain->SetBranchAddress("strip_sumEnergy", &strip_sumEnergy, &b_strip_sumEnergy);
   fChain->SetBranchAddress("strip_gala_tdiff", &strip_gala_tdiff, &b_strip_gala_tdiff);
   fChain->SetBranchAddress("gala_En_coinc", &gala_En_coinc, &b_gala_En_coinc);
   fChain->SetBranchAddress("gala_ch_coinc", &gala_ch_coinc, &b_gala_ch_coinc);
   fChain->SetBranchAddress("strip_gala_coinc", &strip_gala_coinc, &b_strip_gala_coinc);
   Notify();
}

Bool_t test::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void test::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t test::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef test_cxx
