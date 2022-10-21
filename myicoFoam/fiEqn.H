// Solve the Maxwell equation for the scalar potential

const dimensionedScalar myone
(
    "myone",
    dimensionSet(0 , 0, -1, 0, 0, 0, 0),
    scalar(1)
);


//volScalarField source ;
fvScalarMatrix fiEqn
(
    fvm::laplacian(sigma, fi) 
 == myone*Foam::cos(2*3.14*runTime.value())
    
    //fvOptions(sigma, fi)
);

// fvVectorMatrix& UEqn = tUEqn.ref();

//fiEqn.relax();

//fvOptions.constrain(fiEqn);
Info<<"cos"<<Foam::cos(2*3.14*runTime.value()) << nl <<endl;

fiEqn.solve();

