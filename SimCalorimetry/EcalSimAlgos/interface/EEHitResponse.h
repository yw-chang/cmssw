#ifndef EcalSimAlgos_EEHitResponse_h
#define EcalSimAlgos_EEHitResponse_h

#include "CalibFormats/CaloObjects/interface/CaloTSamples.h"
#include "CalibFormats/CaloObjects/interface/EcalTBXHits.h"
#include "SimCalorimetry/EcalSimAlgos/interface/EcalHitResponse.h"

class EEHitResponse : public EcalHitResponse
{
   public:

      typedef CaloTSamples<float,10> EESamples ;
      typedef EcalTBXHits<float,16> EEBXSamples ;

      EEHitResponse( const CaloVSimParameterMap* parameterMap , 
		     const CaloVShape*           shape          ) ;

      virtual ~EEHitResponse() ;

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

      std::vector<EESamples> m_vSam ;
      std::vector<EEBXSamples> m_vBXSam ;
};
#endif


