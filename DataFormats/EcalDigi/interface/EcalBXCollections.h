#ifndef DIGIECAL_ECALBXCOLLECTION_H
#define DIGIECAL_ECALBXCOLLECTION_H

#include "DataFormats/EcalDigi/interface/EBBXFrame.h"
#include "DataFormats/EcalDigi/interface/EEBXFrame.h"
//#include "DataFormats/EcalDigi/interface/ESBXFrame.h"
//#include "DataFormats/EcalDigi/interface/EcalTriggerPrimitiveDigi.h"
//#include "DataFormats/EcalDigi/interface/EcalTrigPrimCompactColl.h"
//#include "DataFormats/EcalDigi/interface/EcalPseudoStripInputDigi.h"
//#include "DataFormats/EcalDigi/interface/EBSrFlag.h"
//#include "DataFormats/EcalDigi/interface/EESrFlag.h"
//#include "DataFormats/EcalDigi/interface/EcalPnDiodeDigi.h"
//#include "DataFormats/EcalDigi/interface/EcalMatacqDigi.h"
//#include "DataFormats/Common/interface/SortedCollection.h"

#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"
#include "DataFormats/Common/interface/DataFrameContainer.h"

class EcalBXCollection : public edm::DataFrameContainer {
public:
  typedef edm::DataFrameContainer::size_type size_type;
  static const size_type MAXSAMPLES = 16;
  explicit EcalBXCollection(size_type istride=MAXSAMPLES, int isubdet=0)  : 
    edm::DataFrameContainer(istride, isubdet){}
  void swap(DataFrameContainer& other) {this->DataFrameContainer::swap(other);}
};

// make edm (and ecal client) happy
class EBBXCollection : public  EcalBXCollection {
public:
  typedef edm::DataFrameContainer::size_type size_type;
  typedef EBBXFrame Digi;
  typedef Digi::key_type DetId;

  EBBXCollection(size_type istride=MAXSAMPLES) : 
    EcalBXCollection(istride, EcalBarrel){}
  void swap(EBBXCollection& other) {this->EcalBXCollection::swap(other);}
};

class EEBXCollection : public  EcalBXCollection {
public:  
  typedef edm::DataFrameContainer::size_type size_type;
  typedef EEBXFrame Digi;
  typedef Digi::key_type DetId;

  EEBXCollection(size_type istride=MAXSAMPLES) : 
    EcalBXCollection(istride, EcalEndcap){}
  void swap(EEBXCollection& other) {this->EcalBXCollection::swap(other);}
};

/*
class ESBXCollection : public EcalBXCollection 
{
   public:  
      typedef edm::DataFrameContainer::size_type size_type;
      typedef ESDataFrame Digi;
      typedef Digi::key_type DetId;

      static const size_type NSAMPLE = ESDataFrame::MAXSAMPLES ;
      ESBXCollection(size_type istride=NSAMPLE) : 
	 EcalBXCollection(istride, EcalPreshower){}
      void swap(ESBXCollection& other) {this->EcalBXCollection::swap(other);}

      void push_back( unsigned int i ) 
      {
	 DataFrameContainer::push_back( i ) ;
      }

      void push_back( const Digi& digi ) 
      {
	 uint16_t esdata[NSAMPLE] ;
	 for( unsigned int i ( 0 ) ; i != NSAMPLE; ++i )
	 {
	    static const int offset ( 65536 ) ; // for int16 to uint16
	    const int16_t dshort ( digi[i].raw() ) ;
	    const int     dint   ( (int) dshort + // add offset for uint16 conversion
				   ( (int16_t) 0 > dshort ? 
				     offset : (int) 0 ) ) ;
	    esdata[i] = dint ;
	 }
	 EcalBXCollection::push_back( digi.id()(), esdata ) ;
      }
};
*/

// Free swap functions
inline
void swap(EcalBXCollection& lhs, EcalBXCollection& rhs) {
  lhs.swap(rhs);
}

inline
void swap(EBBXCollection& lhs, EBBXCollection& rhs) {
  lhs.swap(rhs);
}

inline
void swap(EEBXCollection& lhs, EEBXCollection& rhs) {
  lhs.swap(rhs);
}

/*
inline
void swap(ESBXCollection& lhs, ESBXCollection& rhs) {
  lhs.swap(rhs);
}
*/
//typedef edm::SortedCollection<EcalTriggerPrimitiveDigi> EcalTrigPrimDigiCollection;
//
//typedef edm::SortedCollection<EcalPseudoStripInputDigi> EcalPSInputDigiCollection;
//typedef edm::SortedCollection<EBSrFlag> EBSrFlagCollection;
//typedef edm::SortedCollection<EESrFlag> EESrFlagCollection;
//typedef edm::SortedCollection<EcalPnDiodeDigi> EcalPnDiodeDigiCollection;
//typedef edm::SortedCollection<EcalMatacqDigi> EcalMatacqDigiCollection;

#endif
