#!/bin/sh
cd "${0%/*}" || exit                                # Run from this directory
. ${WM_PROJECT_DIR:?}/bin/tools/RunFunctions        # Tutorial run functions
#------------------------------------------------------------------------------

#restore0Dir
rm log.*
rm -r 0 
cp -r 0.orig 0
runApplication foamListTimes -rm

runApplication blockMesh 

runApplication extrudeMesh

#runApplication refineMesh -overwrite
#runApplication refineMesh -overwrite
runApplication setFields

runApplication topoSet
#runApplication setExprFields
runApplication  decomposePar -force

#runApplication $(getApplication)
runParallel $(getApplication)

#------------------------------------------------------------------------------
