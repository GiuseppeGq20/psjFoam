// Solve the Maxwell equation for the scalar potential

fvScalarMatrix VEqn
(
    fvm::laplacian(sigma, V) 
// == 
    //fvOptions(V)
);

//fiEqn.relax();

//fvOptions.constrain(fiEqn);

VEqn.solve();
// calc current
//volVectorField J = sigma*fvc::grad(V);
