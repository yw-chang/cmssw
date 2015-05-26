#ifndef DIGIECAL_EEBXFRAME_H
#define DIGIECAL_EEBXFRAME_H

#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/EcalDigi/interface/EcalBXFrame.h"
#include <iosfwd>



/** \class EEBXFrame
      
*/


class EEBXFrame : public EcalBXFrame 
{
 public:
  typedef EEDetId key_type; ///< For the sorted collection
  typedef EcalBXFrame Base;

  EEBXFrame() {}
  EEBXFrame(edm::DataFrame const & base) : Base(base) {}
  EEBXFrame(EcalBXFrame const & base) : Base(base) {}
    
  virtual ~EEBXFrame() {}

  key_type id() const { return Base::id(); }

};


std::ostream& operator<<(std::ostream&, const EEBXFrame&);


#endif
