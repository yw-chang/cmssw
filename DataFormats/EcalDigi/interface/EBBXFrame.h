#ifndef DIGIECAL_EBBXFRAME_H
#define DIGIECAL_EBBXFRAME_H

#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDigi/interface/EcalBXFrame.h"
#include <iosfwd>



/** \class EBBXFrame
      
*/
class EBBXFrame : public EcalBXFrame 
{
 public:
  typedef EBDetId key_type; ///< For the sorted collection
  typedef EcalBXFrame Base;

  EBBXFrame() {}
  // EBBXFrame(DetId i) :  Base(i) {}
  EBBXFrame(edm::DataFrame const & base) : Base(base) {}
  EBBXFrame(EcalBXFrame const & base) : Base(base) {}

  /** estimator for a signal being a spike
   *  based on ratios between 4th, 5th and 6th sample
   */
  float spikeEstimator() const;
    
  virtual ~EBBXFrame() {}

  key_type id() const { return Base::id(); }

};

std::ostream& operator<<(std::ostream&, const EBBXFrame&);


#endif
