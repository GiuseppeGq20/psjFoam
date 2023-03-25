# jetActuatorFoam
Solver for PSj actuators

## compilation process
The solver and library should succesfully compile with openfoam2206 and 2212 installed on your machine
([how to install openfoam2206](https://develop.openfoam.com/Development/openfoam/-/wikis/precompiled)).
First of all clone this repo on your machine.
    git clone https://github.com/GiuseppeGq20/JetActuatorFoam.git

then cd into it,switch to the relevant branch, for example `dev`:
    
    git switch dev

The first time you do that this will create the branch locally, and it will automatically
track the remote branch with the same name.
To compile all the solvers and library run:

    ./Allwmake

optionally you can add debug option `-debug`, multi process compilation `-j`.
    
    ./Allwmake -j -debug 

## run simpleTest (non confined arc simulation)
You have to cd in `test/simpleTest` and then you can run the Allrun script.
    
    cd test/simpleTest
    ./Allrun.sh

## note
remember to un-ignore each file file you want to track in the test directories

- source terms with [fvOptions](https://www.openfoam.com/documentation/guides/latest/doc/guide-fvoptions-sources.html)
- [mhdFoam](https://www.openfoam.com/documentation/tutorial-guide/2-incompressible-flow/2.3-magnetohydrodynamic-flow-of-a-liquid)
- [IOobject wiki](https://openfoamwiki.net/index.php/OpenFOAM_guide/Input_and_Output_operations_using_dictionaries_and_the_IOobject_class)

## generating compile_command.json for intellisense
use bear with allwmake
    
    ./Allwmake -with-bear

