import FWCore.ParameterSet.Config as cms

from PhysicsTools.PatAlgos.recoLayer0.jetCorrFactors_cfi import *
from JetMETCorrections.Configuration.JetCorrectionServicesAllAlgos_cff import *

from Configuration.Eras.Modifier_fastSim_cff import fastSim

fastSimPostFix = '_FS'
fastSim.toModify(patJetCorrFactors, payload=cms.string(patJetCorrFactors.payload.value() + fastSimPostFix))

## for scheduled mode
patJetCorrectionsTask = cms.Task(patJetCorrFactors)
patJetCorrections = cms.Sequence(patJetCorrectionsTask)
