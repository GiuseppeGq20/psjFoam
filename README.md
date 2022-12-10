# jetAxtuatorFoam
Solver for PSj actuators

## compilation process
The solver and library should succesfully compile with openfoam2206 installed on your machine
([how to install openfoam2206](https://develop.openfoam.com/Development/openfoam/-/wikis/precompiled)).
First of all clone this repo on your machine.
    git clone https://github.com/GiuseppeGq20/JetActuatorFoam.git

then cd into it,switch to the relevant branch, for example `sigma-solver`:
    
    git checkout sigma-solver

The first time you do that this will create the branch locally, and it will automatically
track the remote branch with the same name.
To compile all the solvers and library run:

    ./Allwmake

optionally you can add debug option `-debug`, multi process compilation `-j`.
    
    ./Allwmake -j -debug 

## run simpleTest2D
You have to cd in `test/simpleTest2D` and then you can run the Allrun script.
    
    cd test/simpleTest2D
    ./Allrun.axisym.sh

## note
remember to un-ignore each file file you want to track in the test directories

- source terms with [fvOptions](https://www.openfoam.com/documentation/guides/latest/doc/guide-fvoptions-sources.html)
- [mhdFoam](https://www.openfoam.com/documentation/tutorial-guide/2-incompressible-flow/2.3-magnetohydrodynamic-flow-of-a-liquid)
- [IOobject wiki](https://openfoamwiki.net/index.php/OpenFOAM_guide/Input_and_Output_operations_using_dictionaries_and_the_IOobject_class)

## diff Conte

- Conte non mette AEqn e la forza di Lorentz nella UEqn
- L’effetto Joule nella EEqn di Conte è moltiplicato per 0.6
- L’effetto Joule è calcolato nella PotEqn di Conte come JouleEffect= mySigma*(fvc::grad(V) & fvc::grad(V));

## generating compile_command.json for intellisense
use bear with allwmake
    
    ./Allwmake -with-bear

## hypothesis on whhy simpleTest2D keeps failing
Due to the current initialization:
- V=0 internal field and dirichlet on electrod faces
- T>5000 K on the inter electrod space while T=298 K elsewhere
we think that the simulation undergoes an unphysical transient period with an 
unphysical electric field (grad(V)) between the electrods
that leads to a joule heating term >1e15, so it becames the
leading term and as a result we have a sensisble hentalpy > 1e8 that fails the 
Newton-Rhapson algorithm to calculate the temperature distribution.
