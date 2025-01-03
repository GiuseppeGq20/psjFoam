# psjFoam
Solver for PSj actuators

## compilation process
The solver and library should succesfully compile with OpenFoam-v2412 onwards.
([how to install openfoam](https://develop.openfoam.com/Development/openfoam/-/wikis/precompiled)).
First of all clone this repo on your machine.
    git clone https://github.com/GiuseppeGq20/JetActuatorFoam.git

To compile all the solvers and library run:

    ./Allwmake

optionally you can add debug option `-debug` and multi process compilation `-j`.
    
    ./Allwmake -j -debug 

## run simpleTest (non confined arc simulation)
You have to cd in `test/simpleTest` and then you can run the Allrun script.
    
    cd test/simpleTest
    ./Allrun.sh

## generate compile_command.json for intellisense
use bear with allwmake
    
    ./Allwmake -with-bear

