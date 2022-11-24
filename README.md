# jetAxtuatorFoam
Solver for PSj actuators


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
> `./Allwmake -with-bear`
