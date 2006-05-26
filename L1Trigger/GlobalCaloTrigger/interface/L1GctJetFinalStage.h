#ifndef L1GCTJETFINALSTAGE_H_
#define L1GCTJETFINALSTAGE_H_

#include "L1Trigger/GlobalCaloTrigger/interface/L1GctJetCand.h"
#include "L1Trigger/GlobalCaloTrigger/interface/L1GctProcessor.h"
#include "L1Trigger/GlobalCaloTrigger/interface/L1GctWheelJetFpga.h"
#include "L1Trigger/GlobalCaloTrigger/interface/L1GctEtTypes.h"

#include <vector>

/*
 * The GCT Jet classify and sort algorithms
 * author: Jim Brooke
 * date: 20/2/2006
 * 
 */

class L1GctJetFinalStage : public L1GctProcessor
{
public:
	L1GctJetFinalStage(std::vector<L1GctWheelJetFpga*> m_wheelFpgas);
	~L1GctJetFinalStage();

  typedef std::vector<L1GctJetCand> JetVector;

  /// Overload << operator
  friend std::ostream& operator << (std::ostream& os, const L1GctJetFinalStage& fpga);

  /// clear internal buffers
  virtual void reset();

  /// get input data from sources
  virtual void fetchInput();

  /// process the data, fill output buffers
  virtual void process();
    	
  // set input data
  void setInputCentralJet(int i, L1GctJetCand jet);
  void setInputForwardJet(int i, L1GctJetCand jet);
  void setInputTauJet(int i, L1GctJetCand jet); 

  // return input data
  JetVector getInputCentralJets() const { return m_inputCentralJets; }
  JetVector getInputForwardJets() const { return m_inputForwardJets; }
  JetVector getInputTauJets() const { return m_inputTauJets; }

  // return output data
  JetVector getCentralJets() const { return m_centralJets; }
  JetVector getForwardJets() const { return m_forwardJets; }
  JetVector getTauJets() const { return m_tauJets; }
private:

  /// Max number of wheel FPGA pointers
  static const unsigned int MAX_WHEEL_FPGAS = 2;
  /// Max number of jets of each type coming in
  static const int MAX_JETS_IN = MAX_WHEEL_FPGAS*L1GctWheelJetFpga::MAX_JETS_OUT;
  /// Max number of jets of each type going out
  static const int MAX_JETS_OUT = 4;
  
  /// wheel jet FPGAs
  std::vector<L1GctWheelJetFpga*> m_wheelFpgas;

  // input data
  JetVector m_inputCentralJets;
  JetVector m_inputForwardJets;
  JetVector m_inputTauJets;

  // output data
  JetVector m_centralJets;
  JetVector m_forwardJets;
  JetVector m_tauJets;

  //PRIVATE MEMBER FUNCTIONS
  ///Enters jets into the specified storageVector, according to which wheel card we are taking them from.
  void storeJets(JetVector& storageVector, JetVector jets, unsigned short iWheel);
  
};

std::ostream& operator << (std::ostream& os, const L1GctJetFinalStage& fpga);

#endif /*L1GCTJETFINALSTAGE_H_*/
