#!/bin/sh
cd "${0%/*}" || exit                                # Run from this directory
. ${WM_PROJECT_DIR:?}/bin/tools/RunFunctions        # Tutorial run functions
#------------------------------------------------------------------------------

#restore0Dir
rm log.*
rm -r 0 
cp -r 0.orig 0
runApplication foamListTimes -rm

runApplication blockMesh -dict system/blockMeshDict.arcdischarge 

runApplication setFields -dict system/setFieldsDict.arcdischarge

runApplication  decomposePar -force

#runApplication $(getApplication)
runParallel $(getApplication)

#------------------------------------------------------------------------------
