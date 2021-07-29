#ifndef PostProcessor_
#define PostProcessor_

#include <map>
#include <iomanip>

// root
#include "TFile.h"
#include "TCanvas.h"
#include "TRegexp.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStyle.h"

// largex-eic
#include "Histos.h"
#include "Kinematics.h"
#include "CutDef.h"
#include "BinSet.h"

class PostProcessor : public TNamed
{
  public:
    PostProcessor(
        TString infileN_,
        Bool_t plotRatioOnly_=false
        );
    ~PostProcessor();

    // settings
    // - canvas dimensions [pixels]
    const Int_t dimx=800;
    const Int_t dimy=700;
    static const int nsumMax=3; // number of summary plots with formatting


    // cleanup and close open files and streams
    // - MUST be called at the end of any postprocessor macro, after
    //   all algorithms have finished
    void Finish();


    // algorithms: useful to run in loops over bins
    // - see PostProcessor.cxx for descriptions for how to use these
    // - these are general functions that operate either on Histos 
    //   objects, or on histograms
    // - they can be shared in any postprocessor macro
    // - they can be anything, such as taking ratios of each histogram
    //   from two different Histos objects (e.g., y>0.05 / y>0.00 sets)
    // - you are welcome to add your own algorithms
    void DumpHist(TString datFile, TString histSet, TString varName);
    void DumpAve(TString datFile, TString histSet, TString cutName);
    void DrawSingle(TString outName, TString histSet, TString varName);
    void DrawRatios(TString outName, TString numerSet, TString denomSet);

    // algorithm finish methods; to be called after loops
    void PostProcessor::FinishDumpAve(TString datFile);

    // accessors
    TString GetPngDir() { return pngDir; };
    BinSet *GetBinSet(TString varName);
    std::vector<int> GetBinNums(TString varName);

    // text file manipulation
    void StartTextFile(TString datFile, TString firstLine="");
    void AppendToTextFile(TString datFile, TString appendText);
    void Columnify(TString inputFile, TString outputFile);

    // reset algorithm-specific variables
    void ResetVars();

  private:

    // files and names
    TString infileN, outfileN, pngDir;
    TFile *infile, *outfile;

    // algorithm-specific variables
    Bool_t plotRatioOnly;
    std::map<TString,TCanvas*> summaryCanvMap;
    std::vector<TString> varList;
    int nsum,ndump;
    CutDef *dumpCut;
    TCanvas *summaryCanv;
    Color_t summaryColor[nsumMax];
    Style_t summaryStyle[nsumMax];

  ClassDef(PostProcessor,1);
};

#endif
