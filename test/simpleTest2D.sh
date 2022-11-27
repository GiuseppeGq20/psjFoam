#!/bin/bash

# run simpleTest2D
#

# Variables
currentDir="$(pwd)"

caseName=simpleTest2D
caseRun=/dev/shm
# base dictionary name
dictName=thermophysicalProperties

cases=("my" "orig")
apps=("myrhoPimpleFoam" "rhoPimpleFoam")


echo "copy case in $caseRun"

#check if the running dir exist and copy the directory where the test are run
if [ -d "$caseRun/$caseName" ]
then
    rm -r "$caseRun/$caseName"
fi
cp -r $caseName $caseRun

echo "creating logs dir"

#check if output log directory exist and if so delete it
if [ ! -d logs ]
then
    mkdir logs
else
    rm -r logs
    mkdir logs
fi

#cd in the directory where the test are run
cd "$caseRun/$caseName"

echo "create axisym mesh"
blockMesh -dict system/blockMeshDict.axisym &>blockMesh.log
extrudeMesh &>extrudeMesh.log
echo "meshing done"
echo ""


echo "#---run cases ---#"
for Case in ${cases[@]}; do
    for App in ${apps[@]}; do
        
        echo "running $App with $dictName.$Case, Axissym case"

        cp constant/$dictName.$Case constant/$dictName
        
        if [ -d 0 ]
        then 
            rm -r 0 
        fi
        cp -r 0.orig.axisym 0
        setFields &>/dev/null
        $App &> $App.$Case.log
        
        echo "copying logs"
        cp *.log "$currentDir/logs"
        
    done
done
echo "#--- ---#"

cd -

echo "done"
