#ifndef ECALTBXHITS_H
#define ECALTBXHITS_H 1

#include "CalibFormats/CaloObjects/interface/EcalTBXHitsBase.h"

/** \class EcalTBXHits
    
Class which represents the charge/voltage measurements of an event/channel
with the ADC decoding performed.

*/

template <class Ttype, uint32_t Tsize> 
class EcalTBXHits : public EcalTBXHitsBase<Ttype>
{
   public:

      enum { kCapacity = Tsize } ;

      EcalTBXHits<Ttype,Tsize>()  ;
      EcalTBXHits<Ttype,Tsize>( const EcalTBXHits<Ttype,Tsize>& cs )  ;
      EcalTBXHits<Ttype,Tsize>( const DetId& id   , 
				 uint32_t size = 0 ,
				 uint32_t pre  = 0  ) ;
      virtual ~EcalTBXHits<Ttype,Tsize>() ;

      EcalTBXHits<Ttype,Tsize>& operator=( const EcalTBXHits<Ttype,Tsize>& cs ) ;

      virtual uint32_t capacity() const ;

   private:

      virtual       Ttype* data(  uint32_t i ) ;
      virtual const Ttype* cdata( uint32_t i ) const ;

      Ttype m_data[ Tsize ] ;
} ;

#endif
