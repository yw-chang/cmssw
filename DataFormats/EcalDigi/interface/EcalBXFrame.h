#ifndef DIGIECAL_ECALBXFRAME_H
#define DIGIECAL_ECALBXFRAME_H

//#include "DataFormats/EcalDigi/interface/EcalMGPASample.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/Common/interface/DataFrame.h"

/** \class EcalBXFrame
      
*/
class EcalBXFrame {
 public:
  EcalBXFrame() {}
  EcalBXFrame(edm::DataFrame const & iframe) : m_data(iframe){} 

  virtual ~EcalBXFrame() {} 

  DetId id() const { return m_data.id();}
    
  int size() const { return m_data.size();}

  uint16_t operator[](int i) const { return m_data[i];}
  uint16_t sample(int i) const { return m_data[i]; }
  //float operator[](int i) const { return m_data[i];}
  //float sample(int i) const { return m_data[i]; }

  void setSize(int){}
  void setSample(int i, uint16_t sam) { m_data[i]=sam; }
  //void setSample(int i, float sam) { m_data[i]=sam; }

  static const int MAXSAMPLES = 16;

  edm::DataFrame const & frame() const { return m_data;}
  edm::DataFrame & frame() { return m_data;}

 private:
 
  edm::DataFrame m_data;
  
};
  
#endif
