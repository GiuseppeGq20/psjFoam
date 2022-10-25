# jetAxtuatorFoam
Solver for PSj actuators


## note
remember to un-ignore each file file you want to track in the test directories

- source terms with [fvOptions](https://www.openfoam.com/documentation/guides/latest/doc/guide-fvoptions-sources.html)
- [mhdFoam](https://www.openfoam.com/documentation/tutorial-guide/2-incompressible-flow/2.3-magnetohydrodynamic-flow-of-a-liquid)

## diff Conte

- Conte non mette AEqn e la forza di Lorentz nella UEqn
- L’effetto Joule nella EEqn di Conte è moltiplicato per 0.6
- L’effetto Joule è calcolato nella PotEqn di Conte come JouleEffect= mySigma*(fvc::grad(V) & fvc::grad(V));
