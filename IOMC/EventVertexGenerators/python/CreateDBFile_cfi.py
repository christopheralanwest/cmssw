import IOMC.EventVertexGenerators.VtxSmearedParameters_cfi as VtxSmearedParameters

import FWCore.ParameterSet.Config as cms

process = cms.Process("UPLOAD")

process.source = cms.Source("EmptySource")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)
process.load("CondCore.CondDB.CondDB_cfi")

process.upload = cms.EDAnalyzer("BeamProfile2DB",
                                VtxSmearedParameters.Run3RoundOptics25ns13TeVLowSigmaZVtxSmearingParameters)

process.PoolDBOutputService = cms.Service(
    "PoolDBOutputService",
    DBParameters = cms.PSet(
        messageLevel = cms.untracked.int32(0),
        authenticationPath = cms.untracked.string('.')
    ),
    connect = cms.string('sqlite_file:simbeamspot.db'),
    timetype = cms.untracked.string('runnumber'),
    toPut = cms.VPSet(cms.PSet(
        record = cms.string("SimBeamSpotObjectsRcd"),
        tag = cms.string("Run3RoundOptics25ns13TeVLowSigmaZVtxSmearingParameters")
    ))
)

process.e = cms.Path(process.upload)
