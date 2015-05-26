#ifndef EcalSimAlgos_ESHitResponse_h
#define EcalSimAlgos_ESHitResponse_h

#include "CalibFormats/CaloObjects/interface/CaloTSamples.h"
#include "CalibFormats/CaloObjects/interface/EcalTBXHits.h"
#include "SimCalorimetry/EcalSimAlgos/interface/EcalHitResponse.h"

class ESHitResponse : public EcalHitResponse
{
   public:

      typedef CaloTSamples<float,3> ESSamples ;
      typedef EcalTBXHits<float,16> ESBXSamples ;

      ESHitResponse( const CaloVSimParameterMap* parameterMap , 
		     const CaloVShape*           shape          ) ;

      virtual ~ESHitResponse() ;

      virtual bool keepBlank() const { return false ; }

      virtual unsigned int samplesSize() const ;

      virtual EcalSamples* operator[]( unsigned int i ) ;

      virtual const EcalSamples* operator[]( unsigned int i ) const ;


      virtual unsigned int BXsamplesSize() const ;

      virtual unsigned int BXsamplesSizeAll() const ;

      virtual EcalBXSamples* vBXSamAll( unsigned int i ) ;

      virtual const EcalBXSamples* vBXSamAll( unsigned int i ) const ;

      virtual EcalBXSamples* vBXSam( unsigned int i ) ;

   protected:

      virtual unsigned int samplesSizeAll() const ;

      virtual EcalSamples* vSamAll( unsigned int i ) ;

      virtual const EcalSamples* vSamAll( unsigned int i ) const ;

      virtual EcalSamples* vSam( unsigned int i ) ;

   private:

      std::vector<ESSamples> m_vSam ;
      std::vector<ESBXSamples> m_vBXSam ;
};
#endif


