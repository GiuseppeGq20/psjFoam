#!/bin/sh
cd "${0%/*}" || exit                                # Run from this directory
. ${WM_PROJECT_DIR:?}/bin/tools/RunFunctions        # Tutorial run functions
#------------------------------------------------------------------------------

#restore0Dir
#rm log.*
runApplication foamListTimes -rm

rm -r 0 
cp -r 0.orig 0

#runApplication blockMesh 

#mirrorMesh -overwrite

#mirrorMesh -overwrite -dict system/mirrorMeshDict.second

#runApplication refineMesh -overwrite
#runApplication refineMesh -overwrite

runApplication topoSet

runApplication setFields

#runApplication setExprFields
runApplication  decomposePar -force

#runApplication $(getApplication)
runParallel $(getApplication)

#------------------------------------------------------------------------------
