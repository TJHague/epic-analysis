#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

// histograms
#pragma link C++ class Hist4D+;
#pragma link C++ class Histos+;
#pragma link C++ class HistConfig+;
#pragma link C++ class Adage<Histos>+;
#pragma link C++ class HistosDAG+;

// analysis objects
#pragma link C++ class Kinematics+;
#pragma link C++ class SimpleTree+;
#pragma link C++ class Weights+;
#pragma link C++ class WeightsUniform+;
#pragma link C++ class WeightsSivers+;
#pragma link C++ class WeightsCollins+;
#pragma link C++ class WeightsProduct+;
#pragma link C++ class WeightsSum+;

// analysis event loop classes
#pragma link C++ class Analysis+;
#pragma link C++ class AnalysisAthena+;
#pragma link C++ class AnalysisEcce+;
#pragma link C++ class AnalysisDelphes+;

// postprocessing
#pragma link C++ class PostProcessor+;

#endif
