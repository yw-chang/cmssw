import FWCore.ParameterSet.Config as cms

ecal_bx_dump = cms.PSet(
    EBBXCollection = cms.string(''),
    EEBXCollection = cms.string(''),
    doBXdump       = cms.bool(True)
)

