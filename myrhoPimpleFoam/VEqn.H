// Solve the Maxwell equation for the scalar potential

fvScalarMatrix VEqn
(
    fvm::laplacian(sigma, V) 
// == 
    //fvOptions(V)
);

// fvVectorMatrix& UEqn = tUEqn.ref();

//fiEqn.relax();

//fvOptions.constrain(fiEqn);
//Info<<"cos"<<Foam::cos(2*3.14*runTime.value()) << nl <<endl;

VEqn.solve();
//Info<<"Max/Min value of V"<<nl<<Foam::max(V)<<Foam::min(V)<<endl;

// calc current
volVectorField J = sigma*fvc::grad(V);
