#ifndef CALOSAMPLES_H
#define CALOSAMPLES_H 1

#include <ostream>
#include <vector>
#include "DataFormats/DetId/interface/DetId.h"

/** \class EcalBXHits
    
Class which represents the charge/voltage measurements of an event/channel
with the ADC decoding performed.

*/
class EcalBXHits {
public:
  EcalBXHits();
  explicit EcalBXHits(const DetId& id, int size);
  explicit EcalBXHits(const DetId& id, int size, int preciseSize);
 
  /// get the (generic) id
  DetId id() const { return id_; }

  /// get the size
  int size() const { return size_; }
  /// mutable operator to access samples
  double& operator[](int i) { return data_[i]; }
  /// const operator to access samples
  double operator[](int i) const { return data_[i]; }

  /// mutable function to access precise samples
  float& preciseAtMod(int i) { return preciseData_[i]; }
  /// const function to access precise samples
  float preciseAt(int i) const { return preciseData_[i]; }

  /// access presample information
  int presamples() const { return presamples_; }
  /// set presample information
  void setPresamples(int pre);

  /// multiply each item by this value
  EcalBXHits& scale(double value);
  /// scale all samples
  EcalBXHits& operator*=(double value) { return scale(value); }

  /// add a value to all samples
  EcalBXHits& operator+=(double value);
  EcalBXHits& operator+=(const EcalBXHits & other);

  /// shift all the samples by a time, in ns, interpolating
  // between values
  EcalBXHits& offsetTime(double offset);

  void setDetId( DetId detId ) { id_ = detId ; }

  void setSize( unsigned int size ) { size_ = size ; }

  bool isBlank() const ; // are the samples blank (zero?)

  void setBlank() ; // keep id, presamples, size but zero out data

  /// get the size
  int preciseSize() const { if ( preciseData_.size() ==0 ) return 0; return preciseSize_; }
  int precisePresamples() const { return precisePresamples_; }
  float preciseDeltaT() const { return deltaTprecise_; }

  void setPrecise( int precisePresamples, float deltaT ) {
    precisePresamples_=precisePresamples;
    deltaTprecise_=deltaT;
  }

  void resetPrecise();

  static const int MAXSAMPLES=16;
private:
  DetId id_;
  double data_[MAXSAMPLES]; // 
  int size_, presamples_;
  float deltaTprecise_;
  std::vector<float> preciseData_;
  int preciseSize_,precisePresamples_;
};

std::ostream& operator<<(std::ostream& s, const EcalBXHits& samps);

#endif
